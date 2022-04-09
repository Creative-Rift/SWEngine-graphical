/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * IEntity.hpp
 *
 * Description:
 * Interface class of Entity
 * An Entity is a kind of id to manage Component.
 * So, you need an Entity to link Component on it by creating them.
 * Entity also is a good tools to link Component between them with the parent-child system.
 * To create an Entity, you must use a Scene.
 */

#ifndef __SHIPWRECK_CORE_IENTITY_HPP__
#define __SHIPWRECK_CORE_IENTITY_HPP__

#include "../concepts.hpp"

namespace sw
{

    class _IEntity
    {

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b _IEntity.
            //
            virtual ~_IEntity() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the name of the @b Entity.
            ///
            /// @return The @b Entity name.
            //
            virtual std::string name() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a reference of the parent @b Scene of the @b Entity.
            ///
            /// @return The parent @b Scene.
            //
            virtual AScene& scene() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the activity of the @b Component.
            ///
            /// @return True or false.
            /// True by default, so the @b Manager will update its component.
            /// If it is false, the @b Manager will not update its component.
            //
            virtual bool isActive() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Change the activity of the @b Component.
            ///
            /// @param value True or false.
            /// True by default, so the @b Manager will update its component.
            /// If it is set to false, the @b Manager will not update its component.
            //
            virtual void setActive(bool value) = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Add the @b Entity corresponding to the given name as
            /// a child of the @b Entity.
            ///
            /// @param entityName The futur @b Entity child name.
            //
            virtual void addChild(const std::string& entityName) = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Remove the @b Entity corresponding to the given name as
            /// a child of the @b Entity.
            ///
            /// @param entityName The @b Entity child name to remove.
            //
            virtual void removeChild(const std::string& entityName) = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Make a requeste to the @b Manager corresponding to the
            /// given name to delete the @b Component associate with the @b Entity.
            ///
            /// @param managerName The manager name.
            //
            virtual void setLayer(const std::string& managerName, int layer) = 0;
            ///

    }; // class Entity

} // namespace sw

#endif // __SHIPWRECK_CORE_IENTITY_HPP__