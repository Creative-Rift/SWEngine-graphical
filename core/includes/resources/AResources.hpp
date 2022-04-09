/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AResources.hpp
 *
 * Description:
 * Abstract class of Resources
 * Graphics Modules use Resources differently.
 * So when you develop a new Graphic Module you need to use this base class
 * to encapsulate the graphics resources of the library you use.
 * We provide you a base class for Texture, Sound, Music, Font and Model.
 */

#ifndef __SHIPWRECK_CORE_ARESOURCES_HPP__
#define __SHIPWRECK_CORE_ARESOURCES_HPP__

#include <vector>
#include <string>

namespace sw
{

    class AResources {
        public:
            std::vector<std::string> m_neededResource;

            virtual void loadResources() = 0;
            virtual void unloadResources() = 0;
            virtual void addNeededResource(const std::string& name, const std::string& path, const std::string& type) = 0;
    };

    class ITexture {
        public:
            virtual ~ITexture() = default;
    };

    class ISound {
        public:
            virtual ~ISound() = default;
    };

    class IFont {
        public:
            virtual ~IFont() = default;
    };

    class IMusic {
        public:
            virtual ~IMusic() = default;
    };

    class IModel {
        public:
            virtual ~IModel() = default;
    };

} // namespace sw

#endif // __SHIPWRECK_CORE_ARESOURCES_HPP__
