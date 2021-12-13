/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** scene.hpp
*/

#ifndef __SHIPWRECK_ASCENE_HPP__
#define __SHIPWRECK_ASCENE_HPP__

#include <iostream>
#include <unordered_map>
#include <map>
#include <memory>
#include <forward_list>
#include <type_traits>
#include <stack>

#include "concepts.hpp"

#include "entity/IEntity.hpp"
#include "manager/IManager.hpp"

#include "error/Error.hpp"
#include "utils/Speech.hpp"

#include "resources/AResources.hpp"
#include "event/EventManager.hpp"
#include "json_parser/jsnp.hpp"

namespace sw
{

    class AScene
    {

        public:
            class ManagerMap :
                private std::unordered_map<std::string, std::unique_ptr<IManager>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<IManager>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<IManager>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<IManager>>::operator[];

                friend AScene;
            };

            class EntityMap :
                private std::unordered_map<std::string, std::unique_ptr<IEntity>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::operator[];

                friend AScene;
            };

            class ManagerLayer :
                private std::forward_list<std::pair<int, std::string>>
            {
                private:
                    bool needSort;

                public:
                    using std::forward_list<std::pair<int, std::string>>::begin;
                    using std::forward_list<std::pair<int, std::string>>::end;

                friend AScene;
            };

        private:
            const std::string m_name;
            bool m_isLoad;

            ManagerMap m_managerMap;
            ManagerLayer m_managerLayer;

            EntityMap m_entityMap;
            std::stack<std::string> m_deletedEntity;

            EventManager m_eventManager;
            std::unique_ptr<AResources> m_resources;

        protected:
            virtual void onLoad() = 0;
            virtual void onUpdate() = 0;
            virtual void onUnload() = 0;

        public:
            AScene() = delete;
            AScene(AScene&&) = delete;
            AScene(const AScene&) = delete;
            explicit AScene(const std::string& sceneName);
            ~AScene() = default;

            [[nodiscard]] std::string name() const;
            [[nodiscard]] bool isLoad() const;

            [[nodiscard]] ManagerMap& factories();
            [[nodiscard]] ManagerLayer& managerLayers();

            [[nodiscard]] EntityMap& entities();
            [[nodiscard]] std::stack<std::string>& deletedEntities();

            [[nodiscard]] sw::EventManager& eventManager();
            [[nodiscard]] std::unique_ptr<AResources>& resources();

            void load();
            void update();
            void unload();

            Entity& createEntity(const std::string& entityName);
            [[nodiscard]] Entity& getEntity(const std::string& entityName);
            [[nodiscard]] bool hasEntity(const std::string& entityName);
            void deleteEntity(const std::string& entityName);
            void deleteRequestedEntity();

            template <ConcreteManager Manager, typename... Args>
            Manager& createManager(const std::string& managerName, Args... args);
            template <ConcreteManager Manager>
            [[nodiscard]] Manager& getManager(const std::string& managerName);
            [[nodiscard]] IManager& getManager(const std::string& managerName);
            [[nodiscard]] bool hasManager(const std::string& managerName);
            void deleteManager(const std::string& managerName);
            void eraseManager();

            void setLayer(const std::string& managerName, int layer);
            [[nodiscard]] int getLayer(const std::string managerName) const;

            friend void LoadResourcesFile(const std::string& path);
            friend void AddResourcesOnScene(jsnp::Token& it);

            template<class T>
            void createScript(sw::Entity& entity);

            bool operator==(const sw::AScene& right) const {
                return (m_name == right.m_name);
            }

    }; // class scene

    #include "managerFunction.inl"

} // namespace sw

//inline auto operator<=>(const std::pair<int, std::string>& left, const std::pair<int, std::string>& right)
//{
//    return (left.first <=> right.first);
//}

#endif // __SHIPWRECK_ASCENE_HPP__