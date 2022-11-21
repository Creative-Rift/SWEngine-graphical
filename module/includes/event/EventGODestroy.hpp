/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: EventGODestroy.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_EVENTGODESTROY_HPP
#define SWENGINE_OPENGLMODULE_EVENTGODESTROY_HPP

#include <string>

#include "event/EventInfo.hpp"

#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT GODestroyEvent : public sw::IEventInfo
    {
        public:
            std::string m_obj;

        GODestroyEvent(std::string obj);
    };
}

#endif //SWENGINE_OPENGLMODULE_EVENTGODESTROY_HPP
