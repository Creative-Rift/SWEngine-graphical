/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Event.hpp
 *
 * Description:
 * Event class
 * An Event class represents an event, like a key pressed.
 * You can subscribe a Component to this event to listen the wanted event.
 * When this event occured, the Event class drop a notification to all the listener
 * that were subscribed.
 */

#ifndef __SHIPWRECK_CORE_EVENT_HPP__
#define __SHIPWRECK_CORE_EVENT_HPP__

#include <string>
#include <memory>
#include <forward_list>
#include <set>

#include "../OpenGLModule_Config.hpp"
#include "../concepts.hpp"

#include "EventListener.hpp"

namespace sw
{

    class SW_GRAPH_MODULE_EXPORT Event
    {

        private:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The list of Component's Listener.
            //
            std::unordered_map<std::string, std::shared_ptr<_IEventListener>> m_listenerList;
            ///

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of an @b Event.
            //
            Event();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b Event.
            //
            ~Event() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Subscribe a @b Component to the @b Event allow it to
            /// listen it to execute a function when its occured.
            ///
            /// @c ConcreteComponent Type of the wanted @b Component.
            ///
            /// @param cpt The @b Component that listen the Event.
            /// @param call The @b Component function that will be called when
            /// the @b Event occured. This function take nothing as argument.
            //
            template <class Cpt>
            void subscribe(std::string name, Cpt* cpt, void (Cpt::*call)());
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Subscribe a @b Component to the @b Event allow it to
            /// listen it to execute a function when its occured.
            ///
            /// @c ConcreteComponent Type of the wanted @b Component.
            ///
            /// @param cpt The @b Component that listen the Event.
            /// @param call The @b Component function that will be called when the
            /// @b Event occured. This function must take an @b EventInfo as parameter.
            //
            template <class Cpt>
            void subscribe(std::string name, Cpt* cpt, void (Cpt::*call)(EventInfo&));
            ///

            void unsubscribe(std::string name);

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When the Event occured, call this function to drop a
            /// notification to all the listener.
            //
            void drop();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When the Event occured, call this function to drop a
            /// notification to all the listener.
            ///
            /// @param info The information class needed by the @b Component function
            /// that will be called.
            //
            void drop(EventInfo& info);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When the Event occured, call this function to drop a
            /// notification to all the listener.
            ///
            /// @param target The list of target that will received the notification
            /// among the listener. You need to provide the @b Entity name of the
            /// @b Component listener.
            //
            void drop(std::set<std::string> targets);
            ///

            void drop(const std::string& target);
            void drop(EventInfo& info, const std::string& target);

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When the Event occured, call this function to drop a
            /// notification to all the listener.
            ///
            /// @param info The information class needed by the @b Component function
            /// that will be called.
            /// @param target The list of target that will received the notification
            /// among the listener. You need to provide the @b Entity name of the
            /// @b Component listener.
            //
            void drop(EventInfo& info, std::set<std::string> targets);
            ///

            void clearListener();

    }; // class Event

    #include "Event.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_EVENT_HPP__
