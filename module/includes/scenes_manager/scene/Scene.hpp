/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * Scene.hpp
 *
 * Description:
 */

#ifndef SHIPWRECK_ENGINE_SCENE_HPP
#define SHIPWRECK_ENGINE_SCENE_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <forward_list>

#include "managers/base/IManager.hpp"
#include "event/EventManager.hpp"

#include "exception/Error.hpp"
#include "utils/Speech.hpp"
#include "utils/Reference.hpp"
#include "JSNP/jsnp.hpp"

#include "OpenGLModule_Config.hpp"
#include "resources/OpenResources.hpp"

#include "gameObject/IGameObject.hpp"
#include "utils/tree/aabb.hpp"

namespace sw
{

    class GameObject;
    class SceneManager;
    class CameraManager;
    class OpenGLModule;

    class SW_GRAPH_MODULE_EXPORT Scene
    {
        private:

            /// @brief Used to know if the Scene is load or unload.
            bool m_isLoad;

            /// @brief When a @b Manager is delete, its name is first place in
            /// this set, in order to not pose any problem during the update.
            std::unordered_set<std::string> m_managersToDelete;

            /// @brief When an @b GameObject is delete, its name is first place in
            /// this set, in order to not pose any problem during the update.
            std::unordered_set<std::string> m_entitiesToDelete;

            Reference<CameraManager> m_cameraManager;

            std::string m_configFile;
            int m_gameObjectId;

            class ManagerMap :
                    private std::unordered_map<std::string, std::shared_ptr<_IManager>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<_IManager>>::begin;
                    using std::unordered_map<std::string, std::shared_ptr<_IManager>>::end;
                    using std::unordered_map<std::string, std::shared_ptr<_IManager>>::operator[];

                    friend Scene;
            }
            /// @brief The map use to store the Managers.
            ///
            /// @arg std::string          The Manager name.
            /// @arg std::shared_ptr<Cpt> The Manager itself.
            m_managers;

            class ManagerLayer :
                    private std::forward_list<std::pair<int, std::string>>
            {
                private:
                    bool needSort;

                public:
                    using std::forward_list<std::pair<int, std::string>>::begin;
                    using std::forward_list<std::pair<int, std::string>>::end;

                    friend Scene;
            }
            /// @brief The map use to reference the @b Manager by their layers.
            ///
            /// @arg int         The @b Manager layer.
            /// @arg std::string The @b Manager name.
            m_managersLayers;

            class GameObjectMap :
                    private std::unordered_map<std::string, std::shared_ptr<IGameObject>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<IGameObject>>::begin;
                    using std::unordered_map<std::string, std::shared_ptr<IGameObject>>::end;
                    using std::unordered_map<std::string, std::shared_ptr<IGameObject>>::operator[];

                    friend Scene;
            }
            /// @brief The map use to store the created @b Entities.
            ///
            /// @arg std::string          The @b GameObject name.
            /// @arg std::shared_ptr<Cpt> The @b GameObject itself.
            m_entities;

            /// @brief This function delete the requested @b Entities at the end
            /// of the update.
            void deleteRequestedEntities();

            /// @brief This function delete the requested @b Managers at the end
            /// of the update.
            void deleteRequestedManagers();

            void loadConfigFile();

        public:
            Scene() = delete;

            /// @brief Default @c Constructor of an @b Scene.
            ///
            /// @param managerName The futur name of the @b Scene.
            explicit Scene(const std::string& sceneName);

            /// @brief Default @c Destructor of an @b Scene.
            ~Scene() = default;

            /// @brief The name of the @b Scene.
            std::string name;

            /// @brief The @b EventManager of the @b Scene. You can get it to \n
            /// manage the @b Event of this @b Scene.
            EventManager eventManager;

            /// @brief The @b Resources of the @b Scene. You can get it to \n
            /// use the @b Resources loaded on this @b Scene.
            OpenResources resources;

            /// @brief Return the statut of the @b Scene.
            ///
            /// @return True if the @b Scene is load. False if not.
            [[nodiscard]] bool isLoad() const;

            /// @brief Function called to initialize the @b Scene.
            void load(bool async = false);

            /// @brief Function called to update the @b Scene.
            void update();

            void updatePhysics();
            void updateLogic();
            void updateGraphics();

            /// @brief Function called to terminate the @b Scene.
            void unload();

            /// @brief Create a new @b GameObject.
            ///
            /// @param gameObjectName The @b GameObject name.
            ///
            /// @return The newly created @b GameObject.
            GameObject& createGameObject(const std::string& gameObjectName);

            /// @brief Get the @b GameObject corresponding to the given name.
            ///
            /// @param gameObjectName The @b GameObject name.
            ///
            /// @return The wanted @b GameObject.
            [[nodiscard]] GameObject& getGameObject(const std::string& gameObjectName);

            /// @brief Verify if the @b GameObject corresponding to the given name
            /// exist or not.
            ///
            /// @param gameObjectName The @b GameObject Name.
            ///
            /// @return True if it exist, false if not.
            [[nodiscard]] bool hasGameObject(const std::string& gameObjectName);

            /// @brief Delete the @b GameObject corresponding to the given name.
            ///
            /// @param gameObjectName The @b GameObject Name.
            void deleteGameObject(const std::string& gameObjectName);

            /// @brief Delete all the existing @b Entities of the @b Scene.
            void eraseGameObject();

            /// @brief Calculate the number of @b Entities stored in the @b Scene.
            ///
            /// @return The number of @b Entities.
            [[nodiscard]] std::size_t gameObjectCount() const;

            /// @brief Create a new @b Manager.
            ///
            /// @c ConcreteManager Type of the wanted @b Manager.
            ///
            /// @param sceneName The @b Manager Name.
            /// @param args The arguments for the @b Manager constructor.
            ///
            /// @return The newly created @b Manager.
            template <ConcreteManager Manager, typename... Args>
            Manager& createManager(const std::string& managerName, Args... args);

            /// @brief Get the @b Manager corresponding to the given name.
            ///
            /// @c ConcreteManager Type of the wanted @b Manager.
            ///
            /// @param managerName The @b Manager Name.
            ///
            /// @return The wanted @b Manager, with the given type.
            template <ConcreteManager Manager>
            [[nodiscard]] Manager& getManager(const std::string& managerName);

            /// @brief Get the @b Manager corresponding to the given name.
            ///
            /// @param managerName The @b Manager Name.
            ///
            /// @return The wanted @b Manager, with the interface type.
            [[nodiscard]] _IManager& getManager(const std::string& managerName);

            /// @brief Verify if the @b Manager corresponding to the given name
            /// exist or not.
            ///
            /// @param managerName The @b Manager Name.
            ///
            /// @return True if it exist, false if not.
            [[nodiscard]] bool hasManager(const std::string& managerName);

            /// @brief Delete the @b Manager corresponding to the given name.
            ///
            /// @param managerName The @b Manager Name.
            void deleteManager(const std::string& managerName);

            /// @brief Delete all the existing @b Managers of the @b Scene.
            void eraseManagers();

            /// @brief Calculate the number of @b Managers stored in the @b Scene.
            ///
            /// @return The number of @b Managers.
            [[nodiscard]] std::size_t managersCount() const;

            /// @brief Set the order of the @b Manager corresponding to the given name.
            ///
            /// @param managerName The @b Manager name.
            /// @param layer The new layer of the @b Manager.
            void setOrder(const std::string& managerName, int layer);

            /// @brief Get the order of the @b Manager corresponding to the given name.
            ///
            /// @param managerName The @b Manager name.
            ///
            /// @return The layer of the wanted @b Manager.
            [[nodiscard]] int getOrder(const std::string managerName) const;

            void save() const;

            //AABB tree containing id of entity and their hitboxes
            tree::tree<int, float> m_tree;
            std::unordered_map<int, Reference<Component>> m_lut;

            friend void LoadResourcesFile(const std::string& path);
            friend void AddResourcesOnScene(jsnp::Token& it);
            friend SceneManager;
            friend OpenGLModule;
    };

    #include "Scene.inl"
    #include "SceneManagerFunction.inl"

    //std::ostream& operator<<(std::ostream& os, const AScene& scene);
}

#endif //SHIPWRECK_ENGINE_SCENE_HPP
