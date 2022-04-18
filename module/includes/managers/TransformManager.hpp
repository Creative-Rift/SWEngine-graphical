/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: TransformManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_TRANSFORMMANAGER_HPP
#define SWENGINE_OPENGLMODULE_TRANSFORMMANAGER_HPP

#include "base/AManager.hpp"
#include "../components/Transform.hpp"
#include "../OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT TransformManager : public sw::AManager<Transform>
    {
        public:
            using sw::AManager<Transform>::AManager;
            ~TransformManager() = default;

            void onUpdate() override {};
    }; // class TransformManager

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_TRANSFORMMANAGER_HPP
