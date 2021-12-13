/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: EventListener.hpp
** Description: [CHANGE]
*/

#ifndef SHIPWRECKENGINE_EVENTLISTENER_HPP
#define SHIPWRECKENGINE_EVENTLISTENER_HPP

#include <map>
#include <variant>

#include "concepts.hpp"
#include "event/IEventListener.hpp"

namespace sw
{

    template<ConcreteComponent Cpt>
    class EventListener
        :   public IEventListener
    {

        private:
            Cpt& m_cpt;
            std::variant<
                void (Cpt::*)(void),
                void (Cpt::*)(EventInfo&)
            > m_call;

        public:
            explicit EventListener(Cpt& obj, void (Cpt::*call)());
            explicit EventListener(Cpt& obj, void (Cpt::*call)(EventInfo&));
            ~EventListener() override = default;

            void catchEvent() override;
            void catchEvent(EventInfo& info) override;

            [[nodiscard]] std::string linkedEntity() const override;

    }; // class EventListener

    #include "EventListener.inl"

} // namespace sw

#endif //SHIPWRECKENGINE_EVENTLISTENER_HPP
