#pragma once

#include "dependencies/glad/glad.h"
#include "GLFW/glfw3.h"

#include <cstdint>
#include <array>
#include <stdexcept>
#include <string>
#include <iostream>

namespace sw
{
    constexpr std::size_t MAX_BUFFER = 32;

    enum Type {
        None,
        Keyboard,
        Mouse,
        Position,
        Scroll
    };

    ////////////////////////////////////////////////////////////
    /// @brief Return a printable string of the event type
    ///
    /// @param sw::Type&
    /// 
    /// @return std::string
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    std::string getEventType(const sw::Type &evt);

    ////////////////////////////////////////////////////////////
    /// @brief Return a printable string of the event action
    ///
    /// @param sw::Type &, const int &
    /// 
    /// @return std::string
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    std::string getEventAction(const sw::Type &evt, const int &act);

    class MouseEvent
    {
        public:
            sw::Type m_t;
            std::pair<int,int> m_ki;
            std::pair<double,double> m_os;

            MouseEvent(): m_t(sw::Type::None), m_ki{}, m_os{}
            {
            }

            MouseEvent(const sw::MouseEvent &evt): m_t(evt.m_t), m_ki(evt.m_ki), m_os(evt.m_os)
            {
            }

            MouseEvent(sw::Type& evt, std::pair<int,int>& ikv, std::pair<double,double>& mwi): m_t(evt), m_ki{ikv}, m_os{mwi}
            {
            }

            MouseEvent& operator=(const MouseEvent& evt)
            {
                m_t = evt.m_t;
                m_ki = evt.m_ki;
                m_os = evt.m_os;

                return *this;
            }

            ~MouseEvent() = default;
    };

    ////////////////////////////////////////////////////////////
    /// @brief Print the entirety of the event buffer
    ///
    /// @param sw::EventInfo*
    /// 
    /// @return void
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    void dumpEvent(const sw::EventInfo* jaj);

#include "Buffer_utility.inl"

    class Input_buffer //currently fix typed buffer, TODO template buffer
    {
        public:
            Input_buffer();
            ~Input_buffer();

            void clear();
            void push(sw::Type& evt, std::pair<int,int>& ikf, std::pair<double,double>& mwi);
            const MouseEvent* get() const;
            const std::size_t getIdx() const { return m_index; }
        private:
            std::size_t m_index;
            std::pair<double, double> m_pos;
            MouseEvent m_input[sw::MAX_BUFFER]{};
    };

#include "Buffer.inl"
}
