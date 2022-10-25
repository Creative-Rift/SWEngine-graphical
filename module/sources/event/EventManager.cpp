/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * EventManager.cpp
 *
 * Description:
 * EventManager functions implementation
 */

#include "EventManager.hpp"
#include "EventInfo.hpp"
#include "Event.hpp"
#include "Speech.hpp"

sw::Event& sw::EventManager::create(const std::string& eventName)
{
    if (m_eventList.contains(eventName))
        sw::Speech::Warning(sw::Log::warningA2B(FUNCTION, "sw::Engine::activeSceneName()", eventName));
    return (*(m_eventList.try_emplace(eventName, std::make_shared<Event>()).first->second));
}

sw::Event& sw::EventManager::get(const std::string& eventName) const
try
{
    return (*m_eventList.at(eventName));
}
catch (std::out_of_range&)
{
    throw sw::Error(sw::Log::errorA1B(FUNCTION, "sw::Engine::activeSceneName()", eventName));
}

sw::Event& sw::EventManager::operator[](const std::string& eventName) const
try
{
    return (*m_eventList.at(eventName));
}
catch (std::out_of_range&)
{
    throw sw::Error(sw::Log::errorA1B(FUNCTION, "sw::Engine::activeSceneName()", eventName));
}

void sw::EventManager::drop(const std::string& eventName)
try
{
    m_eventList.at(eventName)->drop();
}
catch (std::out_of_range&)
{
    throw sw::Error(sw::Log::errorA1B(FUNCTION, "sw::Engine::activeSceneName()", eventName));
}

void sw::EventManager::drop(const std::string& eventName, sw::EventInfo& info)
try
{
    m_eventList.at(eventName)->drop(info);
}
catch (std::out_of_range&)
{
    throw sw::Error(sw::Log::errorA1B(FUNCTION, "sw::Engine::activeSceneName()", eventName));
}

void sw::EventManager::drop(const std::string& eventName, std::set<std::string> targets)
try
{
    m_eventList.at(eventName)->drop(targets);
}
catch (std::out_of_range&)
{
    throw sw::Error(sw::Log::errorA1B(FUNCTION, "sw::Engine::activeSceneName()", eventName));
}

void sw::EventManager::drop(const std::string& eventName, const std::string& target)
try
{
    m_eventList.at(eventName)->drop(target);
}
catch (std::out_of_range&)
{
    throw sw::Error(sw::Log::errorA1B(FUNCTION, "sw::Engine::activeSceneName()", eventName));
}

void sw::EventManager::drop(const std::string& eventName, sw::EventInfo& info, const std::string& target)
try
{
    m_eventList.at(eventName)->drop(info, target);
}
catch (std::out_of_range&)
{
    throw sw::Error(sw::Log::errorA1B(FUNCTION, "sw::Engine::activeSceneName()", eventName));
}

void sw::EventManager::drop(const std::string& eventName, sw::EventInfo& info, std::set<std::string> targets)
try
{
    m_eventList.at(eventName)->drop(info, targets);
}
catch (std::out_of_range&)
{
    throw sw::Error(sw::Log::errorA1B(FUNCTION, "sw::Engine::activeSceneName()", eventName));
}

void sw::EventManager::clearEvents()
{
    for (auto& [name, event] : m_eventList) {
        event->clearListener();
    }
}