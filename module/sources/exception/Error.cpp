/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Error.cpp
 *
 * Description:
 * Error function implementation
 */

#include "Error.hpp"

std::ostream &operator<<(std::ostream &s, const sw::Error &error)
{
    s << std::string("[") << error.getCode() << std::string("]: ") << error.getMessage();
    return (s);
}