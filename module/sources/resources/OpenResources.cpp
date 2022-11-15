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
#include "utils/Speech.hpp"
#include "exception/Error.hpp"
#include "OpenGLModule.hpp"

#include <iostream>
#include <memory>
#include <functional>

SW_GRAPH_MODULE_EXPORT sw::OpenResources::TexturesMap sw::OpenResources::m_ntext;
SW_GRAPH_MODULE_EXPORT sw::OpenResources::FontsMap sw::OpenResources::m_nfont;
SW_GRAPH_MODULE_EXPORT sw::OpenResources::AudioMap sw::OpenResources::m_naudio;
SW_GRAPH_MODULE_EXPORT sw::OpenResources::ModelMap sw::OpenResources::m_nmodel;
SW_GRAPH_MODULE_EXPORT sw::OpenResources::ShaderMap sw::OpenResources::m_nshader;
SW_GRAPH_MODULE_EXPORT sw::OpenResources::AnimationMap sw::OpenResources::m_nanimation;

sw::Ftlib fontlb;

sw::OpenResources::~OpenResources()
= default;

void sw::OpenResources::loadResources()
{
    sw::Speech::Info("Loading all resources...", "1227");
    try {
        loadTextures();
        loadShader();
        loadFonts();
        loadAudio();
        loadModels();
        loadAnimation();
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
    for ( auto &[name, text] : m_ntext)
        if (!text->isLoaded())
            text->upload();
    for (auto& [_, shader] : m_nshader)
        if (!shader->isLoaded())
            shader->createShader();
    for (auto& [_, model] : m_nmodel)
        if (!model->isLoaded())
            model->compileModel();
}

void sw::OpenResources::loadFonts()
{
    for (auto &[name, path] : m_nft) {
        if (m_nfont.contains(name))
            continue;
        m_nfont.emplace(name, std::make_shared<Font>(path));
    }
    if (m_nfont.empty())
        sw::Speech::Warning("No Font was loaded.", "3720");
}

void sw::OpenResources::loadTextures()
{
    for (auto &[name, path] : m_ntx) {
        if (m_ntext.contains(name))
            continue;
        m_ntext.emplace(name, std::make_shared<Texture>(path));
    }
    if (m_ntext.empty())
        sw::Speech::Warning("No Texture was loaded.", "3720");
}

void sw::OpenResources::loadAudio()
{
    for (auto &[name, path] : m_nau) {
        if (m_naudio.contains(name))
            continue;
        m_naudio.emplace(name, std::make_shared<Audio>(path));
    }
    if (m_naudio.empty())
        sw::Speech::Warning("No Audio was loaded.", "3720");
}

void sw::OpenResources::loadShader()
{
    for (auto &[name, path] : m_nsh) {
        if (m_nshader.contains(name))
            continue;
        std::string fragment = std::string(path);
        std::string vertex = std::string(path.replace(path.size() - 7, 1, "v"));
        m_nshader.emplace(name, std::make_shared<Shader>(fragment, vertex));
        path.replace(path.size() - 7, 1, "f");
    }
    if (m_nshader.empty())
        sw::Speech::Warning("No Shaders was loaded.", "3720");
}

void sw::OpenResources::loadAnimation()
{
    for (auto &[name, path] : m_nanim) {
        if (m_nanimation.contains(name))
            continue;
        m_nanimation.emplace(name, std::make_shared<sw::Animation>(path));
    }
    if (m_nanimation.empty())
        sw::Speech::Warning("No Animation loaded.", "3720");
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
    } else if (type == "Animation") {
        if (m_nanim.find(name) == m_nanim.end())
            m_nanim.emplace(name, path);
    }
}

void sw::OpenResources::loadModels()
{
    for (auto &[name, path] : m_nmd) {
        if (m_nmodel.contains(name))
            continue;
        m_nmodel.emplace(name, std::make_shared<Model>(path));
    }
    if (m_nmodel.empty())
        sw::Speech::Warning("No model was loaded.", "3720");
}

void sw::OpenResources::unloadResources()
{
    if (sw::OpenGLModule::m_sceneManager.m_nameNextActiveScene.empty()) {
        for(auto &[name, ptr] : m_ntext)
            ptr.reset();
        for(auto &[name, ptr] : m_naudio)
            ptr.reset();
        for(auto &[name, ptr] : m_nfont)
            ptr.reset();
        for(auto &[name, ptr] : m_nmodel)
            ptr.reset();
        for(auto &[name, ptr] : m_nshader)
            if (ptr.get())
                ptr.reset();
        m_ntext.clear();
        m_naudio.clear();
        m_nfont.clear();
        m_nmodel.clear();
        m_nshader.clear();
        return;
    }
    auto newScene = sw::OpenGLModule::m_sceneManager.getScene(sw::OpenGLModule::m_sceneManager.m_nameNextActiveScene);
    std::vector<std::string> element;

    for(auto &[name, ptr] : m_ntext) {
        if (newScene->resources.m_ntx.contains(name))
            continue;
        ptr.reset();
        element.emplace_back(name);
    }
    for (auto& name : element)
        m_ntext.erase(name);
    element.clear();
    for(auto &[name, ptr] : m_naudio) {
        if (newScene->resources.m_nau.contains(name))
            continue;
        ptr.reset();
        element.emplace_back(name);
    }
    for (auto& name : element)
        m_naudio.erase(name);
    element.clear();
    for(auto &[name, ptr] : m_nfont) {
        if (newScene->resources.m_nft.contains(name))
            continue;
        ptr.reset();
        element.emplace_back(name);
    }
    for (auto& name : element)
        m_nfont.erase(name);
    element.clear();
    for(auto &[name, ptr] : m_nmodel) {
        if (newScene->resources.m_nmd.contains(name))
            continue;
        ptr.reset();
        element.emplace_back(name);
    }
    for (auto& name : element)
        m_nmodel.erase(name);
    element.clear();
    for(auto &[name, ptr] : m_nshader) {
        if (newScene->resources.m_nsh.contains(name) || !ptr.get())
            continue;
        ptr.reset();
        element.emplace_back(name);
    }
    for (auto& name : element)
        m_nshader.erase(name);
    element.clear();
}

std::shared_ptr<sw::Texture> sw::OpenResources::TexturesMap::operator[](std::string name)
{
    if (!contains(name)) {
        sw::Speech::Warning(name + " texture not found", "");
        return (find("MissingTexture")->second);
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Texture> sw::OpenResources::TexturesMap::operator[](std::string name) const
{
    if (!contains(name)) {
        sw::Speech::Warning(name + " texture not found", "");
        return (find("MissingTexture")->second);
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Font> sw::OpenResources::FontsMap::operator[](std::string name)
{
    if (!contains(name)) {
        sw::Speech::Warning(name + " font not found", "");
        return (find("DefaultFont")->second);
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Font> sw::OpenResources::FontsMap::operator[](std::string name) const
{
    if (!contains(name)) {
        sw::Speech::Warning(name + " font not found", "");
        return (find("DefaultFont")->second);
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Audio> sw::OpenResources::AudioMap::operator[](std::string name)
{
    if (!contains(name)) {
        throw sw::Error(name + " audio not found", "");
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Audio> sw::OpenResources::AudioMap::operator[](std::string name) const
{
    if (!contains(name)) {
        throw sw::Error(name + " audio not found", "");
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Model> sw::OpenResources::ModelMap::operator[](std::string name)
{
    if (!contains(name)) {
        throw sw::Error(name + " model not found", "");
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Model> sw::OpenResources::ModelMap::operator[](std::string name) const
{
    if (!contains(name)) {
        throw sw::Error(name + " model not found", "");
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Shader> sw::OpenResources::ShaderMap::operator[](std::string name)
{
    if (!contains(name)) {
        sw::Speech::Warning(name + " shader not found", "");
        return (find("default")->second);
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Shader> sw::OpenResources::ShaderMap::operator[](std::string name) const
{
    if (!contains(name)) {
        sw::Speech::Warning(name + " shader not found", "");
        return (find("default")->second);
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Animation> sw::OpenResources::AnimationMap::operator[](std::string name)
{
    if (!contains(name)) {
        throw sw::Error(name + " model not found", "");
    }
    return (find(name)->second);
}

std::shared_ptr<sw::Animation> sw::OpenResources::AnimationMap::operator[](std::string name) const
{
    if (!contains(name)) {
        throw sw::Error(name + " model not found", "");
    }
    return (find(name)->second);
}