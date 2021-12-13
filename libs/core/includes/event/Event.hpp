/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Event.hpp
** Description: [CHANGE]
*/

#ifndef SHIPWRECKENGINE_EVENT_HPP
#define SHIPWRECKENGINE_EVENT_HPP

#include <string>
#include <memory>
#include <forward_list>
#include <set>

#include "concepts.hpp"
#include "EventListener.hpp"

namespace sw
{

    class Event
    {
        private:
            std::forward_list<std::unique_ptr<IEventListener>> m_listenerList;

        public:
            Event()
                :   m_listenerList{}
            {}
            ~Event() = default;

            template <ConcreteComponent Cpt>
            void subscribe(Cpt* cpt, void (Cpt::*call)());
            template <ConcreteComponent Cpt>
            void subscribe(Cpt* cpt, void (Cpt::*call)(EventInfo&));

            void drop();
            void drop(EventInfo& info);
            void drop(std::set<std::string> target);
            void drop(EventInfo& info, std::set<std::string> target);

    }; // class Event

    #include "Event.inl"

} // namespace sw

#endif //SHIPWRECKENGINE_EVENT_HPP
