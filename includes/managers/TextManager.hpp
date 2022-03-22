/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: FONTManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_FONTMANAGER_HPP
#define SWENGINE_OPENGLMODULE_FONTMANAGER_HPP

#include "SW/Manager.hpp"
#include "components/Text.hpp"

namespace sw
{
    class TextManager : public sw::AManager<Text>
    {
        public:
            using sw::AManager<Text>::AManager;
            ~TextManager() override = default;

            void onUpdate() override;
            [[nodiscard]] std::string type() const override { return(std::string("Text Manager")); };
    }; // class FONTManager
} // namespace FONTManager

#endif //SWENGINE_OPENGLMODULE_FONTMANAGER_HPP
