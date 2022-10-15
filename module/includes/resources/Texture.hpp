#pragma once

#include "AResources.hpp"

#include "dependencies/glad/glad.h"
#include "OpenGLModule_Config.hpp"

#include <queue>
#include <memory>
#include <map>
#include <iostream>

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Texture
    {
        public:

        enum class Filter {
            NEAR = 0,
            LINEAR = 1
        };
        Texture();
        Texture(std::string path);
        //Texture(std::string path,Filter filter);
        
        ~Texture()
        {}

        const unsigned int getId() const { return id; };
        const int getWidth() const { return wdt;};
        const int getHeight() const { return hgt;};
        const int getChannels() const { return nbc;};
        const unsigned char* getImage() const { return m_img; };
        void upload();
        bool isLoaded() const;
        //void resize();
        std::string type;
    private:
            int wdt;
            int hgt;
            int nbc;
            unsigned int id;
            int dsc = 0;
            unsigned char *m_img;
            bool m_loaded;
    };
} // namespace sw
