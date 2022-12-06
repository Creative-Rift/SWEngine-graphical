/*
** ShipWreck Engine , 2022
** PrimitiveManager.hpp
*/

#ifndef SHIPWRECK_ENGINE_PRIMITIVEMANAGER_HPP
#define SHIPWRECK_ENGINE_PRIMITIVEMANAGER_HPP

#include "OpenGLModule_Config.hpp"
#include "components/Primitive.hpp"
#include "base/AManager.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT PrimitiveManager : public sw::AManager<Primitive>
    {
    public:
        using sw::AManager<Primitive>::AManager;
        ~PrimitiveManager() override = default;

        void onUpdate() override;
        void onLoad(YAML::Node& node) override;
        [[nodiscard]] YAML::Node save() const override;

    private:

    }; // class PrimitiveManager
} // namespace sw

#endif //SHIPWRECK_ENGINE_PRIMITIVEMANAGER_HPP
