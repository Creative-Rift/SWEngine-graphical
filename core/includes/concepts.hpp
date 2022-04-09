/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * concepts.hpp
 *
 * Description:
 * Concept header file for the Engine.
 * It contains all class declaration and templation concept.
 */

#ifndef __SHIPWRECK_CORE_CONCEPTS_HPP__
#define __SHIPWRECK_CORE_CONCEPTS_HPP__

#include <concepts>

namespace sw
{

    class EventManager;
    class Event;
    class IEventInfo;
    class EventInfo;
    class _IEventListener;
    class Error;
    class Log;

    class AModule;
    class AScene;
    class _IManager;
    class _IEntity;
    class Entity;
    class Component;

    class AResources;
    class ITexture;
    class IFont;
    class ISound;
    class IMusic;
    class IModel;

    template <class T>
    concept ConcreteResource = std::is_base_of<AResources, T>::value;

    template <class T>
    concept ConcreteModule = std::is_base_of<AModule, T>::value;

    template <class T>
    concept ConcreteScene = std::is_base_of<AScene, T>::value;

    template <class T>
    concept ConcreteManager = std::is_base_of<_IManager, T>::value;

    template <class T>
    concept ConcreteComponent = std::is_base_of<Component, T>::value;

    template <class T>
    concept ConcreteEventInfo = std::is_base_of<IEventInfo, T>::value;

    template <class T, class Cpt>
    concept ConcreteChild = std::is_base_of<Component, Cpt>::value
                            && std::is_base_of<Cpt, T>::value;

    template <class T>
    concept EventCallable = std::is_base_of<Component, T>::value
                            || std::is_base_of<AModule, T>::value
                            || std::is_base_of<AScene, T>::value;

    template <class T>
    concept ConcreteTexture = std::is_base_of<ITexture, T>::value;
    template <class T>
    concept ConcreteFont = std::is_base_of<IFont, T>::value;
    template <class T>
    concept ConcreteSound = std::is_base_of<ISound, T>::value;
    template <class T>
    concept ConcreteMusic = std::is_base_of<IMusic, T>::value;
    template <class T>
    concept ConcreteModel = std::is_base_of<IModel, T>::value;

} // namespace sw

#endif // __SHIPWRECK_CORE_CONCEPTS_HPP__