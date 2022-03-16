/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Camera.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_CAMERA_HPP
#define SWENGINE_OPENGLMODULE_CAMERA_HPP

#include "SW/Component.hpp"
#include "dependencies/glm/glm.hpp"

namespace sw
{
    class Camera : public sw::Component
    {
        public:
            enum Projection {
                ORTHOGRAPHIC,
                PERSPECTIVE,
            };

            explicit Camera(sw::Entity& entity);
            ~Camera() override = default;
            Camera& setProjection(Projection projection);
            Camera& setFov(float fov);
            Camera& setSize(float size);
            Camera& setClipping(float near, float far);
            Camera& setClippingNear(float near);
            Camera& setClippingFar(float far);

            [[nodiscard]] const glm::mat4& getProjection();
            [[nodiscard]] const glm::mat4& getView() const;

        private:
            Projection m_type;
            float m_fov;
            float m_size;
            float m_clippingNear;
            float m_clippingFar;

            glm::mat4 m_view;

    }; // class Camera
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_CAMERA_HPP
