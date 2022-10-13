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
    for(auto & meshes : meshRenderer.model->meshes)
        drawMesh(*meshRenderer.model, meshes);
    glUseProgram(0);
}

void sw::MeshRendererManager::drawMesh(sw::Model &model, std::shared_ptr<sw::Mesh> &mesh)
{
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    for(unsigned int i = 0; i < mesh->m_texture.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        std::string number;
        std::string name = mesh->m_texture[i]->type;
        if(name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else
            continue;

        int y = (int)i;
        model.shader->setUniInt(name + number, y);
        glBindTexture(GL_TEXTURE_2D, mesh->m_texture[i]->getId());
    }
    // draw mesh
    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, mesh->m_indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);

    glActiveTexture(GL_TEXTURE0);
}