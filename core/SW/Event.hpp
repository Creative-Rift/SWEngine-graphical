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
 * The EventManager manage all the Event of a Scene.
 * There is one EventManager in each Scene.
 * With it, you can create several Event and drop a notification when you judged
 * that it occured.
 * When you send a notification, you can choose to also send Event Information
 * and/or a list of Entity Name that will be the only one affected by this notification.
 *
 * With an Event, you can subscribe a Component to this event to listen the wanted event.
 * When this event occured, the Event class drop a notification to all the EventListener
 * that were subscribed.
 *
 * An EventListener is link to a Component. It is use to follow an event
 * and call the referenced function when it occured.
 *
 * An EventInfo is used by EventListener to carry an IEventInfo. Behind this IEventInfo
 * is a real class that contained information about the event.
 * When you want to send information throught the Event system, you need to
 * create your own class based on IEventInfo. So you can send it with an
 * EventInfo class using the drop function.
 */

#ifndef __SW_CORE_INC_EVENT_HPP__
#define __SW_CORE_INC_EVENT_HPP__

#include "../includes/event/EventManager.hpp"
#include "../includes/event/EventInfo.hpp"

#endif // __SW_CORE_INC_EVENT_HPP__