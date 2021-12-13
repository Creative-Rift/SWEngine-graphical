/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Component.hpp
*/

#ifndef __SHIPWRECK_COMPONENT_HPP__
#define __SHIPWRECK_COMPONENT_HPP__

#include <string>
#include <iostream>

#include "IComponent.hpp"
#include "Entity.hpp"

namespace sw
{

    class  Component :
        public IComponent
    {

        protected:
            bool m_isActive;
            Entity& m_entity;

        public:
            explicit Component(Entity& entityRef);
            ~Component() = default;

            void setActive(bool value);
            [[nodiscard]] bool isActive() const;
            [[nodiscard]] Entity& entity() const;

    }; // class Component

    std::ostream& operator<<(std::ostream& os, Component& cpt);

    #include "Component.inl"

} // namespace sw

#endif // __SHIPWRECK_COMPONENT_HPP__