/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** data_type.hpp
*/

#ifndef __JSNP_DATA_TYPE_HPP__
#define __JSNP_DATA_TYPE_HPP__

#include <string>
#include <utility>

namespace jsnp
{

    class Value;

    using Token = std::pair<std::string, Value>;

    std::ostream& operator<<(std::ostream& os, jsnp::Token& token);

    enum Type
    {
        NULL_PTR,
        NUMBER,
        BOOL,
        STRING,
        ARRAY,
        OBJECT
    };

    struct Null {};

} // namespace jsnp

#endif // __JSNP_DATA_TYPE_HPP__