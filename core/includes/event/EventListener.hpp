/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * EventListener.hpp
 *
 * Description:
 * EventListener class
 * An EventListener is link to a Component. It is use to follow an event
 * and call the referenced function when it occured.
 */

#ifndef __SHIPWRECK_CORE_EVENTLISTENER_HPP__
#define __SHIPWRECK_CORE_EVENTLISTENER_HPP__

#include <map>
#include <variant>

#include "../Config.hpp"
#include "../concepts.hpp"

#include "IEventListener.hpp"
#include "../utils/Speech.hpp"

namespace sw
{

    template<EventCallable Element>
    class SW_CORE_API_EXPORT EventListener
        :   public _IEventListener
    {

        private:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief A reference to the linked @b Element. It will be use
            /// to call its referenced function.
            //
            Element& m_element;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The referenced @b Element function. The variant contains
            /// either a function without argument or a function that take an
            /// EventInfo as argument. This function will be call when the @b Event
            /// listen by the @b EventListener occured.
            //
            std::variant<
                void (Element::*)(void),
                void (Element::*)(EventInfo&)
            > m_call;
            ///

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of an @b Event.
            ///
            /// @param obj The linked @b Element.
            /// @param call The referenced @b Element function, without argument.
            //
            explicit EventListener(Element& obj, void (Element::*call)());

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of an @b Event.
            ///
            /// @param obj The linked @b Element.
            /// @param call The referenced @b Element function, with an EventInfo
            /// as argument.
            //
            explicit EventListener(Element& obj, void (Element::*call)(EventInfo&));

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b Event.
            //
            ~EventListener() override = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Execute the referenced @b Element function without argument.
            //
            void catchEvent() override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Execute the referenced @b Element function with an
            /// EventInfo as argument.
            ///
            /// @param info The information class needed by the @b Element function
            /// that will be called.
            //
            void catchEvent(EventInfo& info) override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the @b Entity name of the referenced @b Element.
            ///
            /// @return The Entity name.
            //
            [[nodiscard]] std::string linkedElement() const override;
            ///

    }; // class EventListener

    #include "EventListener.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_EVENTLISTENER_HPP__
