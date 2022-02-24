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

namespace sw
{
    class SpriteManager : public sw::AManager<Sprite>
    {
        public:
            using sw::AManager<Sprite>::AManager;
            ~SpriteManager() override = default;

            void onUpdate() override;
            [[nodiscard]] std::string type() const override { return(std::string("Sprite Manager")); };
    }; // class SpriteManager
} // namespace SpriteManager

#endif //SWENGINE_OPENGLMODULE_SPRITEMANAGER_HPP
