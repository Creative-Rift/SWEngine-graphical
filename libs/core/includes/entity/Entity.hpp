/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Entity.hpp
*/

#ifndef __SHIPWRECK_ENTITY_HPP__
#define __SHIPWRECK_ENTITY_HPP__

#include <string>
#include <unordered_map>
#include <type_traits>

#include "IEntity.hpp"
#include "component/IComponent.hpp"
#include "scene/AScene.hpp"
#include "manager/AManager.hpp"
#include "utils/Reference.hpp"

namespace sw
{

    class Entity :
        public IEntity
    {

        private:
            bool m_isActive;
            const std::string m_name;
            AScene& m_scene;

        public:
            Reference<Entity> m_parent;
            std::unordered_map<std::string, std::reference_wrapper<Entity>> m_childrenMap;

            Entity() = delete;
            Entity(Entity&&) = delete;
            Entity(const Entity&) = delete;
            Entity(const std::string& entityName, AScene& sceneRef);
            Entity(const std::string& entityName, AScene& sceneRef, bool isActive);
            ~Entity() = default;

            std::string name() override;
            AScene& scene() override;
            bool isActive() const override;
            void setActive(bool value) override;
            void addChild(const std::string& entityName) override;

            template <ConcreteComponent Cpt, typename... Args>
            Cpt& createComponent(const std::string& managerName, Args... values);

            template <ConcreteComponent Cpt>
            Cpt& getComponent(const std::string& managerName);

            bool hasComponent(const std::string& managerName) const;
            void deleteComponent(const std::string& managerName);
            void setLayer(const std::string& managerName, int layer) override;

            bool operator==(const sw::Entity& right) const {
                return (m_name == right.m_name);
            }

    }; // class Entity


    #include "Entity.inl"

} // namespace sw

#endif // __SHIPWRECK_ENTITY_HPP__