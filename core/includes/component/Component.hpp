/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Component.hpp
 *
 * Description:
 * Abstract class for a Component.
 * A Component defines a specific behavior to be attached to a given Entity.
 * You can give several Component to an Entity but not two of the same type.
 * To use Component, you must create a Manager with the same or a parent type.
 */

#ifndef __SHIPWRECK_CORE_COMPONENT_HPP__
#define __SHIPWRECK_CORE_COMPONENT_HPP__

#include <string>
#include <iostream>

#include "IComponent.hpp"
#include "../entity/Entity.hpp"

namespace sw
{

    class  Component :
        public _IComponent
    {

        protected:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The activity of a @b Component.
            /// True by default, so the @b Manager will update it.
            /// If it is false, the @b Manager will not update it.
            //
            bool m_isActive;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The reference of the parent entity of the @b Component.
            //
            Entity& m_entity;
            ///

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of a @b Component.
            ///
            /// @param entityRef The reference of the parent entity.
            //
            explicit Component(Entity& entityRef);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of a @b Component.
            //
            virtual ~Component() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a string corresponding to the @b Entity name
            /// of the @b Component.
            ///
            /// @return The type name.
            //
            std::string name() const override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Change the activity of the @b Component.
            ///
            /// @param value True or false.
            /// True by default, so the @b Manager will update it.
            /// If it is set to false, the @b Manager will not update it.
            //
            void setActive(bool value) override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the activity of the @b Component.
            ///
            /// @return True or false.
            /// True by default, so the @b Manager will update the @b Component.
            /// If it is false, the @b Manager will not update it.
            //
            [[nodiscard]] bool isActive() const override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a reference of the parent @b Entity of the @b Component.
            ///
            /// @return The parent @b Entity.
            //
            [[nodiscard]] Entity& entity() const override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a string corresponding to the type name of the @b Component.
            ///
            /// @return The type name of the @b Component.
            //
            virtual std::string type() const override;
            ///

    }; // class Component

    /*////////////////////////////////////////////////////////////////////////*/
    /// @brief Write in the given out stream the informations of the given @b Component.
    ///
    /// @return The given out stream.
    //
    std::ostream& operator<<(std::ostream& os, const Component& cpt);
    ///

    #include "Component.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_COMPONENT_HPP__