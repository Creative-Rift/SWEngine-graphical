/*
** ShipWreck Engine , 2022
** AsyncScene.hpp
*/


#ifndef SHIPWRECK_ENGINE_ASYNCSCENE_HPP
#define SHIPWRECK_ENGINE_ASYNCSCENE_HPP

#include "dependencies/glad/glad.h"
#include "GLFW/glfw3.h"
#include "AsyncOperation.hpp"

#include <string>

namespace sw
{
    class Scene;

    class SW_GRAPH_MODULE_EXPORT AsyncScene : public AsyncOperation
    {
    public:
        AsyncScene();
        explicit AsyncScene(std::string sceneName);
        AsyncScene(const AsyncScene& other) = delete;
        ~AsyncScene();

        bool isDone() override;

        std::string m_sceneName;
        bool m_done;
        std::shared_ptr<Scene> m_scene;

    }; // class AsyncScene

    void startThread(sw::AsyncScene *asyncScene);
} // namespace sw

#endif //SHIPWRECK_ENGINE_ASYNCSCENE_HPP
