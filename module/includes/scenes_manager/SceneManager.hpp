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

namespace sw
{
    class Scene;

    class SW_GRAPH_MODULE_EXPORT SceneManager
    {
        private:
            std::map<std::string, Scene> m_scenes;
            std::string m_nameActiveScene;
            std::string m_nameNextActiveScene;

        public:
            SceneManager() noexcept;

            void checkForNewScene();
            void createScene(std::string name);
            void createScene(std::string name, std::string config_file);
            void loadScene(std::string SceneName);
            Scene& getScene(int index);
            Scene& getScene(std::string sceneName);
            Scene getActiveScene();
    };
}

#endif //SHIPWRECK_ENGINE_SCENEMANAGER_HPP
