/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * EventInfo.hpp
 *
 * Description:
 * IEventInfo interface class
 * It provide an interface class to create child class EventInfo.
 * These classes are use by Event to share information about the event.
 *
 * EventInfo class
 * It use by EventListener to carry an IEventInfo. Behind this IEventInfo
 * is a real class that contained information about the event.
 * When you want to send information throught the Event system, you need to
 * create your own class based on IEventInfo. So you can send it with an
 * EventInfo class using the drop function.
 */

#ifndef __SHIPWRECK_CORE_EVENTINFO_HPP__
#define __SHIPWRECK_CORE_EVENTINFO_HPP__

#include <typeinfo>

#include "../concepts.hpp"
#include "../OpenGLModule_Config.hpp"
#include "../exception/Error.hpp"

namespace sw
{

    class IEventInfo
    {

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b IEventInfo.
            //
            virtual ~IEventInfo() = default;
            ///

    }; // class IEventInfo

    class SW_GRAPH_MODULE_EXPORT EventInfo
    {

        private:
            IEventInfo& event;

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of an @b EventInfo.
            ///
            /// @param info The event information to share to the @b Component
            /// listener.
            //
            explicit EventInfo(IEventInfo& info) : event{info} {}
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b EventInfo.
            //
            ~EventInfo() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the event information.
            ///
            /// @c ConcreteEventInfo The real type of the EventInfo.
            //
            template<ConcreteEventInfo Info>
            Info& getInfo()
            try
            {
                return (dynamic_cast<Info&>(event));
            }
            catch (const std::bad_cast&)
            {
                throw sw::Error("EventInfo - getInfo - Bad cast", "");
            }
            ///

    }; // class EventInfo

} // namespace sw

#endif // __SHIPWRECK_CORE_EVENTINFO_HPP__
