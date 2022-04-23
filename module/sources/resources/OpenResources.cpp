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
#include <filesystem>
#include <memory>
#include <exception>

sw::Texture::Texture(std::string path)
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
    } else
        std::cout << "Failed to load texture" << std::endl;
    stbi_image_free(data);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

SW_GRAPH_MODULE_EXPORT sw::OpenResources::TexturesMap sw::OpenResources::m_ntext;

SW_GRAPH_MODULE_EXPORT sw::OpenResources::FontsMap sw::OpenResources::m_nfont;

SW_GRAPH_MODULE_EXPORT sw::OpenResources::AudioMap sw::OpenResources::m_naudio;

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
        sw::Speech::Info("Resources loaded successfully!", "2227");
    } catch (sw::Error& error) {
        sw::Speech::Error(error.getMessage(), error.getCode());
    }
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

void sw::OpenResources::addNeededResource(const std::string& name, const std::string& path, const std::string& type)
{
    if (type == "Texture")
    {
        if (m_ntx.find(name) == m_ntx.end())
            m_ntx.emplace(name, path);
    } else if (type == "Font") {
        if (m_nft.find(name) == m_nft.end())
            m_nft.emplace(name, path);
    } else if (type == "Audio") {
        if (m_nau.find(name) == m_nau.end())
            m_nau.emplace(name, path);
    }

}

void sw::OpenResources::unloadResources()
{
    for(auto &[_, ptr] : m_ntext)
    {
        ptr.reset();
    }
    m_ntext.clear();
}
