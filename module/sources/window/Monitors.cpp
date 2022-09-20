/*
** EPITECH PROJECT, 2022
** Monitors.cpp
** File description:
** Monitors.cpp
*/

#include "Window.hpp"
#include "Monitors.hpp"

int sw::Monitors::GetCurrentMonitorIndex()
{
    int monitorCount;
    GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
    GLFWmonitor* monitor = nullptr;

    if (monitorCount == 1)
        return 0;
    if (sw::Window::IsFullScreen()) {
        monitor = glfwGetWindowMonitor(sw::Window::GetWindow());
        for (int i = 0; i < monitorCount; i++)
            if (monitors[i] == monitor)
                return i;
        return 0;
    } else {
        int winX = 0;
        int winY = 0;

        glfwGetWindowPos(sw::Window::GetWindow(), &winX, &winY);
        for (int i = 0; i < monitorCount; i++)
        {
            int mx = 0;
            int my = 0;
            int width = 0;
            int height = 0;

            monitor = monitors[i];
            glfwGetMonitorWorkarea(monitor, &mx, &my, &width, &height);
            if (winX >= mx && winX <= (mx + width) && winY >= my && winY <= (my + height))
                return i;
        }
    }
    return (0);
}

GLFWmonitor *sw::Monitors::GetMonitor(int index)
{
    int count = 0;
    GLFWmonitor **monitors = glfwGetMonitors(&count);

    if (index > count)
        throw std::out_of_range("Monitor index doesn't exist");
    return (monitors[index]);

}

int sw::Monitors::GetMonitorsCount()
{
    int count = 0;
    glfwGetMonitors(&count);

    return (count);
}

sw::Vector2i sw::Monitors::GetMonitorPos(int index)
{
    int height;
    int width;

    glfwGetMonitorPos(GetMonitor(index), &width, &height);
    return (sw::Vector2i(width, height));
}

std::string sw::Monitors::GetMonitorName(int index)
{
    return (std::string(glfwGetMonitorName(GetMonitor(index))));
}

sw::Vector2i sw::Monitors::GetMonitorPhysicalSize(int index)
{
    int height;
    int width;

    glfwGetMonitorPhysicalSize(GetMonitor(index), &width, &height);
    return (sw::Vector2i(width, height));
}

int sw::Monitors::GetMonitorFreshRate(int index)
{
    const GLFWvidmode *videoMode = glfwGetVideoMode(GetMonitor(index));

    return (videoMode->refreshRate);
}