/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Resources.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP
#define SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP

#include "core/includes/resources/AResources.hpp"

#include "dependencies/glad/glad.h"
#include "dependencies/resources/stb_image.h"

#include <queue>
#include <memory>
#include <map>
#include <iostream>

namespace sw
{
    class Texture
    {
        public:

        Texture(): wdt(0), hgt(0), nbc(0), id(0)
        {};

        Texture(std::string path)
        {
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
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, wdt, hgt, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);
            } else
                std::cout << "Failed to load texture" << std::endl;
            stbi_image_free(data);
        };

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

    /*
    class Font
    {

    };
    */

    class OpenResources : public sw::AResources
    {
        private:
            std::map<std::string, std::string> m_ntx{};

            void loadTextures();
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
            OpenResources() = default;
            ~OpenResources();
            void loadResources() override;
            void unloadResources() override;
            void addNeededResource(const std::string& name, const std::string& path, const std::string& type) override;
    }; // class Resources

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP
