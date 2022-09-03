/*
** EPITECH PROJECT, 2022
** Monitors.cpp
** File description:
** Monitors.cpp
*/

#include "Monitors.hpp"
#include "Error.hpp"

int sw::Monitors::GetCurrentMonitorIndex()
{
    int monitorCount;
    GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
    GLFWmonitor* monitor = nullptr;

    if (monitorCount == 1)
        return 0;
    // TODO: Handle more device
    throw sw::Error("The Engine handle one monitor device!", "");
}