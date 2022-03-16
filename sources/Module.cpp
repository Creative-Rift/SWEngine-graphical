/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Module.cpp
** Description: [CHANGE]
*/

#include "SW/utils/Speech.hpp"
#include "JSNP/jsnp.hpp"

#include "OpenGLModule.hpp"
#include "OpenGLModule_Config.hpp"
#include "resources/OpenResources.hpp"
#include "utils/Buffer.hpp"

#include <iostream>
#include <map>
#include <algorithm>
#include <ranges>
#include <execution>

sw::Input_buffer event_buffer;

SW_GRAPH_MODULE_EXPORT char current_key_flags[sw::Keyboard::LAST];
SW_GRAPH_MODULE_EXPORT char previous_key_flags[sw::Keyboard::LAST];

SW_GRAPH_MODULE_EXPORT char current_mouse_flags[sw::MouseBtn::Button_last];
SW_GRAPH_MODULE_EXPORT char previous_mouse_flags[sw::MouseBtn::Button_last];

/*
SW_GRAPH_MODULE_EXPORT std::map<int, int> m_key_flags = {
        {sw::MouseBtn::Button_1, sw::Actions::A_UP},
        {sw::MouseBtn::Button_2, sw::Actions::A_UP},
        {sw::MouseBtn::Button_3, sw::Actions::A_UP},
        {sw::MouseBtn::Button_4, sw::Actions::A_UP},
        {sw::MouseBtn::Button_5, sw::Actions::A_UP},
        {sw::MouseBtn::Button_6, sw::Actions::A_UP},
        {sw::MouseBtn::Button_7, sw::Actions::A_UP},
        {sw::MouseBtn::Button_8, sw::Actions::A_UP},
        {sw::MouseBtn::Button_last, sw::Actions::A_UP},
        {sw::MouseBtn::Button_left, sw::Actions::A_UP},
        {sw::MouseBtn::Button_right, sw::Actions::A_UP},
        {sw::Keyboard::UNKNOWN, sw::Actions::A_UP},
        {sw::Keyboard::A, sw::Actions::A_UP},
        {sw::Keyboard::B, sw::Actions::A_UP},
        {sw::Keyboard::C, sw::Actions::A_UP},
        {sw::Keyboard::D, sw::Actions::A_UP},
        {sw::Keyboard::E, sw::Actions::A_UP},
        {sw::Keyboard::F, sw::Actions::A_UP},
        {sw::Keyboard::G, sw::Actions::A_UP},
        {sw::Keyboard::H, sw::Actions::A_UP},
        {sw::Keyboard::I, sw::Actions::A_UP},
        {sw::Keyboard::J, sw::Actions::A_UP},
        {sw::Keyboard::K, sw::Actions::A_UP},
        {sw::Keyboard::L, sw::Actions::A_UP},
        {sw::Keyboard::M, sw::Actions::A_UP},
        {sw::Keyboard::N, sw::Actions::A_UP},
        {sw::Keyboard::O, sw::Actions::A_UP},
        {sw::Keyboard::P, sw::Actions::A_UP},
        {sw::Keyboard::Q, sw::Actions::A_UP},
        {sw::Keyboard::R, sw::Actions::A_UP},
        {sw::Keyboard::S, sw::Actions::A_UP},
        {sw::Keyboard::T, sw::Actions::A_UP},
        {sw::Keyboard::U, sw::Actions::A_UP},
        {sw::Keyboard::V, sw::Actions::A_UP},
        {sw::Keyboard::X, sw::Actions::A_UP},
        {sw::Keyboard::Y, sw::Actions::A_UP},
        {sw::Keyboard::Z, sw::Actions::A_UP},
        {sw::Keyboard::SPACE, sw::Actions::A_UP},
        {sw::Keyboard::ADD, sw::Actions::A_UP},
        {sw::Keyboard::APOSTROPHE, sw::Actions::A_UP},
        {sw::Keyboard::BACKSLASH, sw::Actions::A_UP},
        {sw::Keyboard::BACKSPACE, sw::Actions::A_UP},
        {sw::Keyboard::CAPS_LOCK, sw::Actions::A_UP},
        {sw::Keyboard::COMMA, sw::Actions::A_UP},
        {sw::Keyboard::DECIMAL, sw::Actions::A_UP},
        {sw::Keyboard::DELETE, sw::Actions::A_UP},
        {sw::Keyboard::DIVIDE, sw::Actions::A_UP},
        {sw::Keyboard::DOWN, sw::Actions::A_UP},
        {sw::Keyboard::DOWN, sw::Actions::A_UP},
        {sw::Keyboard::PAGE_DOWN, sw::Actions::A_UP},
        {sw::Keyboard::EIGHT, sw::Actions::A_UP},
        {sw::Keyboard::END, sw::Actions::A_UP},
        {sw::Keyboard::ENTER, sw::Actions::A_UP},
        {sw::Keyboard::EQUAL, sw::Actions::A_UP},
        {sw::Keyboard::ESCAPE, sw::Actions::A_UP},
        {sw::Keyboard::KP_ENTER, sw::Actions::A_UP},
        {sw::Keyboard::KP_EQUAL, sw::Actions::A_UP},
        {sw::Keyboard::F1, sw::Actions::A_UP},
        {sw::Keyboard::F2, sw::Actions::A_UP},
        {sw::Keyboard::F3, sw::Actions::A_UP},
        {sw::Keyboard::F4, sw::Actions::A_UP},
        {sw::Keyboard::F5, sw::Actions::A_UP},
        {sw::Keyboard::F6, sw::Actions::A_UP},
        {sw::Keyboard::F7, sw::Actions::A_UP},
        {sw::Keyboard::F8, sw::Actions::A_UP},
        {sw::Keyboard::F9, sw::Actions::A_UP},
        {sw::Keyboard::F10, sw::Actions::A_UP},
        {sw::Keyboard::F11, sw::Actions::A_UP},
        {sw::Keyboard::F12, sw::Actions::A_UP},
        {sw::Keyboard::F13, sw::Actions::A_UP},
        {sw::Keyboard::F14, sw::Actions::A_UP},
        {sw::Keyboard::F15, sw::Actions::A_UP},
        {sw::Keyboard::F16, sw::Actions::A_UP},
        {sw::Keyboard::F17, sw::Actions::A_UP},
        {sw::Keyboard::F18, sw::Actions::A_UP},
        {sw::Keyboard::F19, sw::Actions::A_UP},
        {sw::Keyboard::F20, sw::Actions::A_UP},
        {sw::Keyboard::F21, sw::Actions::A_UP},
        {sw::Keyboard::F22, sw::Actions::A_UP},
        {sw::Keyboard::F23, sw::Actions::A_UP},
        {sw::Keyboard::F24, sw::Actions::A_UP},
        {sw::Keyboard::F25, sw::Actions::A_UP},
        {sw::Keyboard::FIVE, sw::Actions::A_UP},
        {sw::Keyboard::FOUR, sw::Actions::A_UP},
        {sw::Keyboard::G, sw::Actions::A_UP},
        {sw::Keyboard::GRAVE, sw::Actions::A_UP},
        {sw::Keyboard::H, sw::Actions::A_UP},
        {sw::Keyboard::HOME, sw::Actions::A_UP},
        {sw::Keyboard::I, sw::Actions::A_UP},
        {sw::Keyboard::INSERT, sw::Actions::A_UP},
        {sw::Keyboard::J, sw::Actions::A_UP},
        {sw::Keyboard::K, sw::Actions::A_UP},
        {sw::Keyboard::KP_0, sw::Actions::A_UP},
        {sw::Keyboard::KP_1, sw::Actions::A_UP},
        {sw::Keyboard::KP_2, sw::Actions::A_UP},
        {sw::Keyboard::KP_3, sw::Actions::A_UP},
        {sw::Keyboard::KP_4, sw::Actions::A_UP},
        {sw::Keyboard::KP_5, sw::Actions::A_UP},
        {sw::Keyboard::KP_6, sw::Actions::A_UP},
        {sw::Keyboard::KP_7, sw::Actions::A_UP},
        {sw::Keyboard::KP_8, sw::Actions::A_UP},
        {sw::Keyboard::KP_9, sw::Actions::A_UP},
        {sw::Keyboard::L, sw::Actions::A_UP},
        {sw::Keyboard::LALT, sw::Actions::A_UP},
        {sw::Keyboard::LAST, sw::Actions::A_UP},
        {sw::Keyboard::LBRACKET, sw::Actions::A_UP},
        {sw::Keyboard::LCONTROL, sw::Actions::A_UP},
        {sw::Keyboard::LEFT, sw::Actions::A_UP},
        {sw::Keyboard::LSHIFT, sw::Actions::A_UP},
        {sw::Keyboard::LSUPER, sw::Actions::A_UP},
        {sw::Keyboard::M, sw::Actions::A_UP},
        {sw::Keyboard::MENU, sw::Actions::A_UP},
        {sw::Keyboard::MINUS, sw::Actions::A_UP},
        {sw::Keyboard::MULTIPLY, sw::Actions::A_UP},
        {sw::Keyboard::N, sw::Actions::A_UP},
        {sw::Keyboard::NINE, sw::Actions::A_UP},
        {sw::Keyboard::NUM_LOCK, sw::Actions::A_UP},
        {sw::Keyboard::O, sw::Actions::A_UP},
        {sw::Keyboard::ONE, sw::Actions::A_UP},
        {sw::Keyboard::PAGE_UP, sw::Actions::A_UP},
        {sw::Keyboard::P, sw::Actions::A_UP},
        {sw::Keyboard::PAUSE, sw::Actions::A_UP},
        {sw::Keyboard::PERIOD, sw::Actions::A_UP},
        {sw::Keyboard::PRINT, sw::Actions::A_UP},
        {sw::Keyboard::Q, sw::Actions::A_UP},
        {sw::Keyboard::R, sw::Actions::A_UP},
        {sw::Keyboard::RALT, sw::Actions::A_UP},
        {sw::Keyboard::RBRACKET, sw::Actions::A_UP},
        {sw::Keyboard::RCONTROL, sw::Actions::A_UP},
        {sw::Keyboard::RIGHT, sw::Actions::A_UP},
        {sw::Keyboard::RSHIFT, sw::Actions::A_UP},
        {sw::Keyboard::RSUPER, sw::Actions::A_UP},
        {sw::Keyboard::S, sw::Actions::A_UP},
        {sw::Keyboard::SCROLL_LOCK, sw::Actions::A_UP},
        {sw::Keyboard::SEMICOLON, sw::Actions::A_UP},
        {sw::Keyboard::SEVEN, sw::Actions::A_UP},
        {sw::Keyboard::SIX, sw::Actions::A_UP},
        {sw::Keyboard::SLASH, sw::Actions::A_UP},
        {sw::Keyboard::SPACE, sw::Actions::A_UP},
        {sw::Keyboard::SUBSTRACT, sw::Actions::A_UP},
        {sw::Keyboard::T, sw::Actions::A_UP},
        {sw::Keyboard::TAB, sw::Actions::A_UP},
        {sw::Keyboard::THREE, sw::Actions::A_UP},
        {sw::Keyboard::TWO, sw::Actions::A_UP},
        {sw::Keyboard::U, sw::Actions::A_UP},
        {sw::Keyboard::UP, sw::Actions::A_UP},
        {sw::Keyboard::V, sw::Actions::A_UP},
        {sw::Keyboard::W, sw::Actions::A_UP},
        {sw::Keyboard::WORLD_1, sw::Actions::A_UP},
        {sw::Keyboard::WORLD_2, sw::Actions::A_UP},
        {sw::Keyboard::X, sw::Actions::A_UP},
        {sw::Keyboard::Y, sw::Actions::A_UP},
        {sw::Keyboard::Z, sw::Actions::A_UP},
        {sw::Keyboard::ZERO, sw::Actions::A_UP}
    };
*/

sw::OpenGLModule::OpenGLModule() :
sw::AModule(),
m_window(nullptr),
m_chrono(sw::Chrono::Wait)
{}

void sw::OpenGLModule::initialize()
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

    glViewport(0, 0, 1920, 1080);
    loadResourcesFile("resources/textures.json");
    setUpCallBack();
    m_chrono.start();
}

void sw::OpenGLModule::update()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glfwSwapBuffers(m_window);
    glClear(GL_COLOR_BUFFER_BIT);

    sw::Engine::activeScene().update();
    auto toUp = [](auto &i)
    {
        if (i.second != sw::Actions::A_UP)
            i.second = sw::Actions::A_UP;
    };
    for (int i = 0; i < sw::Keyboard::LAST; ++i)
        previous_key_flags[i] = current_key_flags[i];
    for (int i = 0; i < sw::MouseBtn::Button_last; ++i)
        previous_mouse_flags[i] = current_mouse_flags[i];
    event_buffer.clear();
    m_chrono.tour();

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void sw::OpenGLModule::terminate()
{
    glfwTerminate();
}

bool sw::OpenGLModule::isOk()
{
    return (!glfwWindowShouldClose(m_window));
}

std::unique_ptr<sw::AResources> sw::OpenGLModule::createResourceInstance()
{
    return (std::make_unique<sw::OpenResources>());
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

        sw::AScene& currentScene = sw::Engine::getScene(yolo);
        currentScene.resources()->addNeededResource(key, path, type);
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
