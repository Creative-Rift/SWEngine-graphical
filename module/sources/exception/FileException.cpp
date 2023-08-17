/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2023
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/

#include "exception/FileException.hpp"

#include <utility>

sw::FileException::FileException(std::string reason) : std::exception(),
                                                        m_what(std::move(reason))
{}

const char *sw::FileException::what() const noexcept
{
    return (m_what.c_str());
}