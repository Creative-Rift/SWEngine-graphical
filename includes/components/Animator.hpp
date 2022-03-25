/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Animator.h
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_ANIMATOR_HPP
#define SWENGINE_OPENGLMODULE_ANIMATOR_HPP

#include "SW/Component.hpp"
#include "SW/Utils.hpp"

#include "OpenGLModule_Config.hpp"
#include "Sprite.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Animator : public sw::Component
    {
        public:
            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define the type of the animation
            ////////////////////////////////////////////////////////////////////////////
            enum AnimType {
                ANIM_SPRITE,
                ANIM_LINE
            };

        private:
            sw::Vector2u m_rect;
            sw::FloatRect m_displayRect;
            float m_lastFrame;
            int m_endFrame;
            float m_loopDelay;
            bool m_isPlaying;
            bool m_loop;
            float m_framePerSecond;
            AnimType m_type;

            Sprite& m_spr;
        public:

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default constructor
            ///
            /// \param engine
            /// \param entity
            ////////////////////////////////////////////////////////////////////////////
            explicit Animator(sw::Entity& entity);
            Animator() = delete;
            Animator(Animator const&) = delete;
            Animator(Animator&&) = delete;
            Animator& operator=(Animator const&) = delete;
            Animator& operator=(Animator&&) = delete;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Play your animation
            ////////////////////////////////////////////////////////////////////////////
            void play();

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Set pause on your animation
            ////////////////////////////////////////////////////////////////////////////
            void pause();

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Reset your animation (set on first frame)
            ////////////////////////////////////////////////////////////////////////////
            void reset();

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Return a bool if the animation is playing
            ///
            /// \return bool
            ////////////////////////////////////////////////////////////////////////////
            [[nodiscard]] bool isPlaying() const;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Set your animation in loop or not
            ///
            /// \param loop
            /// \param delay delay between two animation
            /// \return reference to your sprite animator
            ////////////////////////////////////////////////////////////////////////////
            Animator& setLoop(bool loop, float delay = 0);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief If you have one animation per line on your texture, you can define
            ///        the line you want here and the number of the frame (if you have
            ///        les frame than the length of your texture)
            ///
            /// \param engine
            /// \param line
            /// \param end number of frame in your animation
            /// \return reference to your sprite animator
            ////////////////////////////////////////////////////////////////////////////
            Animator& setLine(int line, int end = -1);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define the displayed rect on your texture
            ///
            /// \param engine
            /// \param rect
            /// \return reference to your sprite animator
            ////////////////////////////////////////////////////////////////////////////
            Animator& setRect(sw::Vector2u rect);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define the speed (number of frame per second) of your animation
            ///
            /// \param fps
            /// \return reference to your sprite
            ////////////////////////////////////////////////////////////////////////////
            Animator& setFPS(float fps);

            Animator& setAnimType(AnimType type);

            [[nodiscard]]const bool& isLoop() const;
            [[nodiscard]]const sw::Vector2u& getRect() const;
            [[nodiscard]]float& getLastFrame();
            [[nodiscard]]int& getEndFrame();
            [[nodiscard]]const float& getLoopDelay() const;
            [[nodiscard]]const float& getFPS() const;
            [[nodiscard]]FloatRect& getDisplayRect();
            [[nodiscard]]Sprite& getSprite();
            [[nodiscard]]AnimType& getAnimType();
            Animator& setPlaying(bool play);
            Animator& setDisplayRect(sw::FloatRect rect);

    }; // class Animator

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_ANIMATOR_HPP
