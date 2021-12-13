/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Array.hpp
*/

#ifndef __JSNP_ARRAY_HPP__
#define __JSNP_ARRAY_HPP__

#include <list>
#include <iostream>

namespace jsnp
{

    class Value;

    class Array
    {
        private:
            std::list<Value> m_values;

        public:
            Array() = default;
            ~Array() = default;

            std::list<Value>::iterator begin() { return (m_values.begin()); }
            std::list<Value>::iterator end() { return (m_values.end()); }

            template <typename T>
            T& emplace_front(T value);
            template <typename T>
            T& emplace_at(T value, unsigned index);
            template <typename T>
            T& emplace_back(T value);

            Value& insert_front(Value& token);
            Value& insert_at(Value& token, unsigned index);
            Value& insert_back(Value& token);

            void remove(int index);
            unsigned size() const { return (m_values.size()); }
            Value& operator[](unsigned index);

            friend std::ostream& operator<<(std::ostream& os, Array& data);

    }; // class Array

    std::ostream& operator<<(std::ostream& os, jsnp::Array& array);

} // namespace jsnp

#endif // __JSNP_ARRAY_HPP__