/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Resources.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP
#define SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP

#pragma warning(disable: 4251)

#include "AResources.hpp"

#include "dependencies/glad/glad.h"

#include "OpenGLModule_Config.hpp"
#include "resources/Font.hpp"
#include "resources/Audio.hpp"
#include "resources/Model.hpp"
#include "resources/Texture.hpp"

#include <queue>
#include <memory>
#include <map>
#include <iostream>


namespace sw
{
    class SW_GRAPH_MODULE_EXPORT OpenResources : public sw::AResources
    {
        private:
            std::map<std::string, std::string> m_ntx{};
            std::map<std::string, std::string> m_nft{};
            std::map<std::string, std::string> m_nau{};
            std::map<std::string, std::string> m_nmd{};
            std::map<std::string, std::string> m_nsh{};

            int index;

            void loadTextures();
            void loadFonts();
            void loadAudio();
            void loadModels();
            void loadShader();
            //std::priority_queue<std::unique_ptr<Font>> m_ft{}; font -> dev 2 final
            //std::priority_queue<std::unique_ptr<void>> m_sh; shaders -> dev 2/3
            //std::priority_queue<std::unique_ptr<void>> m_mt; materials -> dev 3
            // List des resources
        public:
            bool loaded;

            void compileResources();

            static class TexturesMap : public std::map<std::string, std::shared_ptr<Texture>>
            {
                public:
                    std::shared_ptr<Texture> operator[](std::string name);
                    std::shared_ptr<Texture> operator[](std::string name) const;
                    friend OpenResources;
            } m_ntext;

            static class FontsMap : public std::map<std::string, std::shared_ptr<Font>>
            {
                public:
                    std::shared_ptr<Font> operator[](std::string name);
                    std::shared_ptr<Font> operator[](std::string name) const;
                    friend OpenResources;
            } m_nfont;

            static class AudioMap : public std::map<std::string, std::shared_ptr<Audio>>
            {
                public:
                    std::shared_ptr<Audio> operator[](std::string name);
                    std::shared_ptr<Audio> operator[](std::string name) const;
                    friend OpenResources;
            } m_naudio;

            static class ModelMap : public std::map<std::string, std::shared_ptr<Model>>
            {
                public:
                    std::shared_ptr<Model> operator[](std::string name);
                    std::shared_ptr<Model> operator[](std::string name) const;
                    friend OpenResources;
            } m_nmodel;

            static class ShaderMap : public std::map<std::string, std::shared_ptr<Shader>>
            {
                public:
                    std::shared_ptr<Shader> operator[](std::string name);
                    std::shared_ptr<Shader> operator[](std::string name) const;
                    friend OpenResources;
            } m_nshader;

            OpenResources() : index(0), loaded(false) {};
            ~OpenResources();
            void loadResources() override;
            void loadOneResources();
            void unloadResources() override;
            void addNeededResource(const std::string& name, const std::string& path, const std::string& type) override;
    }; // class Resources

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP
