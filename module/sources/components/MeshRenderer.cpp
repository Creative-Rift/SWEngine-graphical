/*
** ShipWreck Engine , 2022
** Mesh.cpp
*/

#include "MeshRenderer.hpp"
#include "OpenGLModule.hpp"

sw::MeshRenderer::MeshRenderer(sw::GameObject &gameobject, std::string name) : //TODO Set model as resource
sw::Component(gameobject),
model(gameobject.scene().resources.m_nmodel[name])
{}
