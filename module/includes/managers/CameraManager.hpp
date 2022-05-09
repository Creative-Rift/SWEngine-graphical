/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: TransformManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_CAMERAMANAGER_HPP
#define SWENGINE_OPENGLMODULE_CAMERAMANAGER_HPP

#include "base/AManager.hpp"
#include "../components/Camera.hpp"
#include "../OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT CameraManager : public sw::AManager<Camera>
    {
        public:
            [[nodiscard]] YAML::Node save() const override;
            void onLoad(YAML::Node& node) override;
            using sw::AManager<Camera>::AManager;
            ~CameraManager() override = default;

            void onUpdate() override {};
    }; // class TransformManager

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_CAMERAMANAGER_HPP
