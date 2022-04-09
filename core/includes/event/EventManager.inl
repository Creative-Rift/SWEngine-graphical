/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * EventManager.inl
 *
 * Description:
 * Implementation of EventManager functions
 */

inline sw::EventManager::EventManager()
    :   m_eventList{}
{}

inline bool sw::EventManager::hasEvent(const std::string& eventName) const
{
    return (m_eventList.contains(eventName));
}