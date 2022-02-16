/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: TransformManager.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_TRANSFORM_MANAGER_HPP__
#define __RAYLIB_MODULE_TRANSFORM_MANAGER_HPP__

#include "SW/Manager.hpp"
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
            [[nodiscard]] std::string type() const override { return(std::string("Transform Manager")); };
    }; // class TransformManager

} // namespace ray

#endif //__RAYLIB_MODULE_TRANSFORM_MANAGER_HPP__
