/*
** ShipWreck Engine , 2022
** Light.hpp
*/

#ifndef SHIPWRECK_ENGINE_LIGHT_HPP
#define SHIPWRECK_ENGINE_LIGHT_HPP

#include "OpenGLModule_Config.hpp"
#include "components/base/Component.hpp"
#include "utils/Vector3.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Light : public Component
    {
        public:
            enum LightType
            {
                DIRECTIONAL = 1,
                POINT = 2,
            };

            Vector3f m_pos;
            Vector3f m_ambient;
            Vector3f m_diffuse;
            Vector3f m_specular;

            float m_constant;
            float m_linear;
            float m_quadratic;

            float m_shininess;

            explicit Light(GameObject& gameObject);
            Light& setLightType(LightType type);

            [[nodiscard]] int getType() const;
        private:
            LightType m_type;

    }; // class Light
} // namespace sw

#endif //SHIPWRECK_ENGINE_LIGHT_HPP
