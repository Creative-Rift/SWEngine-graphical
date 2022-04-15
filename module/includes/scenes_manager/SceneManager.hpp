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

#include "Scene.hpp"

namespace sw
{
    class SceneManager
    {
        private:
            std::map<std::string, Scene> m_scenes;

        public:
            SceneManager();

            void createScene(std::string name);
            void loadScene(std::string SceneName);
            sw::Scene& getScene(int index);
            sw::Scene& getScene(std::string sceneName);
    };
}

#endif //SHIPWRECK_ENGINE_SCENEMANAGER_HPP
