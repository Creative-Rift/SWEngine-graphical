/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Reference.hpp
*/

#ifndef __REFERENCE_H__
#define __REFERENCE_H__

#include <optional>
#include <functional>

namespace sw
{

    template <typename T>
    class Reference
    {

        private:
            std::optional<std::reference_wrapper<T>> m_value;

        public:
            Reference();
            explicit Reference(T& value);
            ~Reference() = default;

            void emplace(T& newValue);
            [[nodiscard]] bool hasValue() const;
            T& value() const;

            T& operator=(T& newValue);
            T& operator*() const;

            bool operator==(const Reference<T>& other) const
            {
                return (m_value.value() == other.m_value.value());
            }

            bool operator==(const T& other) const
            {
                return (m_value.value() == other);
            }

    }; // class Reference

    #include "Reference.inl"

} // namespace sw

#endif // __REFERENCE_H__