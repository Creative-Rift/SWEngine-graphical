/*
** ShipWreck Engine , 2022
** Mesh.cpp
*/

#include "MeshRenderer.hpp"

#include <utility>

sw::MeshRenderer::MeshRenderer(sw::GameObject &gameobject, std::shared_ptr<Model> model) :
sw::Component(gameobject),
model(std::move(model))
{}
