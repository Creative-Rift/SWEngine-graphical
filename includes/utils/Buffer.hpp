#pragma once

#include "../OpenGLModule.hpp"

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

    std::string getEventType(const sw::Type &evt)
    {
        switch(evt)
        {
            case sw::Type::None:
                return ("None");
            case sw::Type::Mouse:
                return ("Mouse button");
            case sw::Type::Position:
                return ("Mouse position");
            case sw::Type::Keyboard:
                return ("Keyboard");
            case sw::Type::Scroll:
                return ("Scroll");
        }
        return "None";
    };

    std::string getEventAction(const sw::Type &evt, const int &act)
    {
        switch(evt)
        {
            default:
                return ("None");
            case sw::Type::Mouse:
                switch(act)
                {
                    case GLFW_PRESS:
                        return "Pressed";
                    case GLFW_RELEASE:
                        return "Released";
                }
            case sw::Type::Keyboard:
                switch(act)
                {
                    case GLFW_PRESS:
                        return "Pressed";
                    case GLFW_RELEASE:
                        return "Released";
                    case GLFW_REPEAT:
                        return "Down";
                    case (-1):
                        return "Up";
                }
        }
        return "None";
    }

    class EventInfo
    {
        public:
            sw::Type m_t;
            std::pair<int,int> m_ki;
            std::pair<double,double> m_os;

            EventInfo(): m_t(sw::Type::None), m_ki{}, m_os{}
            {
            };

            EventInfo(const sw::EventInfo &evt): m_t(evt.m_t), m_ki(evt.m_ki), m_os(evt.m_os)
            {
            };

            EventInfo(sw::Type& evt, std::pair<int,int>& ikv, std::pair<double,double>& mwi): m_t(evt), m_ki{ikv}, m_os{mwi}
            {
            };

            EventInfo& operator=(const EventInfo& evt)
            {
                m_t = evt.m_t;
                m_ki = evt.m_ki;
                m_os = evt.m_os;

                return *this;
            }

            ~EventInfo() = default;
    };

    void dumpEvent(const sw::EventInfo* jaj)
    {
        for (size_t i = 0 ; i < sw::MAX_BUFFER; ++i)
        {
            switch(jaj[i].m_t)
            {
                case sw::Type::None:
                    break;
                case sw::Type::Mouse:
                    std::cout << "Event type is " + sw::getEventType(jaj[i].m_t) << " action is: " + sw::getEventAction(jaj[i].m_t, jaj[i].m_ki.second) << std::endl;
                    break;
                case sw::Type::Position:
                    std::cout << "Event type is " + sw::getEventType(jaj[i].m_t) << " positions are: " << jaj[i].m_os.first << "," << jaj[i].m_os.second << std::endl;
                    break;
                case sw::Type::Keyboard:
                    std::cout << "Event type is " + sw::getEventType(jaj[i].m_t) << " action is: " + sw::getEventAction(jaj[i].m_t, jaj[i].m_ki.second) << std::endl;
                    break;
                case sw::Type::Scroll:
                    std::cout << "Event type is " + sw::getEventType(jaj[i].m_t) << " scroll values are: " << jaj[i].m_os.first << "," << jaj[i].m_os.second << std::endl;
                    break;
            }
        }
    }

    class Input_buffer //currently fix typed buffer, TODO template buffer
    {
        public:
            Input_buffer();
            ~Input_buffer();

            void clear();
            void push(sw::Type& evt, std::pair<int,int>& ikf, std::pair<double,double>& mwi);
            const EventInfo* get() const;
            const std::size_t getIdx() const { return m_index; };
        private:
            std::size_t m_index;
            std::pair<double, double> m_pos;
            //std::array<EventInfo, sw::MAX_BUFFER> m_input_buffer{};
            EventInfo m_input[sw::MAX_BUFFER]{};
    };

    sw::Input_buffer::Input_buffer(): m_index(0), m_pos{0,0}
    {
        sw::Type evt = sw::Type::None;
        std::pair<int,int> ikv{-1,-1};
        std::pair<double,double> mwi{};
        sw::EventInfo tmp(evt, ikv, mwi);

        for (size_t i = 0; i < sw::MAX_BUFFER; ++i)
            m_input[i] = std::move(tmp);
        //m_input_buffer.fill(tmp);
    }

    sw::Input_buffer::~Input_buffer()
    {
    }

    void sw::Input_buffer::clear()
    {
        sw::Type evt = sw::Type::None;
        std::pair<int,int> ikv{};
        std::pair<double,double> mwi{};
        sw::EventInfo tmp(evt, ikv, mwi);

        m_index = 0;
        for (size_t i = 0; i < sw::MAX_BUFFER; ++i)
            m_input[i] = std::move(tmp);
        //m_input_buffer.fill(tmp);
    }

    void sw::Input_buffer::push(sw::Type& evt, std::pair<int,int>& ikv, std::pair<double,double>& mwi)
    {
        //m_input_buffer[m_index] = {ikv[0], ikv[1]};
        if (evt == sw::Position)
            m_pos = mwi;
        m_input[m_index] = {evt, ikv, mwi};
        m_index = (m_index >= MAX_BUFFER) ? 0 : ++m_index;
    }

    const EventInfo* sw::Input_buffer::get() const
    {
        return m_input;
    }
}
