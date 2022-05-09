/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SpriteManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_SPRITEMANAGER_HPP
#define SWENGINE_OPENGLMODULE_SPRITEMANAGER_HPP

#include "base/AManager.hpp"
#include "components/Sprite.hpp"
#include "OpenGLModule_Config.hpp"

namespace sw
{
    /// \brief A Sprite Manager update all data from the Sprite component \n
    /// He change the displayed rect, Flip...
    class SW_GRAPH_MODULE_EXPORT SpriteManager : public sw::AManager<Sprite>
    {
        private:

            /// \brief This function update the Vertex of the sprite anf flip them is needed
            ///
            /// \param sprite Get a reference to the Sprite
            static void updateInvert(sw::Sprite& sprite);

            /// \brief This function update all vertex according the parameters of the Sprite \n
            /// He change the Vertex texture coordinate according to the rect
            ///
            /// \param sprite Get a reference to the Sprite
            static void defineRect(sw::Sprite& sprite);


        public:
            [[nodiscard]] YAML::Node save() const override;

            /// \brief Default constructor of the AManager class
            using sw::AManager<Sprite>::AManager;

            /// \brief Default destructor
            ~SpriteManager() override = default;

            /// \brief This function is called one time per frame and update all component \n
            /// stored according their data
            void onUpdate() override;

            void onLoad(YAML::Node& node) override;

    }; // class SpriteManager

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_SPRITEMANAGER_HPP
