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
#include "OpenGLModule.hpp"
#include "GameObject.hpp"

void sw::Event::drop()
{
    for (auto& listener : m_listenerList)
        listener->catchEvent();
}

void sw::Event::drop(sw::EventInfo& info)
{
    for (auto& listener : m_listenerList)
        listener->catchEvent(info);
}

void sw::Event::drop(std::set<std::string> targets)
{
    for (auto& listener : m_listenerList)
        if (targets.contains(listener->linkedElement()))
            listener->catchEvent();
}

void sw::Event::drop(const std::string& target)
{
    for (auto& listener : m_listenerList)
        if (listener->linkedElement() == target)
            listener->catchEvent();
}

void sw::Event::drop(sw::EventInfo& info, const std::string& target)
{
    for (auto& listener : m_listenerList)
        if (listener->linkedElement() == target)
            listener->catchEvent(info);
}

void sw::Event::drop(sw::EventInfo& info, std::set<std::string> targets)
{
    for (auto& listener : m_listenerList)
        if (targets.contains(listener->linkedElement()))
            listener->catchEvent(info);
}

void sw::Event::clearListener()
{
    m_listenerList.clear();
}

void sw::Event::unsubscribe(std::string name)
{
    for (auto& listener : m_listenerList) {
        if (listener->linkedElement() == name) {
            m_listenerList.remove(listener);
            break;
        }
    }
    m_listenerListName.remove(name);
}