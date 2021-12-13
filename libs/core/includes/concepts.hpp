/*
** EPITECH PROJECT, 2021
** Epitech Years 3
** File description:
** concepts.hpp
*/

#ifndef __CONCEPTS_H__
#define __CONCEPTS_H__

#include <concepts>

namespace sw
{

    class EventManager;
    class Event;
    class IEventInfo;
    class EventInfo;
    class IEventListener;
    class Error;

    class AModule;
    class AScene;
    class IManager;
    class IEntity;
    class Entity;
    class Component;

    class AResources;
    class ITexture;
    class IFont;
    class ISound;
    class IMusic;
    class IModel;

    template <class T>
    concept ConcreteModule = std::is_base_of<AModule, T>::value;

    template <class T>
    concept ConcreteScene = std::is_base_of<AScene, T>::value;

    template <class T>
    concept ConcreteManager = std::is_base_of<IManager, T>::value;

    template <class T>
    concept ConcreteComponent = std::is_base_of<Component, T>::value;

    template <class T>
    concept ConcreteEventInfo = std::is_base_of<IEventInfo, T>::value;

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

#endif // __CONCEPTS_H__