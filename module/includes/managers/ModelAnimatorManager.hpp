/*
** ShipWreck Engine , 2022
** MeshManager.hpp
*/

#ifndef SHIPWRECK_ENGINE_MODELANIMATORMANAGER_HPP
#define SHIPWRECK_ENGINE_MODELANIMATORMANAGER_HPP

#include "base/AManager.hpp"

#include "OpenGLModule_Config.hpp"
#include "components/ModelAnimator.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT ModelAnimatorManager : public sw::AManager<ModelAnimator>
    {
    public:
        using sw::AManager<ModelAnimator>::AManager;
        ~ModelAnimatorManager() override = default;

        void onUpdate() override;

    private:

    }; // class ModelAnimatorManager
} // namespace sw

#endif //SHIPWRECK_ENGINE_MODELANIMATORMANAGER_HPP
