/*
** ShipWreck Engine , 2022
** Mesh.cpp
*/

#include "MeshRenderer.hpp"

sw::MeshRenderer::MeshRenderer(sw::GameObject &gameobject, std::string name) : //TODO Set model as resource
sw::Component(gameobject),
model(sw::OpenResources::m_nmodel[name])
{}
