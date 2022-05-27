/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Module.cpp
** Description: [CHANGE]
*/

#include "JSNP/jsnp.hpp"

#include "OpenGLModule.hpp"
#include "resources/OpenResources.hpp"
#include "utils/Speech.hpp"
#include "exception/Error.hpp"
#include "managers/Managers.hpp"

#include <iostream>
#include <algorithm>
#include <ranges>
#include <execution>
#include <thread>

sw::Input_buffer event_buffer;

SW_GRAPH_MODULE_EXPORT char current_key_flags[sw::Keyboard::LAST];
SW_GRAPH_MODULE_EXPORT char previous_key_flags[sw::Keyboard::LAST];

SW_GRAPH_MODULE_EXPORT char current_mouse_flags[sw::MouseBtn::Button_last];
SW_GRAPH_MODULE_EXPORT char previous_mouse_flags[sw::MouseBtn::Button_last];

SW_GRAPH_MODULE_EXPORT sw::SceneManager sw::OpenGLModule::m_sceneManager = {};
SW_GRAPH_MODULE_EXPORT sw::EventManager sw::OpenGLModule::m_eventManager = {};
SW_GRAPH_MODULE_EXPORT sw::Chrono sw::OpenGLModule::m_chrono{sw::Chrono::Wait};
SW_GRAPH_MODULE_EXPORT sw::Chrono sw::OpenGLModule::m_chronoWindow(sw::Chrono::Wait);
SW_GRAPH_MODULE_EXPORT bool sw::OpenGLModule::m_isLoad(false);
SW_GRAPH_MODULE_EXPORT double sw::OpenGLModule::m_frameRate(1.0/60.0);
SW_GRAPH_MODULE_EXPORT GLFWwindow* sw::OpenGLModule::m_window(nullptr);
SW_GRAPH_MODULE_EXPORT ALCdevice* sw::OpenGLModule::m_audioDevice(nullptr);
SW_GRAPH_MODULE_EXPORT ALCcontext* sw::OpenGLModule::m_audioContext(nullptr);
SW_GRAPH_MODULE_EXPORT std::vector<std::string> sw::OpenGLModule::m_devices;

sw::OpenGLModule::OpenGLModule()
= default;

void sw::OpenGLModule::displayAudioDevice()
{
    m_devices.clear();
    const ALCchar* deviceList = alcGetString(nullptr, ALC_DEVICE_SPECIFIER);

    if (!deviceList)
        return;
    while (strlen(deviceList) > 0) {
        m_devices.emplace_back(deviceList);
        deviceList += strlen(deviceList) + 1;
    }
    for (auto& str : m_devices)
        std::cout << str << std::endl;
}

void sw::OpenGLModule::load()
{
    sw::Speech::flush();
    if (!glfwInit())
        throw sw::Error("Cannot initialize GLFW", "");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

    GLFWmonitor* glfwMonitor = glfwGetPrimaryMonitor();

    #if WINDOW_FULLSCREEN_WINDOWED == 1
    const GLFWvidmode* mode = glfwGetVideoMode(glfwMonitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    m_window = glfwCreateWindow(mode->width, mode->height, "Title 1",  glfwMonitor, nullptr);
    #elif WINDOW_FULLSCREEN == 1
    m_window = glfwCreateWindow(1920, 1080, "Title", glfwMonitor, nullptr);
    #else
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_window = glfwCreateWindow(1920, 1080, "Title", nullptr, nullptr);
    #endif
    if (!m_window)
        throw sw::Error("Failed to create window", "");
    glfwMakeContextCurrent(m_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw sw::Error("Failed to initialize GLAD", "");

    m_audioDevice = alcOpenDevice(nullptr);
    if (!m_audioDevice)
        sw::Speech::Warning("Audio device cannot be initialized!");
    m_audioContext = alcCreateContext(m_audioDevice, nullptr);
    if (!m_audioContext)
        sw::Speech::Warning("Audio Context cannot be initialized!");
    if (!alcMakeContextCurrent(m_audioContext))
        sw::Speech::Warning("Audio Context cannot be set!");

    sw::Speech::flush();

    glViewport(0, 0, 1920, 1080);
    loadResourcesFile("resources/textures.json");
    setUpCallBack();
    m_chrono.start();
    m_isLoad = true;
    sw::Speech::flush();
}

void sw::OpenGLModule::update()
{
    for (auto& [_, camera] : m_sceneManager.getActiveScene().m_cameraManager.value().m_components) {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_sceneManager.getActiveScene().update();
        for (int i = 0; i < sw::Keyboard::LAST; ++i)
            previous_key_flags[i] = current_key_flags[i];
        for (int i = 0; i < sw::MouseBtn::Button_last; ++i)
            previous_mouse_flags[i] = current_mouse_flags[i];
        event_buffer.clear();
        m_chrono.tour();

        if (camera->isDefaultRender())
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glfwSwapBuffers(m_window);
        glfwPollEvents();
        if (m_frameRate != 0.0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>((m_frameRate - m_chronoWindow.getTotalTime()) * 1000)));
            m_chronoWindow.stop();
            m_chronoWindow.start();
        }
        sceneManager().checkForNewScene();
        sw::Speech::flush();
    }

}

sw::SceneManager& sw::OpenGLModule::sceneManager()
{
    return (m_sceneManager);
}

sw::EventManager& sw::OpenGLModule::eventManager()
{
    return (m_eventManager);
}

void sw::OpenGLModule::unload()
{
    glfwTerminate();
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(m_audioContext);
    alcCloseDevice(m_audioDevice);
    m_isLoad = false;
}

bool sw::OpenGLModule::isLoad() const
{
    return (m_isLoad);
}

bool sw::OpenGLModule::isOk()
{
    return (!glfwWindowShouldClose(m_window));
}

std::shared_ptr<sw::AResources> sw::OpenGLModule::createResourceInstance()
{
    return (std::make_shared<sw::OpenResources>());
}

void sw::OpenGLModule::setUpCallBack()
{
    glfwSetFramebufferSizeCallback(m_window, resizeCallBack);
    glfwSetKeyCallback(m_window, input_callback);
    glfwSetMouseButtonCallback(m_window, mouse_button_callback);
    glfwSetScrollCallback(m_window, scroll_callback);
    glfwSetCursorPosCallback(m_window, position_callback);
}

void sw::OpenGLModule::input_callback(GLFWwindow*, int key, int, int action, int)
{
    if (key == -1)
        return;
    if (action == GLFW_RELEASE)
        current_key_flags[key] = 0;
    else
        current_key_flags[key] = 1;
}

void sw::OpenGLModule::mouse_button_callback(GLFWwindow*, int button, int action, int)
{
    current_mouse_flags[button] = action;
}

void sw::OpenGLModule::position_callback(GLFWwindow*, double xpos, double ypos)
{
    std::pair<int,int> kys{};
    std::pair<double,double> ipt{xpos,ypos};
    sw::Type tpe = sw::Position;

    event_buffer.push(tpe, kys, ipt);
}

void sw::OpenGLModule::scroll_callback(GLFWwindow*, double x, double y)
{
    std::pair<int,int> kys{};
    std::pair<double,double> ipt{x,y};
    sw::Type tpe = sw::Scroll;

    event_buffer.push(tpe, kys, ipt);
}

void sw::OpenGLModule::resizeCallBack(GLFWwindow *window, int width, int height)
{
    width = (width > 1920 ? 1920 : width);
    height = (height > 1080 ? 1080 : height);
    glViewport(0, 0, width, height);
}

std::string sw::OpenGLModule::type() const
{
    return (std::string{"OpenGLModule"});
}

void sw::OpenGLModule::setFrameRateLimit(unsigned int frameRate)
{
    m_frameRate = 1.0 / static_cast<double>(frameRate);
}

bool sw::isKeyPressed(const int& kys)
{
    if ((previous_key_flags[kys] == 0) && (current_key_flags[kys] == 1))
        return true;
    return false;
}

bool sw::isKeyDown(const int &kys)
{
    if (current_key_flags[kys] == 1)
        return true;
    return false;
}

bool sw::isKeyReleased(const int &kys)
{
    if ((previous_key_flags[kys] == 1) && (current_key_flags[kys] == 0))
        return true;
    return false;
}

bool sw::isKeyUp(const int &kys)
{
    if (current_key_flags[kys] == 0)
        return true;
    return false;
}

bool sw::isMouseButtonPressed(const int &btn)
{
    if ((previous_mouse_flags[btn] == 0) && (current_mouse_flags[btn] == 1))
        return true;
    return false;
}

bool sw::isMouseButtonDown(const int &btn)
{
    if (current_mouse_flags[btn] == 1)
        return true;
    return false;
}

bool sw::isMouseButtonReleased(const int &btn)
{
    if ((previous_mouse_flags[btn] == 1) && (current_mouse_flags[btn] == 0))
        return true;
    return false;
}

bool sw::isMouseButtonUp(const int &btn)
{
    return !sw::isMouseButtonDown(btn);
}

bool sw::mouseMoved()
{
    const auto &tmp = event_buffer.get();

    for (size_t i = 0; i < event_buffer.getIdx(); ++i)
    {
        if (tmp[i].m_t == sw::Position)
            return true;
    }
    return false;
}

bool sw::mouseScrolled(const std::pair<double, double> &evt)
{
    const auto& tmp = event_buffer.get();

    for (size_t i = 0; i < event_buffer.getIdx(); ++i)
    {
        if (tmp[i].m_t == sw::Scroll && tmp[i].m_os == evt)
            return true;
    }
    return false;
}

static void addResourcesOnReqScene(jsnp::Token& token)
{
    auto& key = token.first;
    auto& obj = token.second.value<jsnp::Object>();
    auto& path = obj["Path"].second.value<std::string>();
    auto& type = obj["Type"].second.value<std::string>();

    if (!std::ifstream(path))
        sw::Speech::Warning("sw::AddResourcesOnScene - Tag Path <" + path + "> is incorrect!", "3710");


    for (auto value : obj["Scene"].second.value<jsnp::Array>()) {
        auto yolo = value.value<std::string>();

        sw::Scene& currentScene = sw::OpenGLModule::m_sceneManager.getScene(yolo);
        currentScene.resources.addNeededResource(key, path, type);
    }
}

void sw::OpenGLModule::loadResourcesFile(const std::string &path)
{
    std::ifstream in(path);
    jsnp::Data data(path);

    if (!in)
        sw::Speech::Error("sw::LoadResourcesFile - Unable to open file <" + path + ">", "4710");
    else
        for (auto token : data()) {
            auto& obj = token.second.value<jsnp::Object>();
            if (obj["Scene"].second.value<jsnp::Array>().size() == 0) {
                sw::Speech::Warning("sw::LoadResourcesFile - tag Scene not found!", "3710");
                continue;
            }
            addResourcesOnReqScene(token);
        }
}
