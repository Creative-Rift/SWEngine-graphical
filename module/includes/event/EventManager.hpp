/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * EventManager.hpp
 *
 * Description:
 * EventManager class
 * The EventManager manage all the Event of a Scene.
 * There is one EventManager in each Scene.
 * With it, you can create several Event and drop a notification when you judged
 * that it occured.
 * When you send a notification, you can choose to also send Event Information
 * and/or a list of Entity Name that will be the only one affected by this notification.
 */

#ifndef __SHIPWRECK_CORE_EVENTMANAGER_HPP__
#define __SHIPWRECK_CORE_EVENTMANAGER_HPP__

#include <unordered_map>
#include <memory>
#include <string>
#include <set>

#include "../concepts.hpp"
#include "../OpenGLModule_Config.hpp"

#include "Event.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT EventManager
    {
        private:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The list of created Event.
            //
            std::unordered_map<std::string, std::shared_ptr<Event>> m_eventList;
            ///

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of an @b EventManager.
            //
            EventManager() noexcept;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b EventManager.
            //
            ~EventManager() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Check if an @b Event exist.
            ///
            /// @param eventName The @b Event Name.
            ///
            /// @return True if it exist, false otherwise.
            //
            [[nodiscard]] bool hasEvent(const std::string& eventName) const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Create a new @b Event.
            ///
            /// @param eventName The @b Event Name.
            ///
            /// @return The newly created @b Event.
            //
            Event& create(const std::string& eventName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b Event corresponding to the given name.
            ///
            /// @param eventName The @b Event Name.
            ///
            /// @return The wanted @b Event.
            //
            [[nodiscard]] Event& get(const std::string& eventName) const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b Event corresponding to the given name.
            ///
            /// @param eventName The @b Event Name.
            ///
            /// @return The wanted @b Event.
            //
            [[nodiscard]] Event& operator[](const std::string& eventName) const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When the @b Event occured, call this function to send
            /// a notification to the @b Event corresponding with the given name.
            ///
            /// @param eventName The @b Event Name.
            //
            void drop(const std::string& eventName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When the @b Event occured, call this function to send
            /// a notification to the @b Event corresponding with the given name.
            /// This function also send an @b EventInfo class. Use it to send information
            /// about the collision to all the listener that will be notified by the
            /// @b Event.
            ///
            /// @param eventName The @b Event Name.
            /// @param info The information class needed by the @b Component function
            /// that will be called.
            //
            void drop(const std::string& eventName, EventInfo& info);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When the @b Event occured, call this function to send
            /// a notification to the @b Event corresponding with the given name.
            /// This function also send a list of @b Entity target, only the listener
            /// associate with the referenced @b Entity will be notified by the @b Event.
            ///
            /// @param eventName The @b Event Name.
            /// @param target The list of target that will received the notification
            /// among the listener. You need to provide the @b Entity name of the
            //
            void drop(const std::string& eventName, std::set<std::string> targets);
            ///

            void drop(const std::string& eventName, const std::string& target);
            void drop(const std::string& eventName, EventInfo& info, const std::string& target);

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When the @b Event occured, call this function to send
            /// a notification to the @b Event corresponding with the given name.
            /// This function send a list of @b Entity target, only the listener
            /// associate with the referenced @b Entity will be notified by the @b Event.
            /// This function also send an @b EventInfo class. Use it to send information
            /// about the collision to all the listener that will be notified by the
            /// @b Event.
            ///
            /// @param eventName The @b Event Name.
            /// @param info The information class needed by the @b Component function
            /// that will be called.
            /// @param target The list of target that will received the notification
            /// among the listener. You need to provide the @b Entities names of the
            /// @b Components listeners.
            //
            void drop(const std::string& eventName, EventInfo& info, std::set<std::string> target);
            ///

            void clearEvents();

    }; // class EventManager

    #include "EventManager.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_EVENTMANAGER_HPP__