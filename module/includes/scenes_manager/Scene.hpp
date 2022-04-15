/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * Scene.hpp
 *
 * Description:
 */

#ifndef SHIPWRECK_ENGINE_SCENE_HPP
#define SHIPWRECK_ENGINE_SCENE_HPP

#include "SW/Scene.hpp"

namespace sw
{
    class Scene : public AScene
    {
        private:

        public:
            explicit Scene(const std::string& sceneName);

            void onLoad() override;
            void onUpdate() override;
            void onUnload() override;

    };
}

#endif //SHIPWRECK_ENGINE_SCENE_HPP
