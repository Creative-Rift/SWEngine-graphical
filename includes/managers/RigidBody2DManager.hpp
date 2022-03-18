/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: RigidBody2DManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_RIGIDBODY2DMANAGER_HPP
#define SWENGINE_OPENGLMODULE_RIGIDBODY2DMANAGER_HPP

#include "SW/Manager.hpp"

#include "components/RigidBody2D.hpp"

namespace sw
{
    class RigidBody2DManager : public sw::AManager<RigidBody2D>
    {
        public:
            using sw::AManager<RigidBody2D>::AManager;
            ~RigidBody2DManager() override = default;

            void onUpdate() override;
    }; // class RigidBody2DManager
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_RIGIDBODY2DMANAGER_HPP
