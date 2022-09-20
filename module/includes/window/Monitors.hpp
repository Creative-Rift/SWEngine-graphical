/*
** EPITECH PROJECT, 2022
** Monitors.hpp
** File description:
** Monitors.hpp
*/

#ifndef SHIPWRECK_ENGINE_MONITORS_HPP
#define SHIPWRECK_ENGINE_MONITORS_HPP

#include "GLFW/glfw3.h"

#include "Vector2.hpp"

namespace sw::Monitors
{
    int GetCurrentMonitorIndex();
    GLFWmonitor *GetMonitor(int index);
    int GetMonitorsCount();
    sw::Vector2i GetMonitorPos(int index);
    std::string GetMonitorName(int index);
    sw::Vector2i GetMonitorPhysicalSize(int index);
    int GetMonitorFreshRate(int index);
}

#endif //SHIPWRECK_ENGINE_MONITORS_HPP
