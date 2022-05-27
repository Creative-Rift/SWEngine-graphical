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

sw::RenderTexture::RenderTexture() :
m_name("RenderTexture"),
m_frameBufferId(0),
m_texture("hellow works")
{
    CreateRenderTexture();
}

sw::RenderTexture::RenderTexture(std::string name) :
m_name(name),
m_frameBufferId(0),
m_texture("")
{
    CreateRenderTexture();
}

void sw::RenderTexture::CreateRenderTexture()
{
    glGenFramebuffers(1, &m_frameBufferId);
    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBufferId);

    glBindTexture(GL_TEXTURE_2D, m_texture.getId());
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, 1920, 1080, 0,GL_RGB, GL_UNSIGNED_BYTE, nullptr);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_texture.getId(), 0);
    GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, drawBuffers);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        throw sw::Error("Error in RenderTexture", "");

    glBindFramebuffer(GL_FRAMEBUFFER, m_texture.getId());
    std::cout << "Render Texture created!" << std::endl;
    sw::OpenGLModule::sceneManager().getActiveScene().resources.m_ntext.emplace(m_name, std::make_shared<sw::Texture>(m_texture));
}