/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Entity.hpp
 *
 * Description:
 * Entity class
 * An Entity is a kind of id to manage Component.
 * So, you need an Entity to link Component on it by creating them.
 * Entity also is a good tools to link Component between them with the parent-child system.
 * To create an Entity, you must use a Scene.
 */

#ifndef __SHIPWRECK_CORE_ENTITY_HPP__
#define __SHIPWRECK_CORE_ENTITY_HPP__

#include <ostream>
#include <string>
#include <unordered_map>
#include <type_traits>

#include "IEntity.hpp"
#include "../component/IComponent.hpp"
#include "../scene/AScene.hpp"
#include "../manager/AManager.hpp"
#include "../utils/Reference.hpp"

namespace sw
{

    class Entity :
        public _IEntity
    {

        private:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The activity of an @b Entity.
            /// True by default, so the @b Manager will update its component.
            /// If it is false, the @b Manager will not update its component.
            //
            bool m_isActive;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The name of the @b Entity.
            //
            const std::string m_name;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The reference of the parent scene of the @b Entity.
            //
            AScene& m_scene;
            ///

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The parent @b Entity of this @b Entity.
            /// Some @b Component can use it to recover its informations.
            //
            Reference<Entity> m_parent;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The map use to store the children of the @b Entity.
            /// Some @b Component can use it to recover their informations.
            ///
            /// @arg std::string             The @b Entity name.
            /// @arg std::unique_ptr<Entity> An @b Entity child.
            //
            std::unordered_map<std::string, std::reference_wrapper<Entity>> m_childrenMap;
            ///

            Entity() = delete;
            Entity(Entity&&) = delete;
            Entity(const Entity&) = delete;

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of an @b Entity.
            ///
            /// @param entityName The futur name of the @b Entity.
            /// @param sceneRef The reference of the parent @b Scene.
            //
            Entity(const std::string& entityName, AScene& sceneRef);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Second @c Constructor of an @b Entity. You can determine
            /// the activity of the @b Entity directly.
            ///
            /// @param entityName The futur name of the @b Entity.
            /// @param sceneRef The reference of the parent @b Scene.
            /// @param isActive The activity of an @b Entity.
            ///
            /// If it is set to true, the @b Manager will update its component.
            /// If it is set to false, the @b Manager will not update its component.
            //
            Entity(const std::string& entityName, AScene& sceneRef, bool isActive);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b Entity.
            //
            ~Entity() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the name of the @b Entity.
            ///
            /// @return The @b Entity name.
            //
            std::string name() const override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a reference of the parent @b Scene of the @b Entity.
            ///
            /// @return The parent @b Scene.
            //
            AScene& scene() override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the activity of the @b Entity.
            ///
            /// @return True or false.
            /// True by default, so the @b Manager will update its component.
            /// If it is false, the @b Manager will not update its component.
            //
            bool isActive() const override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Change the activity of the @b Entity.
            ///
            /// @param value True or false.
            /// True by default, so the @b Manager will update its component.
            /// If it is set to false, the @b Manager will not update its component.
            //
            void setActive(bool value) override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Add the @b Entity corresponding to the given name as
            /// a child of the @b Entity.
            ///
            /// @param entityName The futur @b Entity child name.
            //
            void addChild(const std::string& entityName) override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Remove the @b Entity corresponding to the given name as
            /// a child of the @b Entity.
            ///
            /// @param entityName The @b Entity child name to remove.
            //
            void removeChild(const std::string& entityName) override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Make a request to the @b Manager corresponding to the
            /// given name to create a @b Component for the @b Entity.
            ///
            /// @c ConcreteComponent Type of the wanted @b Component.
            ///
            /// @param managerName The @b Manager name.
            /// @param args The arguments for the @b Component constructor.
            ///
            /// @return The newly created @b Component.
            //
            template <ConcreteComponent Cpt, typename... Args>
            Cpt& createComponent(const std::string& managerName, Args... values);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Make a request to the @b Manager corresponding to the
            /// given name to get the @b Component associate with the @b Entity.
            ///
            /// @c ConcreteComponent Type of the wanted @b Component.
            ///
            /// @param managerName The @b Manager name.
            ///
            /// @return The wanted @b Component.
            //
            template <ConcreteComponent Cpt>
            Cpt& getComponent(const std::string& managerName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Make a request to the @b Manager corresponding to the
            /// given name to check if the @b Component associate with the
            /// @b Entity exist.
            ///
            /// @param managerName The @b Manager name.
            ///
            /// @return True if it exist, false if not.
            //
            bool hasComponent(const std::string& managerName) const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Make a request to the @b Manager corresponding to the
            /// given name to delete the @b Component associate with the @b Entity.
            ///
            /// @param managerName The @b Manager name.
            //
            void deleteComponent(const std::string& managerName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Make a request to the @b Manager corresponding to the
            /// given name to set the layer of the @b Component associate with the @b Entity.
            ///
            /// @param managerName The @b Manager name.
            //
            void setLayer(const std::string& managerName, int layer) override;
            ///

            bool operator==(const sw::Entity& right) const {
                return (m_name == right.m_name);
            }

    }; // class Entity

    std::ostream& operator<<(std::ostream& os, const Entity& entity);

    #include "Entity.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_ENTITY_HPP__