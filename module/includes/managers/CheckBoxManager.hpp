//
// Created by guill on 15/08/2023.
//

#ifndef SHIPWRECK_ENGINE_CHECKBOXMANAGER_HPP
#define SHIPWRECK_ENGINE_CHECKBOXMANAGER_HPP

#include "managers/base/AManager.hpp"

#include "components/ui/CheckBox.hpp"

namespace sw
{

    class SW_GRAPH_MODULE_EXPORT CheckBoxManager : public AManager<CheckBox>
    {
        public:
            using sw::AManager<CheckBox>::AManager;

            void onUpdate() override;

        private:

    };

} // sw

#endif //SHIPWRECK_ENGINE_CHECKBOXMANAGER_HPP
