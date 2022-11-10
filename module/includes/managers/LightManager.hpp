/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: LightManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_LIGHTMANAGER_HPP
#define SWENGINE_OPENGLMODULE_LIGHTMANAGER_HPP

#include "base/AManager.hpp"

#include "OpenGLModule_Config.hpp"
#include "components/Light.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT LightManager : public sw::AManager<Light>
    {
        private:

        public:
            [[nodiscard]] YAML::Node save() const override;
            /// \brief Default constructor of the AManager class
            using sw::AManager<Light>::AManager;

            /// \brief Default destructor
            ~LightManager() override = default;

            void onUpdate() override;
            void onLoad(YAML::Node& node) override;
    }; // class LightManager
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_LIGHTMANAGER_HPP
