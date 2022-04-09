/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Engine.hpp
 *
 * Description:
 * Engine static class
 * The Engine class is the basis of the ShipWreck Engine. You must use this
 * class to create a software with the ShipWreck Engine.
 * It provides you a simple software architecture for your project.
 * See the documentation for details and several tutorials.
 */

#ifndef __SHIPWRECK_CORE_ENGINE_HPP__
#define __SHIPWRECK_CORE_ENGINE_HPP__

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <type_traits>
#include <memory>

#include "../Config.hpp"
#include "../concepts.hpp"

#include "../scene/AScene.hpp"
#include "../module/AModule.hpp"
#include "../utils/Speech.hpp"

namespace sw
{

    class SW_CORE_API_EXPORT Engine
    {

        private:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The map use to store the created @b Scene.
            ///
            /// @arg std::string             The @b Scene name.
            /// @arg std::unique_ptr<AScene> The @b Scene itself.
            //
            static std::unordered_map<std::string, std::unique_ptr<AScene>> m_scenes;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The name of the active @b Scene.
            /// Use by the @b Engine to update the Software.
            //
            static std::string m_activeScene;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The created @b Module.
            /// Use by the @b Engine to update the Software.
            //
            static std::unique_ptr<AModule> m_module;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Use to know if the @b Engine is load or unload.
            //
            static bool m_isLoad;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When a @b Scene is delete, its name is first place in
            /// this set, in order to not pose any problem during the update.
            //
            static std::unordered_set<std::string> m_scenesToDelete;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When you want to change the active @b Scene, the next
            /// scene name is first place in this set in order to not pose any
            /// problem during the update.
            //
            static std::string m_nextActiveScene;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief When the @b Module is delete, this bool is set to true
            /// to notify the Engine, in order to not pose any problem during
            /// the update.
            //
            static bool m_moduleToDelete;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief EventManager use in the @b Engine internaly.
            //
            static EventManager m_eventManager;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief This function delete the requested @b Scenes at the end
            /// of the update.
            //
            static void deleteRequestedScenes();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief This function activate the requested @b Scene at the end
            /// of the update.
            //
            static void setRequestedActiveScene();
            ///

            static std::unordered_map<std::string, std::unique_ptr<AScene>>& getScenes();

            static void setActiveSceneName(const std::string& newSceneName);

            /*////////////////////////////////////////////////////////////////*/
            /// @brief This function delete the @b Module at the end
            /// of the update if it is requested.
            //
            static void executeDeleteModule();
            ///

            static void setModule(std::unique_ptr<AModule>&& module);

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief @c Constructor deleted because it was unique.
            //
            Engine() = delete;
            Engine(Engine&&) = delete;
            Engine(const Engine&) = delete;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor.
            //
            ~Engine() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to initialize the @b Engine.
            //
            static void initialize();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to update the @b Engine.
            //
            static void update();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to terminate the @b Engine.
            //
            static void terminate();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the statut of the @b Engine.
            ///
            /// @return True if the @b Engine is load. False if not.
            //
            static bool isLoad();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Create a new @b Scene.
            ///
            /// @c ConcreteScene Type of the wanted @b Scene.
            ///
            /// @param sceneName The @b Scene Name.
            /// @param args The arguments for the @b Scene constructor.
            ///
            /// @return The newly created @b Scene.
            //
            template <ConcreteScene Scene, typename... Args>
            static Scene& createScene(const std::string& sceneName, Args... args);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b Scene corresponding to the given name.
            ///
            /// @c ConcreteScene Type of the wanted @b Scene.
            ///
            /// @param sceneName The @b Scene Name.
            ///
            /// @return The wanted @b Scene, with the given type.
            //
            template <ConcreteScene Scene>
            static Scene& getScene(const std::string sceneName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b Scene corresponding to the given name.
            ///
            /// @param sceneName The @b Scene Name.
            ///
            /// @return The wanted @b Scene, with the abstract type.
            //
            static AScene& getScene(const std::string& sceneName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b EventManager of the @b Engine.
            ///
            /// @return The @b EventManager.
            //
            static EventManager& eventManager();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the active @b Scene.
            ///
            /// @c ConcreteScene Type of the wanted @b Scene.
            ///
            /// @return The wanted @b Scene, with the given type.
            //
            template <ConcreteScene Scene>
            static Scene& activeScene();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the active @b Scene.
            ///
            /// @c ConcreteScene Type of the wanted @b Scene.
            ///
            /// @return The wanted @b Scene, with the abstract type.
            //
            static AScene& activeScene();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the active @b Scene name.
            ///
            /// @return The active @b Scene name.
            //
            static std::string activeSceneName();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Delete the @b Scene corresponding to the given name.
            ///
            /// @param sceneName The @b Scene Name.
            //
            static void deleteScene(const std::string& sceneName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Verify if the @b Scene corresponding to the given name
            /// exist or not.
            ///
            /// @param sceneName The @b Scene Name.
            ///
            /// @return True if it exist, false if not.
            //
            static bool hasScene(const std::string sceneName);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Delete all the existing @b Scenes of the @b Engine.
            //
            static void eraseScenes();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Set active the @b Scene corresponding to the given name.
            ///
            /// @param sceneName The @b Scene Name.
            //
            static void setActiveScene(const std::string& name);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Create a new @b Module.
            ///
            /// @c ConcreteModule Type of the wanted @b Module.
            ///
            /// @param args The arguments for the @b Module constructor.
            ///
            /// @return The newly created @b Module.
            //
            template <ConcreteModule Module, typename... Args>
            static Module& createModule(Args... args);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b Module use by the @b Engine.
            ///
            /// @c ConcreteScene Type of the wanted @b Module.
            ///
            /// @return The wanted @b Module, with the given type.
            //
            template <ConcreteModule Module>
            static Module& getModule();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b Module use by the @b Engine.
            ///
            /// @return The wanted @b Module, with the abstract type.
            //
            static AModule& getModule();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Delete the @b Module use by the @b Engine.
            //
            static void deleteModule();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Verify if the @b Module exist.
            ///
            /// @return True if it exist, false if not.
            //
            static bool hasModule();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Write in the given out stream the informations of the @b Engine.
            ///
            /// @param os The out stream, std::cout by default.
            /// @param dispContent False by default. If true, will display the content of the scene map.
            //
            static void display(std::ostream& os = std::cout, bool dispContent = false);
            ///

    }; // class Engine

    #include "moduleFunction.inl"
    #include "sceneFunction.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_ENGINE_HPP__