/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SpriteManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_SPRITEMANAGER_HPP
#define SWENGINE_OPENGLMODULE_SPRITEMANAGER_HPP

#include "SW/Manager.hpp"
#include "components/Sprite.hpp"
#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT SpriteManager : public sw::AManager<Sprite>
    {
        private:
            static void updateInvert(sw::Sprite& sprite);
            static void defineRect(sw::Sprite& sprite);
        public:
            using sw::AManager<Sprite>::AManager;
            ~SpriteManager() override = default;

            void onUpdate() override;
            [[nodiscard]] std::string type() const override { return(std::string("Sprite Manager")); };
    }; // class SpriteManager
} // namespace SpriteManager

#endif //SWENGINE_OPENGLMODULE_SPRITEMANAGER_HPP
