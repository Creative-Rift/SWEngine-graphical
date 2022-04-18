/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * SceneLoadEvent.hpp
 *
 * Description:
 */

#ifndef SHIPWRECK_ENGINE_SCENELOADEVENT_HPP
#define SHIPWRECK_ENGINE_SCENELOADEVENT_HPP

#include "event/EventInfo.hpp"
#include "OpenGLModule_Config.hpp"

#include "scenes_manager/scene/Scene.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT SceneLoadEvent : public IEventInfo
    {
        public:
            Scene& scene;
            explicit SceneLoadEvent(Scene& targetScene);
    };
}

#endif //SHIPWRECK_ENGINE_SCENELOADEVENT_HPP
