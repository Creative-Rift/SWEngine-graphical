/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AScene.hpp
 *
 * Description:
 * Abstract class for Scene.
 * A Scene is used to manage the Entities and the Component Managers.
 * You can create several Entities or Component Manager but only one with the same name.
 */

#ifndef __SHIPWRECK_CORE_ASCENE_HPP__
#define __SHIPWRECK_CORE_ASCENE_HPP__

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <memory>
#include <forward_list>
#include <type_traits>
#include <stack>

#include "../Config.hpp"
#include "../concepts.hpp"

#include "../entity/IEntity.hpp"
#include "../manager/IManager.hpp"
#include "../resources/AResources.hpp"
#include "../event/EventManager.hpp"

#include "../error/Error.hpp"
#include "../utils/Speech.hpp"
#include "JSNP/jsnp.hpp"

namespace sw
{

    class SW_CORE_API_EXPORT AScene
    {

        private:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Use to know if the @b Scene is load or unload.
            //
            bool m_isLoad;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When a @b Manager is delete, its name is first place in
            /// this set, in order to not pose any problem during the update.
            //
            std::unordered_set<std::string> m_managersToDelete;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When an @b Entity is delete, its name is first place in
            /// this set, in order to not pose any problem during the update.
            //
            std::unordered_set<std::string> m_entitiesToDelete;
            ///

        protected:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The name of the @b Scene.
            //
            const std::string m_name;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The @b EventManager of the @b Scene. You can get it to
            /// manage the @b Event of this @b Scene.
            //
            EventManager m_eventManager;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The @b Resources of the @b Scene. You can get it to
            /// use the @b Resources loaded on this @b Scene.
            //
            std::unique_ptr<AResources> m_resources;
            ///

            class ManagerMap :
                private std::unordered_map<std::string, std::unique_ptr<_IManager>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<_IManager>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<_IManager>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<_IManager>>::operator[];

                friend AScene;
            }
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The map use to store the created @b Managers.
            ///
            /// @arg std::string          The @b Manager name.
            /// @arg std::unique_ptr<Cpt> The @b Manager itself.
            //
            m_managers;
            ///

            class EntityMap :
                private std::unordered_map<std::string, std::unique_ptr<_IEntity>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<_IEntity>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<_IEntity>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<_IEntity>>::operator[];

                friend AScene;
            }
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The map use to store the created @b Entities.
            ///
            /// @arg std::string          The @b Entity name.
            /// @arg std::unique_ptr<Cpt> The @b Entity itself.
            //
            m_entities;
            ///

            class ManagerLayer :
                private std::forward_list<std::pair<int, std::string>>
            {
                private:
                    bool needSort;

                public:
                    using std::forward_list<std::pair<int, std::string>>::begin;
                    using std::forward_list<std::pair<int, std::string>>::end;

                friend AScene;
            }
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The map use to reference the @b Manager by their layers.
            ///
            /// @arg int         The @b Manager layer.
            /// @arg std::string The @b Manager name.
            //
            m_managersLayers;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called on the load of the @b Scene.
            //
            virtual void onLoad() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called on the update of the @b Scene.
            //
            virtual void onUpdate() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called on the unload of the @b Scene.
            //
            virtual void onUnload() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief This function delete the requested @b Entities at the end
            /// of the update.
            //
            void deleteRequestedEntities();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief This function delete the requested @b Managers at the end
            /// of the update.
            //
            void deleteRequestedManagers();
            ///

        public:
            AScene() = delete;
            AScene(AScene&&) = delete;
            AScene(const AScene&) = delete;

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of an @b Scene.
            ///
            /// @param managerName The futur name of the @b Scene.
            //
            explicit AScene(const std::string& sceneName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b Scene.
            //
            ~AScene() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the name of the @b Scene.
            ///
            /// @return The @b Scene name.
            //
            [[nodiscard]] std::string name() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the statut of the @b Scene.
            ///
            /// @return True if the @b Scene is load. False if not.
            //
            [[nodiscard]] bool isLoad() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a string corresponding to the type name of the @b Scene.
            ///
            /// @return The type name of the @b Scene.
            //
            virtual std::string type() const;
            ///

            [[nodiscard]] sw::EventManager& eventManager();

            [[nodiscard]] AResources& resources();
            template <ConcreteResource Resources>
            [[nodiscard]] Resources& resources();

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to initialize the @b Scene.
            //
            void load();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to update the @b Scene.
            //
            void update();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to terminate the @b Scene.
            //
            void unload();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Create a new @b Entity.
            ///
            /// @param entityName The @b Entity name.
            ///
            /// @return The newly created @b Entity.
            //
            Entity& createEntity(const std::string& entityName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b Entity corresponding to the given name.
            ///
            /// @param entityName The @b Entity name.
            ///
            /// @return The wanted @b Entity.
            //
            [[nodiscard]] Entity& getEntity(const std::string& entityName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Verify if the @b Entity corresponding to the given name
            /// exist or not.
            ///
            /// @param entityName The @b Entity Name.
            ///
            /// @return True if it exist, false if not.
            //
            [[nodiscard]] bool hasEntity(const std::string& entityName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Delete the @b Entity corresponding to the given name.
            ///
            /// @param entityName The @b Entity Name.
            //
            void deleteEntity(const std::string& entityName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Delete all the existing @b Entities of the @b Scene.
            //
            void eraseEntities();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Calculate the number of @b Entities stored in the @b Scene.
            ///
            /// @return The number of @b Entities.
            //
            std::size_t entitiesCount() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Create a new @b Manager.
            ///
            /// @c ConcreteManager Type of the wanted @b Manager.
            ///
            /// @param sceneName The @b Manager Name.
            /// @param args The arguments for the @b Manager constructor.
            ///
            /// @return The newly created @b Manager.
            //
            template <ConcreteManager Manager, typename... Args>
            Manager& createManager(const std::string& managerName, Args... args);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b Manager corresponding to the given name.
            ///
            /// @c ConcreteManager Type of the wanted @b Manager.
            ///
            /// @param managerName The @b Manager Name.
            ///
            /// @return The wanted @b Manager, with the given type.
            //
            template <ConcreteManager Manager>
            [[nodiscard]] Manager& getManager(const std::string& managerName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b Manager corresponding to the given name.
            ///
            /// @param managerName The @b Manager Name.
            ///
            /// @return The wanted @b Manager, with the interface type.
            //
            [[nodiscard]] _IManager& getManager(const std::string& managerName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Verify if the @b Manager corresponding to the given name
            /// exist or not.
            ///
            /// @param managerName The @b Manager Name.
            ///
            /// @return True if it exist, false if not.
            //
            [[nodiscard]] bool hasManager(const std::string& managerName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Delete the @b Manager corresponding to the given name.
            ///
            /// @param managerName The @b Manager Name.
            //
            void deleteManager(const std::string& managerName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Delete all the existing @b Managers of the @b Scene.
            //
            void eraseManagers();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Calculate the number of @b Managers stored in the @b Scene.
            ///
            /// @return The number of @b Managers.
            //
            std::size_t managersCount() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Set the layer of the @b Manager corresponding to the given name.
            ///
            /// @param managerName The @b Manager name.
            /// @param layer The new layer of the @b Manager.
            //
            void setLayer(const std::string& managerName, int layer);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the layer of the @b Manager corresponding to the given name.
            ///
            /// @param managerName The @b Manager name.
            ///
            /// @return The layer of the wanted @b Manager.
            //
            [[nodiscard]] int getLayer(const std::string managerName) const;
            ///

            friend void LoadResourcesFile(const std::string& path);
            friend void AddResourcesOnScene(jsnp::Token& it);

            bool operator==(const sw::AScene& right) const {
                return (m_name == right.m_name);
            }

    }; // class AScene

    std::ostream& operator<<(std::ostream& os, const AScene& scene);

    #include "AScene.inl"
    #include "entityFunction.inl"
    #include "managerFunction.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_ASCENE_HPP__