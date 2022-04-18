/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BoxColliderManager.h
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_BOXCOLLIDERMANAGER_HPP
#define SWENGINE_OPENGLMODULE_BOXCOLLIDERMANAGER_HPP

#include "base/AManager.hpp"

#include "OpenGLModule_Config.hpp"
#include "components/BoxCollider.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT BoxColliderManager : public sw::AManager<BoxCollider>
    {
        private:
            std::unordered_map<std::string, std::shared_ptr<BoxCollider>> m_static;

        public:
            using sw::AManager<BoxCollider>::AManager;
            ~BoxColliderManager() override = default;

            void onUpdate() override;
            void addStatic(std::string name);

    };
}

#endif //SWENGINE_OPENGLMODULE_BOXCOLLIDERMANAGER_HPP
