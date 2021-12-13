/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: EventManager.hpp
** Description: [CHANGE]
*/

#ifndef UNITESTS_EVENTMANAGER_HPP
#define UNITESTS_EVENTMANAGER_HPP

#include <unordered_map>
#include <memory>
#include <string>
#include <set>

#include "concepts.hpp"
#include "Event.hpp"

namespace sw
{
    class EventManager
    {
        private:
            std::unordered_map<std::string, std::unique_ptr<Event>> m_eventList;

        public:
            EventManager()
                :   m_eventList{}
            {}
            ~EventManager() = default;

            [[nodiscard]] bool hasEvent(std::string eventName) const;

            Event& create(std::string eventName);
            [[nodiscard]] Event& get(std::string eventName) const;
            [[nodiscard]] Event& operator[](std::string eventName) const;

            void drop(std::string eventName);
            void drop(std::string eventName, EventInfo& info);
            void drop(std::string eventName, std::set<std::string> target);
            void drop(std::string eventName, EventInfo& info, std::set<std::string> target);

    }; // class EventManager

} // namespace

#endif //UNITESTS_EVENTMANAGER_HPP