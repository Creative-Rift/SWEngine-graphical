#pragma once

inline sw::Input_buffer::Input_buffer(): m_index(0), m_pos{0,0}
{
    sw::Type evt = sw::Type::None;
    std::pair<int,int> ikv{-1,-1};
    std::pair<double,double> mwi{};
    sw::MouseEvent tmp(evt, ikv, mwi);

    for (size_t i = 0; i < sw::MAX_BUFFER; ++i)
        m_input[i] = std::move(tmp);
}

inline sw::Input_buffer::~Input_buffer()
{
}

inline void sw::Input_buffer::clear()
{
    sw::Type evt = sw::Type::None;
    std::pair<int,int> ikv{};
    std::pair<double,double> mwi{};
    sw::MouseEvent tmp(evt, ikv, mwi);

    m_index = 0;
    for (size_t i = 0; i < sw::MAX_BUFFER; ++i)
        m_input[i] = std::move(tmp);
}

inline void sw::Input_buffer::push(sw::Type& evt, std::pair<int,int>& ikv, std::pair<double,double>& mwi)
{
    if (evt == sw::Position)
        m_pos = mwi;
    m_input[m_index] = {evt, ikv, mwi};
    m_index = (m_index >= MAX_BUFFER) ? 0 : ++m_index;
}

inline const MouseEvent* sw::Input_buffer::get() const
{
    return m_input;
}