/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Window.cpp
** Description: [CHANGE]
*/

#include "Window.hpp"
#include "Monitors.hpp"
#include "utils/Inputs.hpp"
#include "Buffer.hpp"

sw::Input_buffer event_buffer;

SW_GRAPH_MODULE_EXPORT char current_key_flags[sw::Keyboard::LAST];
SW_GRAPH_MODULE_EXPORT char previous_key_flags[sw::Keyboard::LAST];

SW_GRAPH_MODULE_EXPORT char current_mouse_flags[sw::MouseBtn::Button_last];
SW_GRAPH_MODULE_EXPORT char previous_mouse_flags[sw::MouseBtn::Button_last];

SW_GRAPH_MODULE_EXPORT bool sw::Window::m_ready(false);
SW_GRAPH_MODULE_EXPORT GLFWwindow* sw::Window::m_window(nullptr);
SW_GRAPH_MODULE_EXPORT bool sw::Window::m_fullScreen(false);
SW_GRAPH_MODULE_EXPORT sw::Vector2i sw::Window::m_size({1920, 1080});
SW_GRAPH_MODULE_EXPORT std::string sw::Window::m_title("ShipWreck Engine");
SW_GRAPH_MODULE_EXPORT unsigned int sw::Window::m_flags(0);

sw::Window::Window()
= default;

sw::Window::~Window()
= default;

GLFWwindow *sw::Window::CreateWindow()
{
    if (!glfwInit())
        throw sw::Error("Cannot initialize GLFW", "");

    GLFWmonitor* glfwMonitor = glfwGetPrimaryMonitor();

    if (!glfwMonitor)
        throw sw::Error("Unable to find a Monitor", "");

    glfwDefaultWindowHints();
    // Add more flags

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_window = glfwCreateWindow(m_size.x, m_size.y, m_title.c_str(), nullptr, nullptr);

    if (!m_window) {
        glfwTerminate();
        throw sw::Error("Failed to create window", "");
    }
    glfwMakeContextCurrent(m_window);
    setUpCallBack();
    m_ready = true;
    return (m_window);
}

GLFWwindow *sw::Window::GetWindow()
{
    return (m_window);
}

GLFWwindow *sw::Window::UpdateWindow()
{
    for (int i = 0; i < sw::Keyboard::LAST; ++i)
        previous_key_flags[i] = current_key_flags[i];
    for (int i = 0; i < sw::MouseBtn::Button_last; ++i)
        previous_mouse_flags[i] = current_mouse_flags[i];
    event_buffer.clear();
    glfwSwapBuffers(m_window);
    return (m_window);
}

void sw::Window::ToggleFullScreen()
{
    if (!m_fullScreen) {
        // TODO: Save window pos
        int monitorIndex = sw::Monitors::GetCurrentMonitorIndex();
        int monitorCount = 0;
        GLFWmonitor **monitors = glfwGetMonitors(&monitorCount);
        GLFWmonitor *monitor = (monitorIndex < monitorCount) ? monitors[monitorIndex] : nullptr;

        if (!monitors)
        {
            m_fullScreen = false;
            m_flags &= ~sw::WindowFlags::FULLSCREEN_MODE;
            throw sw::Error("No monitor found!", "");
        } else {
            m_fullScreen = true;
            m_flags |= sw::WindowFlags::FULLSCREEN_MODE;
            glfwSetWindowMonitor(m_window, monitor, 0, 0, m_size.x, m_size.y, GLFW_DONT_CARE);
        }
    } else {
        m_fullScreen = false;
        m_flags &= ~sw::WindowFlags::FULLSCREEN_MODE;
        // TODO: put the last position
        glfwSetWindowMonitor(m_window, nullptr, 0, 0, m_size.x, m_size.y, GLFW_DONT_CARE);
    }
}

void sw::Window::Maximize()
{
    if (glfwGetWindowAttrib(m_window, GLFW_RESIZABLE) == GLFW_TRUE)
    {
        glfwMaximizeWindow(m_window);
        m_flags |= sw::WindowFlags::MAXIMIZED;
    }
}

void sw::Window::Minimize()
{
    glfwIconifyWindow(m_window);
    m_flags |= sw::WindowFlags::MINIMIZED;
}

void sw::Window::Restore()
{
    if (glfwGetWindowAttrib(m_window, GLFW_RESIZABLE) == GLFW_TRUE)
    {
        glfwRestoreWindow(m_window);
    }
}

void sw::Window::SetTitle(std::string title)
{
    m_title = title;
    glfwSetWindowTitle(m_window, title.c_str());
}

bool sw::Window::HasFlag(sw::WindowFlags flags)
{
    return (m_flags & flags);
}

sw::Vector2i sw::Window::GetSize()
{
    return (m_size);
}

std::string sw::Window::GetTitle()
{
    return (m_title);
}

bool sw::Window::IsFullScreen()
{
    return (m_fullScreen);
}

bool sw::Window::IsOpen()
{
    return (!glfwWindowShouldClose(m_window));
}

bool sw::Window::IsReady()
{
    return (m_ready);
}

void sw::Window::setUpCallBack()
{
    glfwSetFramebufferSizeCallback(m_window, resizeCallBack);
    glfwSetKeyCallback(m_window, input_callback);
    glfwSetMouseButtonCallback(m_window, mouse_button_callback);
    glfwSetScrollCallback(m_window, scroll_callback);
    glfwSetCursorPosCallback(m_window, position_callback);
}

void sw::Window::input_callback(GLFWwindow*, int key, int, int action, int)
{
    if (key == -1)
        return;
    if (action == GLFW_RELEASE)
        current_key_flags[key] = 0;
    else
        current_key_flags[key] = 1;
}

void sw::Window::mouse_button_callback(GLFWwindow*, int button, int action, int)
{
    current_mouse_flags[button] = action;
}

void sw::Window::position_callback(GLFWwindow*, double xpos, double ypos)
{
    std::pair<int,int> kys{};
    std::pair<double,double> ipt{xpos,ypos};
    sw::Type tpe = sw::Position;

    event_buffer.push(tpe, kys, ipt);
}

void sw::Window::scroll_callback(GLFWwindow*, double x, double y)
{
    std::pair<int,int> kys{};
    std::pair<double,double> ipt{x,y};
    sw::Type tpe = sw::Scroll;

    event_buffer.push(tpe, kys, ipt);
}

void sw::Window::resizeCallBack(GLFWwindow *window, int width, int height)
{
    width = (width > 1920 ? 1920 : width);
    height = (height > 1080 ? 1080 : height);
    glViewport(0, 0, width, height);
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