/*
** ShipWreck Engine , 2022
** Mesh.hpp
*/

#ifndef SHIPWRECK_ENGINE_MESHRENDERER_HPP
#define SHIPWRECK_ENGINE_MESHRENDERER_HPP

#include <vector>

#include "resources/Model.hpp"
#include "Components.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT MeshRenderer : public Component{
    public:
        std::shared_ptr<Model> model;

        MeshRenderer(sw::GameObject& gameobject, std::string name);

    private:

    };
}

#endif //SHIPWRECK_ENGINE_MESHRENDERER_HPP
