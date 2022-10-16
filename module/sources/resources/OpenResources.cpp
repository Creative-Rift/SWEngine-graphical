/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Resources.cpp
** Description: [CHANGE]
*/

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
#include <algorithm>
#include <functional>

SW_GRAPH_MODULE_EXPORT sw::OpenResources::TexturesMap sw::OpenResources::m_ntext;
SW_GRAPH_MODULE_EXPORT sw::OpenResources::FontsMap sw::OpenResources::m_nfont;
SW_GRAPH_MODULE_EXPORT sw::OpenResources::AudioMap sw::OpenResources::m_naudio;
SW_GRAPH_MODULE_EXPORT sw::OpenResources::ModelMap sw::OpenResources::m_nmodel;

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
    for ( auto &[_, text] : m_ntext)
        text->upload(false);
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

void sw::OpenResources::loadModels()
{
    for (auto &[name, path] : m_nmd)
        m_nmodel.emplace(name, std::make_shared<Model>(path));
    if (m_nmodel.empty())
        sw::Speech::Warning("No model was loaded.", "3720");
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
    }

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
