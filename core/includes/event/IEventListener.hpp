/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * IEventListener.hpp
 *
 * Description:
 * Interface class of EventListener
 * An EventListener is link to a Element. It is use to follow an event
 * and call the referenced function when it occured.
 */

#ifndef __SHIPWRECK_CORE_IEVENTLISTENER_HPP__
#define __SHIPWRECK_CORE_IEVENTLISTENER_HPP__

#include <functional>
#include <string>

#include "../concepts.hpp"
#include "../Config.hpp"

namespace sw
{
    class _IEventListener
    {

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b _IEventListener.
            //
            virtual ~_IEventListener() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Execute the referenced @b Element function without argument.
            //
            virtual void catchEvent() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Execute the referenced @b Element function with an
            /// EventInfo as argument.
            ///
            /// @param info The information class needed by the @b Element function
            /// that will be called.
            //
            virtual void catchEvent(EventInfo& info) = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the @b Entity name of the referenced @b Element.
            ///
            /// @return The Entity name.
            //
            virtual std::string linkedElement() const = 0;
            ///

    }; //

}

#endif // __SHIPWRECK_CORE_IEVENTLISTENER_HPP__