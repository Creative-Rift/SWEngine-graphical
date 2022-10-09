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

SW_GRAPH_MODULE_EXPORT bool sw::Window::m_ready(false);
SW_GRAPH_MODULE_EXPORT GLFWwindow* sw::Window::m_window(nullptr);
SW_GRAPH_MODULE_EXPORT bool sw::Window::m_fullScreen(false);
SW_GRAPH_MODULE_EXPORT sw::Vector2i sw::Window::m_size({1920, 1080});
SW_GRAPH_MODULE_EXPORT sw::Vector2i sw::Window::m_maxSize({1920, 1080});
SW_GRAPH_MODULE_EXPORT sw::Vector2i sw::Window::m_position({0, 0});
SW_GRAPH_MODULE_EXPORT std::string sw::Window::m_title("ShipWreck Engine");
SW_GRAPH_MODULE_EXPORT unsigned int sw::Window::m_flags(0);
SW_GRAPH_MODULE_EXPORT bool sw::Window::m_cursorHidden(true);

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
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    setUpCallBack();
    m_ready = true;
    return (m_window);
}

GLFWwindow *sw::Window::GetWindow()
{
    return (m_window);
}

void sw::Window::ToggleFullScreen()
{
    if (!m_fullScreen) {
        glfwGetWindowPos(m_window, &m_position.x, &m_position.y);
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
        glfwSetWindowPos(m_window, m_position.x, m_position.y);
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

void sw::Window::SetWindowPos(int x, int y)
{
    m_size.x = x;
    m_size.y = y;
    glfwSetWindowPos(m_window, x, y);
}

void sw::Window::SetWindowPos(sw::Vector2i pos)
{
    SetWindowPos(pos.x, pos.y);
}

void sw::Window::SetMinSize(int with, int height)
{
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowSizeLimits(m_window, with, height, mode->width, mode->height);
}

void sw::Window::SetMinSize(sw::Vector2i size)
{
    SetMinSize(size.x, size.y);
}

void sw::Window::SetMaxSize(int with, int height)
{
    m_maxSize.x = with;
    m_maxSize.y = height;
}

void sw::Window::SetMaxSize(sw::Vector2i size)
{
    SetMaxSize(size.x, size.y);
}

void sw::Window::SetSize(int with, int height)
{
    glfwSetWindowSize(m_window, with, height);
}

void sw::Window::SetSize(sw::Vector2i size)
{
    SetMinSize(size.x, size.y);
}

void sw::Window::SetVisibleCursor(bool visible)
{
    m_cursorHidden = visible;
    glfwSetInputMode(m_window, GLFW_CURSOR, (visible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN));
}

void sw::Window::SetMonitor(int index)
{
    int count = 0;
    GLFWmonitor **monitors = glfwGetMonitors(&count);

    if (count > index)
        throw std::out_of_range("Monitor not found");
    const GLFWvidmode *mode = glfwGetVideoMode(monitors[index]);
    glfwSetWindowMonitor(m_window, monitors[index], 0, 0, mode->width, mode->height, mode->refreshRate);
}

void sw::Window::SetClipboardText(std::string text)
{
    glfwSetClipboardString(m_window, text.c_str());
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

sw::Vector2i sw::Window::GetPosition()
{
    return (m_position);
}

std::string sw::Window::GetClipBoardText()
{
    return (std::string(glfwGetClipboardString(m_window)));
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

bool sw::Window::IsCursorVisible()
{
    return (m_cursorHidden);
}