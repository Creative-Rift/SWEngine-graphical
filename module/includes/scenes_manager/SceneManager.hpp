/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * SceneManager.hpp
 *
 * Description:
 */

#ifndef SHIPWRECK_ENGINE_SCENEMANAGER_HPP
#define SHIPWRECK_ENGINE_SCENEMANAGER_HPP

#include <string>
#include <map>

#include "OpenGLModule_Config.hpp"
#include "scene/Scene.hpp"
#include "utils/async/AsyncScene.hpp"

namespace sw
{
    class Scene;

    class SW_GRAPH_MODULE_EXPORT SceneManager
    {
        private:
            bool m_async;
            std::map<std::string, std::shared_ptr<Scene>> m_scenes;
            std::string m_nameActiveScene;

        public:
            std::string m_nameNextActiveScene;
            std::shared_ptr<Scene> m_currentLoadingScene;

            SceneManager() noexcept;

            void checkForNewScene();
            void createScene(std::string name);
            void createScene(std::string name, std::string config_file);
            void loadScene(std::string sceneName);
            [[nodiscard]]std::shared_ptr<AsyncScene> loadSceneAsync(std::string sceneName);
            void swapSceneFromAsync(AsyncScene& operation, std::string sceneName);
            std::shared_ptr<Scene> getScene(int index);
            std::shared_ptr<Scene> getScene(std::string sceneName);
            std::shared_ptr<Scene> getActiveScene();
            std::map<std::string, std::shared_ptr<sw::Scene>>& getScenes();
    };
}

#endif //SHIPWRECK_ENGINE_SCENEMANAGER_HPP
