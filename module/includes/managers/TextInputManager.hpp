/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2023
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/


#ifndef SHIPWRECK_ENGINE_TEXTINPUTMANAGER_HPP
#define SHIPWRECK_ENGINE_TEXTINPUTMANAGER_HPP

#include "base/AManager.hpp"
#include "../components/ui/TextInput.hpp"

namespace sw
{

    class SW_GRAPH_MODULE_EXPORT TextInputManager : public AManager<TextInput>
    {
        private:
            void keyBoardHandler(std::shared_ptr<sw::TextInput> obj);
        public:
            [[nodiscard]] YAML::Node save() const override;
            void onLoad(YAML::Node& node) override;
            using sw::AManager<TextInput>::AManager;
            ~TextInputManager() override = default;

            void onUpdate() override;
    }; // class TextInputManager

} // sw

#endif // SHIPWRECK_ENGINE_TEXTINPUTMANAGER_HPP
