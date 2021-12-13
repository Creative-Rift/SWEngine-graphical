/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Value.hpp
*/

#ifndef __JSNP_VALUE_HPP__
#define __JSNP_VALUE_HPP__

#include <string>
#include <variant>

#include "Object.hpp"
#include "Array.hpp"

namespace jsnp
{

    class Value
    {

        private:
            std::variant<
                Null,
                int,
                bool,
                std::string,
                Array,
                Object
            > m_value;
            Type m_type;

        public:
            Value();
            Value(int number);
            Value(bool boolean);
            Value(std::string str);
            Value(Array array);
            Value(Object object);
            ~Value() = default;

            const Type& type() { return (m_type); }
            template <typename T>
            T& value();

            friend std::ostream& operator<<(std::ostream& os, Value& data);

    }; // class Value

    std::ostream& operator<<(std::ostream& os, jsnp::Value& value);

} // namespace jsnp

#endif // __JSNP_VALUE_HPP__