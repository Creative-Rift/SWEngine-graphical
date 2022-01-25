/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Module.cpp
** Description: [CHANGE]
*/

#include "SW/utils/Speech.hpp"

#include "OpenGLModule.hpp"
#include "resources/OpenResources.hpp"
#include "utils/Buffer.hpp"

#include <iostream>

sw::Input_buffer event_buffer;

sw::OpenGLModule::OpenGLModule() :
sw::AModule(),
m_window(nullptr)
{}

void sw::OpenGLModule::initialize()
{
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

    glViewport(0, 0, 800, 600);
    setUpCallBack();
}

void sw::OpenGLModule::update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
    if (sw::mouseMoved())
        std::cout << "mouse moved" << std::endl;
    event_buffer.clear();
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
    std::pair<int,int> input = {key, action};
    std::pair<double,double> pos{};
    sw::Type tpe = sw::Keyboard;

    event_buffer.push(tpe, input, pos);
}

void sw::OpenGLModule::mouse_button_callback(GLFWwindow*, int button, int action, int)
{
    std::pair<int,int> ipt = {button, action};
    std::pair<double,double> pos{};
    sw::Type tpe = sw::Mouse;

    event_buffer.push(tpe, ipt, pos);
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

bool sw::isKeyPressed(sw::Type& evt, const int& kys)
{
    return false;
}

bool sw::isKeyDown(sw::Type &, const int &)
{
    return false;
}

bool sw::isKeyReleased(sw::Type &, const int &)
{
    return false;
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
