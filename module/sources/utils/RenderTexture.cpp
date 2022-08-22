/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/

#include "utils/RenderTexture.hpp"
#include "Error.hpp"
#include "OpenGLModule.hpp"

sw::RenderTexture::RenderTexture(bool defaultRender) :
m_name("RenderTexture"),
m_frameBufferId(0),
m_texture()
{
    CreateRenderTexture(defaultRender);
}

sw::RenderTexture::RenderTexture(std::string name, bool defaultRender) :
m_name(name),
m_frameBufferId(0),
m_texture("resources/textures/logo.png")
{
    CreateRenderTexture(defaultRender);
}

void sw::RenderTexture::CreateRenderTexture(bool defaultRender)
{
    glGenFramebuffers(1, &m_frameBufferId);
    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBufferId);

    glBindTexture(GL_TEXTURE_2D, m_texture.getId());

    if (defaultRender) {
        glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_texture.getId(), 0);
        GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
        glDrawBuffers(1, drawBuffers);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, m_texture.getId());
    sw::OpenGLModule::sceneManager().getActiveScene().resources.m_ntext.emplace(m_name, std::make_shared<sw::Texture>(m_texture));
}

void sw::RenderTexture::use()
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBufferId);
    glBindTexture(GL_TEXTURE_2D, m_texture.getId());
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_texture.getId(), 0);
    GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, drawBuffers);
}