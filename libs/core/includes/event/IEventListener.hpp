/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: IEventListener.h
** Description: [CHANGE]
*/

#ifndef SHIPWRECKENGINE_AEVENTLISTENER_H
#define SHIPWRECKENGINE_AEVENTLISTENER_H

#include <functional>
#include <string>

#include "EventInfo.hpp"

namespace sw
{
    class IEventListener
    {

        public:
            virtual ~IEventListener() = default;

            virtual void catchEvent() = 0;
            virtual void catchEvent(EventInfo& info) = 0;

            virtual std::string linkedEntity() const = 0;

    }; //

}

#endif //SHIPWRECKENGINE_AEVENTLISTENER_H
