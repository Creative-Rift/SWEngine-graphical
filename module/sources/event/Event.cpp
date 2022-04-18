/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Event.cpp
 *
 * Description:
 * Event functions implementation
 */

#include "Event.hpp"
#include "EventListener.hpp"

void sw::Event::drop()
{
    for (auto& listerner : m_listenerList)
        listerner->catchEvent();
}

void sw::Event::drop(sw::EventInfo& info)
{
    for (auto& listerner : m_listenerList)
        listerner->catchEvent(info);
}

void sw::Event::drop(std::set<std::string> targets)
{
    for (auto& listerner : m_listenerList)
        if (targets.contains(listerner->linkedElement()))
            listerner->catchEvent();
}

void sw::Event::drop(const std::string& target)
{
    for (auto& listerner : m_listenerList)
        if (listerner->linkedElement() == target)
            listerner->catchEvent();
}

void sw::Event::drop(sw::EventInfo& info, const std::string& target)
{
    for (auto& listerner : m_listenerList)
        if (listerner->linkedElement() == target)
            listerner->catchEvent(info);
}

void sw::Event::drop(sw::EventInfo& info, std::set<std::string> targets)
{
    for (auto& listerner : m_listenerList)
        if (targets.contains(listerner->linkedElement()))
            listerner->catchEvent(info);
}