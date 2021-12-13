/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Engine.hpp
*/

#ifndef __SHIPWRECK_ENGINE_HPP__
#define __SHIPWRECK_ENGINE_HPP__

#include <unordered_map>
#include <stack>
#include <string>
#include <type_traits>

#include "concepts.hpp"

#include "../scene/AScene.hpp"
#include "../module/AModule.hpp"

namespace sw
{

    class Engine
    {

        private:
            static std::unordered_map<std::string, std::unique_ptr<AScene>> m_scenes;
            static std::string m_activeScene;
            static std::unordered_map<std::string, std::unique_ptr<AModule>> m_modules;
            static std::string m_activeModule;
            static bool m_isLoad;
            static std::stack<std::string> m_sceneToDelete;
            static std::stack<std::string> m_moduleToDelete;
            static std::string m_nextActiveScene;
            static std::string m_nextActiveModule;

            static void onInitialize();
            static void onUpdate();
            static void onTerminate();

        public:
            Engine() = delete;
            Engine(Engine&&) = delete;
            Engine(const Engine&) = delete;
            ~Engine() = default;

            static void initialize();
            static void update();
            static void terminate();

            static bool isLoad();


            template <ConcreteScene Scene>
            static Scene& createScene(const std::string& sceneName);

            template <ConcreteScene Scene>
            static Scene& getScene(const std::string& sceneName);
            static AScene& getScene(const std::string& sceneName);

            template <ConcreteScene Scene>
            static Scene& activeScene();
            static AScene& activeScene();
            static std::string activeSceneName();

            static void deleteScene(const std::string& sceneName);
            static bool hasScene(const std::string& sceneName);
            static void eraseScene();

            static void setActiveScene(const std::string& name);


            template <ConcreteModule Module>
            static Module& createModule(const std::string& moduleName);

            template <ConcreteModule Module>
            static Module& getModule(const std::string& moduleName);
            static AModule& getModule(const std::string& moduleName);

            template <ConcreteModule Module>
            static Module& activeModule();
            static AModule& activeModule();
            static std::string activeModuleName();

            static void deleteModule(const std::string& moduleName);
            static bool hasModule(const std::string& moduleName);
            static void eraseModule();

            static void setActiveModule(const std::string& moduleName);

            static void executeDeleteScene();
            static void executeSetActiveScene();

            static void executeDeleteModule();
            static void executeSetActiveModule();

    }; // class Engine

    #include "moduleFunction.inl"
    #include "sceneFunction.inl"

} // namespace sw

#endif // __SHIPWRECK_ENGINE_HPP__