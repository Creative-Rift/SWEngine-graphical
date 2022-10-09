/*
** ShipWreck Engine , 2022
** MeshManager.hpp
*/

#ifndef SHIPWRECK_ENGINE_MESHMANAGER_HPP
#define SHIPWRECK_ENGINE_MESHMANAGER_HPP

#include "base/AManager.hpp"

#include "OpenGLModule_Config.hpp"
#include "components/MeshRenderer.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT MeshRendererManager : public sw::AManager<MeshRenderer>
    {
    public:
        using sw::AManager<MeshRenderer>::AManager;
        ~MeshRendererManager() override = default;

        void onUpdate() override;

    private:
        void drawModel(sw::MeshRenderer& meshRenderer, sw::Transform &transform);
        void drawMesh(sw::Model &model, std::shared_ptr<sw::Mesh> &mesh, sw::Transform &transform);
    }; // class RigidBody2DManager
} // namespace sw

#endif //SHIPWRECK_ENGINE_MESHMANAGER_HPP
