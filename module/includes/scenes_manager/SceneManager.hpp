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

namespace sw
{
    class Scene;

    class SceneManager
    {
        private:
            std::map<std::string, Scene> m_scenes;
            std::string m_nameActiveScene;

        public:
            SceneManager() noexcept;

            void createScene(std::string name);
            void loadScene(std::string SceneName);
            Scene& getScene(int index);
            Scene& getScene(std::string sceneName);
            Scene getActiveScene();
    };
}

#endif //SHIPWRECK_ENGINE_SCENEMANAGER_HPP
