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

namespace sw
{
    class OpenResources : public sw::AResources
    {
        private:
            // List des resources
        public:
            OpenResources() = default;
            ~OpenResources();
            void loadResources() override;
            void unloadResources() override;
            void loadResourcesFile(const std::string &path) override;
    }; // class Resources

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_OPENRESOURCES_HPP
