/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2023
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/


#ifndef SHIPWRECK_ENGINE_BUTTONMANAGER_HPP
#define SHIPWRECK_ENGINE_BUTTONMANAGER_HPP

#include "base/AManager.hpp"
#include "../components/ui/Button.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT ButtonManager : public AManager<Button>
    {
        public:
            [[nodiscard]] YAML::Node save() const override;
            void onLoad(YAML::Node& node) override;
            using sw::AManager<Button>::AManager;
            ~ButtonManager() override = default;

            void onUpdate() override;

            friend Button;
    }; // class ButtonManager

} // sw

#endif // SHIPWRECK_ENGINE_BUTTONMANAGER_HPP
