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

#include <queue>
#include <memory>
#include <map>
#include <iostream>


namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Texture
    {
        public:

        Texture(): wdt(0), hgt(0), nbc(0), id(0)
        {};

        Texture(std::string path);

        ~Texture()
        {}

        const unsigned int getId() const { return id; };
        const int getWidth() const { return wdt;};
        const int getHeight() const { return hgt;};
        const int getChannels() const { return nbc;};
        private:
            int wdt;
            int hgt;
            int nbc;
            unsigned int id;
            int dsc = 0;
    };

    class SW_GRAPH_MODULE_EXPORT OpenResources : public sw::AResources
    {
        private:
            std::map<std::string, std::string> m_ntx{};
            std::map<std::string, std::string> m_nft{};
            std::map<std::string, std::string> m_nau{};

            void loadTextures();
            void loadFonts();
            void loadAudio();
            //std::priority_queue<std::unique_ptr<Font>> m_ft{}; font -> dev 2 final
            //std::priority_queue<std::unique_ptr<void>> m_sh; shaders -> dev 2/3
            //std::priority_queue<std::unique_ptr<void>> m_mt; materials -> dev 3
            // List des resources
        public:
            static class TexturesMap : private std::map<std::string, std::shared_ptr<Texture>>
            {
                public:
                    using std::map<std::string, std::shared_ptr<Texture>>::operator[];
                    friend OpenResources;
            } m_ntext;

            static class FontsMap : private std::map<std::string, std::shared_ptr<Font>>
            {
                public:
                    using std::map<std::string, std::shared_ptr<Font>>::operator[];
                    friend OpenResources;
            } m_nfont;

            static class AudioMap : private std::map<std::string, std::shared_ptr<Audio>>
            {
                public:
                    using std::map<std::string, std::shared_ptr<Audio>>::operator[];
                    friend OpenResources;
            } m_naudio;
            OpenResources() = default;
            ~OpenResources();
            void loadResources() override;
            void unloadResources() override;
            void addNeededResource(const std::string& name, const std::string& path, const std::string& type) override;
    }; // class Resources

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP
