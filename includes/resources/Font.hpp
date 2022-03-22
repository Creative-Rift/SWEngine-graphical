#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include "dependencies/glad/glad.h"
#include "dependencies/glm/glm.hpp"

#include <map>
#include <string>
#include <iostream>

namespace sw
{
    class Font
    {
    public:
        struct Character {
            unsigned int TextureID;
            glm::ivec2 Size;
            glm::ivec2 Bearing;
            FT_Pos Advance;
        };
        Font(std::string);
        const std::map<FT_ULong, Character> getCharacters() const;
        ~Font();
    private:
        FT_Face face;
        std::map<FT_ULong, Character> characters;
    };
    
    class Ftlib
    {
    public:
        FT_Library ft;
        bool load;
        Ftlib()
        {
            if (FT_Init_FreeType(&ft))
            {
                std::cerr << "Could not init FreeType Library" << std::endl;
                load = false;
                return;
            } else
                std::cout << "FreeType Library loaded" << std::endl;
            load = true;
        };

        ~Ftlib() 
        {
            load = false;
            FT_Done_FreeType(ft);
        };
    };
}

extern sw::Ftlib fontlb;