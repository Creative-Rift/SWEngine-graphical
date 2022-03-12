/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: TransformManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_CAMERAMANAGER_HPP
#define SWENGINE_OPENGLMODULE_CAMERAMANAGER_HPP

#include "SW/Manager.hpp"
#include "../components/Camera.hpp"
#include "../OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT CameraManager : public sw::AManager<Camera>
    {
        public:
            using sw::AManager<Camera>::AManager;
            ~CameraManager() override = default;

            void onUpdate() override {};
            [[nodiscard]] std::string type() const override { return(std::string("Camera Manager")); };
    }; // class TransformManager

} // namespace ray

#endif //SWENGINE_OPENGLMODULE_CAMERAMANAGER_HPP
