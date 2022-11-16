/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: RigidBody2DManager.cpp
*/

#include "OpenGLModule.hpp"

#include "managers/MeshManager.hpp"
#include "Mesh.hpp"

void sw::MeshRendererManager::onUpdate()
{
    for (auto& [_, obj] : m_components) {
        if (!obj->isActive() || !obj->gameObject().isActive())
            continue;
        sw::ConcreteComponent auto& transform = obj->gameObject().transform();
        drawModel(*obj, transform);
    }
}

void sw::MeshRendererManager::drawModel(sw::MeshRenderer& meshRenderer, sw::Transform &transform)
{
    sw::ConcreteComponent auto& camera = m_scene.getGameObject("MainCamera").getComponent<sw::Camera>("CameraManager");
    meshRenderer.model->shader->useShader();
    meshRenderer.model->shader->setUniMat4("projection", camera.getProjection());
    meshRenderer.model->shader->setUniMat4("view", camera.getView());
    meshRenderer.model->shader->setUniMat4("model", transform.getGlobalMatrix());

    for (int i = 0; i < MAX_LIGHT; i++)
        meshRenderer.model->shader->setUniInt("lights[" + std::to_string(i) + "].type", -1);
    //light
    int index = 0;
    for (auto& light : meshRenderer.m_lights) {
        meshRenderer.model->shader->setUniInt("lights[" + std::to_string(index) + "].type", light.value().getType());
        meshRenderer.model->shader->setUniFloat3("lights[" + std::to_string(index) + "].position", light.value().getType() == sw::Light::DIRECTIONAL ? light.value().m_pos : light.value().gameObject().transform().getGlobalPosition());
        meshRenderer.model->shader->setUniFloat3("lights[" + std::to_string(index) + "].ambient", light.value().m_ambient);
        meshRenderer.model->shader->setUniFloat3("lights[" + std::to_string(index) + "].diffuse", light.value().m_diffuse);
        meshRenderer.model->shader->setUniFloat3("lights[" + std::to_string(index) + "].specular", light.value().m_specular);
        meshRenderer.model->shader->setUniFloat("lights[" + std::to_string(index) + "].constant", light.value().m_constant);
        meshRenderer.model->shader->setUniFloat("lights[" + std::to_string(index) + "].linear", light.value().m_linear);
        meshRenderer.model->shader->setUniFloat("lights[" + std::to_string(index) + "].quadratic", light.value().m_quadratic);
        meshRenderer.model->shader->setUniFloat("material.shininess", light.value().m_shininess);
        index++;
    }
    meshRenderer.model->shader->setUniFloat3("viewPos", transform.getGlobalPosition());

    if (meshRenderer.m_animator.hasValue()) {
        meshRenderer.m_animator.value().updateAnimation(meshRenderer.m_animator.value().m_play ? sw::OpenGLModule::deltaTime() : 0);
        auto transforms = meshRenderer.m_animator.value().getFinalBoneMatrices();
        meshRenderer.model->shader->useShader();
        for (int i = 0; i < transforms.size(); ++i)
            meshRenderer.model->shader->setUniMat4("finalBonesMatrices[" + std::to_string(i) + "]", transforms[i]);
    }

    for(auto & meshes : meshRenderer.model->meshes)
        drawMesh(*meshRenderer.model, meshes);
    glUseProgram(0);
}

void sw::MeshRendererManager::drawMesh(sw::Model &model, sw::Mesh &mesh)
{
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    for(unsigned int i = 0; i < mesh.m_texture.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        std::string number;
        std::string name = mesh.m_texture[i]->type;
        if(name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else
            continue;

        model.shader->setUniInt("material.diffuse", (int)i);
        glBindTexture(GL_TEXTURE_2D, mesh.m_texture[i]->getId());
    }
    // draw mesh
    glBindVertexArray(mesh.VAO);
    glDrawElements(GL_TRIANGLES, mesh.m_indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);

    glActiveTexture(GL_TEXTURE0);
}