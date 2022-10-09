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
#include "Window.hpp"

#include <iostream>
#include <algorithm>
#include <ranges>
#include <execution>
#include <thread>

SW_GRAPH_MODULE_EXPORT sw::SceneManager sw::OpenGLModule::m_sceneManager = {};
SW_GRAPH_MODULE_EXPORT sw::EventManager sw::OpenGLModule::m_eventManager = {};
SW_GRAPH_MODULE_EXPORT sw::Chrono sw::OpenGLModule::m_chrono{sw::Chrono::Wait};
SW_GRAPH_MODULE_EXPORT sw::Chrono sw::OpenGLModule::m_chronoWindow(sw::Chrono::Wait);
SW_GRAPH_MODULE_EXPORT bool sw::OpenGLModule::m_isLoad(false);
SW_GRAPH_MODULE_EXPORT double sw::OpenGLModule::m_frameRate(1.0/60.0);
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

    sw::Window::CreateWindow();

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
    glEnable(GL_DEPTH_TEST);
    loadResourcesFile("resources/textures.json");
    m_chrono.start();
    m_isLoad = true;
    sw::Window::Maximize();
    sw::Speech::flush();
}

void sw::OpenGLModule::update()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_sceneManager.getActiveScene().update();

    m_chrono.tour();
    sw::Window::UpdateWindow();
    glfwPollEvents();

    sw::Speech::flush();
    if (m_frameRate != 0.0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>((m_frameRate - m_chronoWindow.getTotalTime()) * 1000)));
        m_chronoWindow.stop();
        m_chronoWindow.start();
    }
    sceneManager().checkForNewScene();
}

sw::SceneManager& sw::OpenGLModule::sceneManager()
{
    return (m_sceneManager);
}

sw::EventManager& sw::OpenGLModule::eventManager()
{
    return (m_eventManager);
}

sw::Chrono &sw::OpenGLModule::chrono()
{
    return (m_chrono);
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

bool sw::OpenGLModule::isRunning()
{
    return (sw::Window::IsOpen());
}

std::shared_ptr<sw::AResources> sw::OpenGLModule::createResourceInstance()
{
    return (std::make_shared<sw::OpenResources>());
}

std::string sw::OpenGLModule::type() const
{
    return (std::string{"OpenGLModule"});
}

void sw::OpenGLModule::setFrameRateLimit(unsigned int frameRate)
{
    m_frameRate = 1.0 / static_cast<double>(frameRate);
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

void sw::OpenGLModule::CheckOpenOperation()
{
    int result = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if(result != GL_FRAMEBUFFER_COMPLETE)
        throw sw::Error("Error in OpenGL Operation", std::to_string(result));
}
