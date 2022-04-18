/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: RigidBody2D.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_RIGIDBODY2D_HPP
#define SWENGINE_OPENGLMODULE_RIGIDBODY2D_HPP

#include "base/Component.hpp"
#include "event/EventCollision.hpp"

#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT RigidBody2D : public sw::Component
    {
        private:
            Vector2f m_velocity;
            Vector2f m_maxVelocity;
            float m_mass;

        public:
            float m_lastTime;
            sw::CollisionEvent::Horizontal m_collideX;
            sw::CollisionEvent::Vertical m_collideY;

            explicit RigidBody2D(sw::GameObject& gameObject);
            ~RigidBody2D() override = default;

            void onCollision(sw::EventInfo& info);

            RigidBody2D& setVelocity(Vector2f velocity);
            RigidBody2D& setMaxVelocity(Vector2f maxVelocity);
            RigidBody2D& setMass(float mass);

            [[nodiscard]] const Vector2f& getVelocity() const;
            [[nodiscard]] const Vector2f& getMaxVelocity() const;
            [[nodiscard]] const float& getMass() const;
    }; // class RigidBody2D
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_RIGIDBODY2D_HPP
