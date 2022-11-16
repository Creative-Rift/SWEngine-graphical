#include "resources/Font.hpp"

sw::Font::Font(std::string font)
{
    if (FT_New_Face(fontlb.ft, font.c_str(), 0, &face))
    {
        std::cerr << "Failed to load font" << std::endl;  
        return;
    }
    FT_Set_Pixel_Sizes(face, 0, 48);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    FT_UInt idx;
    FT_ULong character = FT_Get_First_Char(face, &idx);

    while (true)
    {
        // load character glyph 
        if (FT_Load_Char(face, character, FT_LOAD_RENDER))
        {
            std::cerr << "Failed to load Glyph" << std::endl;
            continue;
        }
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        Character chr = {
            texture, 
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            face->glyph->advance.x
        };
        characters.insert(std::pair<FT_ULong, Character>(character, chr));
        
        character = FT_Get_Next_Char(face, character, &idx);
        if (!idx)
            break;
    }
}

const std::map<FT_ULong, sw::Font::Character> sw::Font::getCharacters() const
{
    return (characters);
}

sw::Font::~Font()
{
    if (fontlb.load)
        FT_Done_Face(face);
}