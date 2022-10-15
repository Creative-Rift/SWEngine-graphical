#define STB_IMAGE_IMPLEMENTATION
#include "dependencies/resources/stb_image.h"

#include "resources/Texture.hpp"
#include "dependencies/glad/glad.h"
#include "utils/Speech.hpp"
#include "exception/Error.hpp"

#include <iostream>
#include <filesystem>
#include <memory>
#include <exception>

sw::Texture::Texture() :
wdt(1920),
hgt(1080),
m_loaded(false)
{
    try {
        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1920, 1080, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, 1920, 1080, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

sw::Texture::Texture(std::string path) :
        wdt(1920),
        hgt(1080),
        m_loaded(false)
{
    stbi_set_flip_vertically_on_load(true);
    m_img = stbi_load(path.c_str(), &wdt, &hgt, &nbc, dsc);

    if (!m_img)
    {
        sw::Speech::Warning("Failed to load texture: " + path);
        throw sw::Error("Failed to load texture: " + path);
    }
}

void sw::Texture::upload()
{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    if (m_img)
    {
        switch(nbc)
        {
            case 1:{
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, wdt, hgt, 0, GL_RED, GL_UNSIGNED_BYTE, getImage());
                GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_ONE };
                glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
                }break;
            case 2:{
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, wdt, hgt, 0, GL_RG, GL_UNSIGNED_BYTE, getImage());
                GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_GREEN };
                glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
                }break;
            case 3:{
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, wdt, hgt, 0, GL_RGB, GL_UNSIGNED_BYTE, getImage());
                }break;
            case 4:{
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, wdt, hgt, 0, GL_RGBA, GL_UNSIGNED_BYTE, getImage());
                }break;
            default:
            break;
        }
        stbi_image_free(m_img);
        glGenerateMipmap(GL_TEXTURE_2D);   
    } else {
        sw::Speech::Warning("Failed to upload texture");
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, 1920, 1080, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
        throw sw::Error("Failed to upload texture", "");
    }
    m_loaded = true;
}

bool sw::Texture::isLoaded() const
{
    return (m_loaded);
}