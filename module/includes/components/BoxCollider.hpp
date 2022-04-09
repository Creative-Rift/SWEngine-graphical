/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BoxCollider.hppp.h
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_BOXCOLLIDER_HPP
#define SWENGINE_OPENGLMODULE_BOXCOLLIDER_HPP

#include "SW/Component.hpp"

#include "SW/Utils.hpp"

#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT BoxCollider : public sw::Component
    {
        private:
            Vector2f m_size;
            bool m_static;
            bool m_isTrigger;

        public:
            explicit BoxCollider(sw::Entity& entity);

            BoxCollider& setSize(float x, float y);
            BoxCollider& setSize(Vector2f size);
            BoxCollider& setStatic(bool state);
            BoxCollider& setTrigger(bool trigger);

            [[nodiscard]] const Vector2f& getSize() const;
            [[nodiscard]] const bool& isStatic() const;
            [[nodiscard]] const bool& isTrigger() const;
    }; // class BoxCollider
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_BOXCOLLIDER_HPP
