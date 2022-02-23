/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Resources.cpp
** Description: [CHANGE]
*/

#include "resources/OpenResources.hpp"
#include "SW/Engine.hpp"
#include "glad/glad.h"

#include <iostream>
#include <filesystem>

sw::OpenResources::~OpenResources()
{
}

void sw::OpenResources::loadResources()
{
    sw::Speech::Info("Loading all resources...", "1227");
    try {
//        loadTextures();
//        loadFonts();
        sw::Speech::Info("Resources loaded successfully!", "2227");
    } catch (sw::Error& error) {
        sw::Speech::Error(error.getMessage(), error.getCode());
    }
}


/*
void sw::OpenResources::addNeededResource(const std::string& name, const std::string& path, const std::string&)
{
    if (m_ntx.find(name) == m_ntx.end())
        m_ntx.emplace(name, path);
}

static void addResourcesOnReqScene(jsnp::Token& token)
{
    auto& key = token.first;
    auto& obj = token.second.value<jsnp::Object>();
    auto& path = obj["Path"].second.value<std::string>();
    auto& type = obj["Type"].second.value<std::string>();

    if (!std::ifstream(path))
        sw::Speech::Warning("sw::AddResourcesOnScene - Tag Path <" + path + "> is incorrect!", "3710");

    for (auto value : obj["Scene"].second.value<jsnp::Array>()) {
        sw::AScene& currentScene = sw::Engine::getScene(value.value<std::string>());
        currentScene.resources()->addNeededResource(key, path, type);
    }
}

void sw::OpenResources::loadResourcesFile(const std::string &path)
{
    std::ifstream in(path);
    jsnp::Data data(path);

    if (!in)
        sw::Speech::Error("sw::LoadResourcesFile - Unable to open file <" + path + ">", "4710");
    else
        for (auto token : data()) {
            auto& obj = token.second.value<jsnp::Object>();
            if (obj["Scene"].second.value<jsnp::Array>().size() == 0) {
                sw::Speech::Warning("sw::LoadResourcesFile - tag Scene not found!", "3710");
                continue;
            }
            addResourcesOnReqScene(token);
        }
}
*/

void sw::OpenResources::loadResourcesFile(const std::string &path)
{
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width, height, nrChannels;
    std::filesystem::path test("resources/test.jpg");
    unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
        std::cout << "Failed to load texture" << std::endl;
    stbi_image_free(data);
}

void sw::OpenResources::unloadResources()
{}
