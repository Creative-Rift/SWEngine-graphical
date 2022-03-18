/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: EventCollision.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_EVENTCOLLISION_HPP
#define SWENGINE_OPENGLMODULE_EVENTCOLLISION_HPP

#include <string>

#include "includes/event/EventInfo.hpp"

namespace sw
{
    class CollisionEvent : public sw::IEventInfo
    {
        public:
            std::string m_obj;
            std::string m_target;
            enum Horizontal {H_NONE, LEFT, RIGHT} m_horizontal;
            enum Vertical {V_NONE, UP, DOWN} m_vertical;

            CollisionEvent(std::string obj, std::string target);
    };
}

#endif //SWENGINE_OPENGLMODULE_EVENTCOLLISION_HPP
