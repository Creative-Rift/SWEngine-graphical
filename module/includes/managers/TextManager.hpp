/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: FONTManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_FONTMANAGER_HPP
#define SWENGINE_OPENGLMODULE_FONTMANAGER_HPP

#include "base/AManager.hpp"
#include "components/Text.hpp"
#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT TextManager : public sw::AManager<Text>
    {
        public:
            using sw::AManager<Text>::AManager;
            ~TextManager() override = default;

            void onUpdate() override;
    }; // class FONTManager
} // namespace FONTManager

#endif //SWENGINE_OPENGLMODULE_FONTMANAGER_HPP
