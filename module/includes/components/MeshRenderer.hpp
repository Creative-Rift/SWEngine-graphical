/*
** ShipWreck Engine , 2022
** Mesh.hpp
*/

#ifndef SHIPWRECK_ENGINE_MESHRENDERER_HPP
#define SHIPWRECK_ENGINE_MESHRENDERER_HPP

#define MAX_LIGHT 5

#include <vector>

#include "resources/Model.hpp"
#include "Components.hpp"
#include "Light.hpp"

namespace sw
{
    class MeshRendererManager;
    class SW_GRAPH_MODULE_EXPORT MeshRenderer : public Component{
    public:
        std::shared_ptr<Model> model;

        MeshRenderer(sw::GameObject& gameObject, std::string name);

        MeshRenderer& attachLight(std::string lightName);
        MeshRenderer& attachLight(Light& light);
        MeshRenderer& detachLight(int index);
        MeshRenderer& detachLight(std::string lightName);
    private:
        std::vector<sw::Reference<Light>> m_lights;

        friend MeshRendererManager;
    };
}

#endif //SHIPWRECK_ENGINE_MESHRENDERER_HPP
