/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * IComponent.hpp
 *
 * Description:
 * Interface class for the Component class.
 * A Component defines a specific behavior to be attached to a given Entity.
 * You can give several Component to an Entity but not two of the same type.
 * To use Component, you must create a Manager with the same or a parent type.
 *
 * /!\ Warning: Don't use it as parent class !
 */

#ifndef __SHIPWRECK_CORE_ICOMPONENT_HPP__
#define __SHIPWRECK_CORE_ICOMPONENT_HPP__

#include <string>

#include "../concepts.hpp"

namespace sw
{

    class _IComponent
    {

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b _IComponent.
            //
            virtual ~_IComponent() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a string corresponding to the @b Entity name
            /// of the @b Component.
            ///
            /// @return The type name.
            //
            virtual std::string name() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Change the activity of the @b Component.
            ///
            /// @param value True or false.
            /// True by default, so the @b Manager will update it.
            /// If it set to false, the @b Manager will not update it.
            //
            virtual void setActive(bool value) = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the activity of the @b Component.
            ///
            /// @return True or false.
            /// True by default, so the @b Manager will update the @b Component.
            /// If it false, the @b Manager will not update it.
            //
            virtual bool isActive() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a reference of the parent @b Entity of the @b Component.
            ///
            /// @return The parent @b Entity.
            //
            virtual Entity& entity() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a string corresponding to the type name of the @b Component.
            ///
            /// @return The type name.
            //
            virtual std::string type() const = 0;
            ///

    }; // class _IComponent

} // namespace sw

#endif // __SHIPWRECK_CORE_ICOMPONENT_HPP__