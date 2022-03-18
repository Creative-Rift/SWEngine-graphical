/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BoxColliderManager.h
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_BOXCOLLIDERMANAGER_HPP
#define SWENGINE_OPENGLMODULE_BOXCOLLIDERMANAGER_HPP

#include "SW/Manager.hpp"
#include "components/BoxCollider.hpp"

namespace sw
{
    class BoxColliderManager : public sw::AManager<BoxCollider>
    {
        private:
            std::unordered_map<std::string, std::shared_ptr<BoxCollider>> m_static;

        public:
            using sw::AManager<BoxCollider>::AManager;
            ~BoxColliderManager() override = default;

            void onUpdate() override;
            [[nodiscard]] std::string type() const override { return(std::string("BoxColliderManager")); };
            void addStatic(std::string name);

    };
}

#endif //SWENGINE_OPENGLMODULE_BOXCOLLIDERMANAGER_HPP
