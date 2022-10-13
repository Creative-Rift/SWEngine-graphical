/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Resources.cpp
** Description: [CHANGE]
*/

#define STB_IMAGE_IMPLEMENTATION
#include "dependencies/resources/stb_image.h"

#include "ft2build.h"
#include FT_FREETYPE_H"freetype/freetype/freetype.h"

#include "resources/Font.hpp"

#include "resources/OpenResources.hpp"
#include "dependencies/glad/glad.h"
#include "utils/Speech.hpp"
#include "exception/Error.hpp"

#include <iostream>
#include <memory>
#include <exception>

sw::Texture::Texture() :
wdt(1920),
hgt(1080)
{
    try {
        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1920, 1080, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

sw::Texture::Texture(std::string path) :
wdt(1920),
hgt(1080)
{
    try{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(path.c_str(), &wdt, &hgt, &nbc, dsc);

    if (data)
    {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        switch(nbc)
        {
            case 1:{
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, wdt, hgt, 0, GL_RED, GL_UNSIGNED_BYTE, data);
                GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_ONE };
                glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
                }break;
            case 2:{
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, wdt, hgt, 0, GL_RG, GL_UNSIGNED_BYTE, data);
                GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_GREEN };
                glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
                }break;
            case 3:{
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, wdt, hgt, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                }break;
            case 4:{
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, wdt, hgt, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
                }break;
            default:
            break;
        }
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
    } else {
        sw::Speech::Warning("Failed to load texture: " + path);
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, 1920, 1080, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    }
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

sw::Ftlib fontlb;

sw::OpenResources::~OpenResources()
= default;

void sw::OpenResources::loadResources()
{
    sw::Speech::Info("Loading all resources...", "1227");
    try {
        loadTextures();
        loadFonts();
        loadAudio();
        loadModels();
        loadShader();
        sw::Speech::Info("Resources loaded successfully!", "2227");
    } catch (sw::Error& error) {
        sw::Speech::Error(error.getMessage(), error.getCode());
    }
}

void sw::OpenResources::loadOneResources()
{
    sw::Speech::Info("Loading all resources...", "1227");
    try {
        //Texture
        if (m_ntext.size() != m_ntx.size()) {
            std::cout << m_ntx.size() << " Texture to load" << std::endl;
            auto texture = m_ntx.begin();
            for (int i = 0; i < index; i++)
                texture++;
            if (texture != m_ntx.end()) {
                std::cout << "Loading... " << texture->first << std::endl;
                m_ntext.emplace(texture->first, std::make_shared<Texture>(texture->second));
                index = (index + 1 >= m_nmd.size()) ? 0 : index + 1;
                return;
            }
        }
        //model
        std::cout << m_nmd.size() << " Model to load " << index << std::endl;
        if (m_nmodel.size() != m_nmd.size()) {
            auto model = m_nmd.begin();
            for (int i = 0; i < index; i++)
                model++;
            if (model != m_nmd.end()) {
                std::cout << "Loading... " << model->first << std::endl;
                m_nmodel.emplace(model->first, std::make_shared<Model>(model->second));
                index = (index + 1 >= m_nmd.size()) ? 0 : index + 1;
                return;
            }
        }
        loaded = true;
        sw::Speech::Info("Resources loaded successfully!", "2227");
    } catch (sw::Error& error) {
        sw::Speech::Error(error.getMessage(), error.getCode());
    }
}

void sw::OpenResources::compileResources()
{
    for (auto& [_, model] : m_nmodel)
        model->compileModel();
    for (auto& [_, shader] : m_nshader)
        shader->createShader();
}

void sw::OpenResources::loadFonts()
{
    for (auto &[name, path] : m_nft) {
        m_nfont.emplace(name, std::make_shared<Font>(path));
    }
    if (m_nfont.empty())
        sw::Speech::Warning("No Font was loaded.", "3720");
}

void sw::OpenResources::loadTextures()
{
    for (auto &[name, path] : m_ntx) {
        m_ntext.emplace(name, std::make_shared<Texture>(path));
    }
    if (m_ntext.empty())
        sw::Speech::Warning("No Texture was loaded.", "3720");
}

void sw::OpenResources::loadAudio()
{
    for (auto &[name, path] : m_nau) {
        m_naudio.emplace(name, std::make_shared<Audio>(path));
    }
    if (m_naudio.empty())
        sw::Speech::Warning("No Audio was loaded.", "3720");
}

void sw::OpenResources::loadShader()
{
    for (auto &[name, path] : m_nsh)
        m_nshader.emplace(name, std::make_shared<Shader>(path + ".fs.glsl", path + ".vs.glsl"));
    if (m_nshader.empty())
        sw::Speech::Warning("No Shaders was loaded.", "3720");
}

void sw::OpenResources::addNeededResource(const std::string& name, const std::string& path, const std::string& type)
{
    if (type == "Texture") {
        if (m_ntx.find(name) == m_ntx.end())
            m_ntx.emplace(name, path);
    } else if (type == "Font") {
        if (m_nft.find(name) == m_nft.end())
            m_nft.emplace(name, path);
    } else if (type == "Audio") {
        if (m_nau.find(name) == m_nau.end())
            m_nau.emplace(name, path);
    } else if (type == "Model") {
        if (m_nmd.find(name) == m_nmd.end())
            m_nmd.emplace(name, path);
    } else if (type == "Shader") {
        if (m_nsh.find(name) == m_nsh.end())
            m_nsh.emplace(name, path);
    }

}

void sw::OpenResources::loadModels()
{
    for (auto &[name, path] : m_nmd)
        m_nmodel.emplace(name, std::make_shared<Model>(path));
    if (m_nmodel.empty())
        sw::Speech::Warning("No model was loaded.", "3720");
}

void sw::OpenResources::unloadResources()
{
    for(auto &[_, ptr] : m_ntext)
        ptr.reset();
    for(auto &[_, ptr] : m_naudio)
        ptr.reset();
    for(auto &[_, ptr] : m_nfont)
        ptr.reset();
    for(auto &[_, ptr] : m_nmodel)
        ptr.reset();
    m_ntext.clear();
    m_ntx.clear();
    m_naudio.clear();
    m_nau.clear();
    m_nfont.clear();
    m_nft.clear();
    m_nmodel.clear();
    m_nmd.clear();
}
