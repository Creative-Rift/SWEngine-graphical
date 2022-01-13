#pragma once

#include <cstdint>
#include <array>
#include <stdexcept>

namespace sw
{
    constexpr std::size_t MAX_BUFFER = 32;

    class Input_buffer //currently fix typed buffer, TODO template buffer
    {
        public:
            Input_buffer();
            ~Input_buffer();

            void clear();
            void push(int a[2]);
            std::array<std::pair<int, int>, sw::MAX_BUFFER> get() const;
        private:
            std::size_t m_index;
            std::array<std::pair<int, int>, sw::MAX_BUFFER> m_input_buffer;
    };

    sw::Input_buffer::Input_buffer(): m_index(0)
    {
        m_input_buffer.fill({-1,-1});
    }

    sw::Input_buffer::~Input_buffer()
    {
    }

    void sw::Input_buffer::clear()
    {
        m_index = 0;
        m_input_buffer.fill({-1,-1});
    }

    void sw::Input_buffer::push(int append[2])
    {
        if (!append)
            throw(std::invalid_argument("null pointer pushed in buffer"));
        m_input_buffer[m_index] = {append[0], append[1]};
        m_index = (m_index >= MAX_BUFFER) ? 0 : ++m_index;
    }

    std::array<std::pair<int, int>, sw::MAX_BUFFER> sw::Input_buffer::get() const
    {
        return m_input_buffer;
    }
}
