/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Resources.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP
#define SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP

#include "stb_image.h"
#include "core/includes/resources/AResources.hpp"

#include <queue>
#include <memory>
#include <map>

namespace sw
{
    class Texture
    {
        public:

        Texture(): wdt(0), hgt(0), nbc(0), img(nullptr)
        {};

        /*
        Texture(std::string &path)
        {
            
        };*/

        ~Texture()
        {
            if (img != nullptr)
                stbi_image_free(img);
        }

        private:
            int wdt;
            int hgt;
            int nbc;
            int dsc = 0;
            stbi_uc *img;
    };

    /*
    class Font
    {

    };
    */

    class OpenResources : public sw::AResources
    {
        private:
            //std::priority_queue<std::shared_ptr<Texture>> m_tx{};
            std::map<std::string, std::string> m_ntx{};

            //std::priority_queue<std::unique_ptr<Font>> m_ft{}; font -> dev 2 final
            //std::priority_queue<std::unique_ptr<void>> m_sh; shaders -> dev 2/3
            //std::priority_queue<std::unique_ptr<void>> m_mt; materials -> dev 3
            // List des resources
        public:
        /*
            static class TexturesMap : private std::map<std::string, std::shared_ptr<Texture>>
            {
                public:
                    using std::map<std::string, std::shared_ptr<Texture>>::operator[];
                    friend OpenResources;
            } m_ntext;*/
            OpenResources() = default;
            ~OpenResources();
            void loadResources() override;
            void unloadResources() override;
            void loadResourcesFile(const std::string &path) override;
    }; // class Resources

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP
