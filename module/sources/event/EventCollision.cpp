/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: EventCollision.cpp
** Description: [CHANGE]
*/

#include "event/EventCollision.hpp"

sw::CollisionEvent::CollisionEvent(std::string obj, std::string target) :
m_obj(obj),
m_target(target),
m_vertical(sw::CollisionEvent::V_NONE),
m_horizontal(sw::CollisionEvent::H_NONE)
{

}