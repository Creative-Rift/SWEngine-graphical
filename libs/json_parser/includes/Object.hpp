/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Object.hpp
*/

#ifndef __JSNP_OBJECT_HPP__
#define __JSNP_OBJECT_HPP__

#include <list>

#include "data_type.hpp"

namespace jsnp
{

    class Object
    {

        private:
            std::list<Token> m_tokens;

        public:
            Object() = default;
            ~Object() = default;

            std::list<Token>::iterator begin() noexcept { return (m_tokens.begin()); }
            std::list<Token>::iterator end() noexcept { return (m_tokens.end()); }

            template <typename T>
            Token& emplace_front(std::string key, T value);
            template <typename T>
            Token& emplace_at(std::string key, T value, unsigned index);
            template <typename T>
            Token& emplace_back(std::string key, T value);
            Token& insert_front(Token& token);
            Token& insert_at(Token& token, unsigned index);
            Token& insert_back(Token& token);

            void remove(const std::string& key);
            unsigned size() const { return (m_tokens.size()); }
            Token& operator[](const std::string& key);

            friend std::ostream& operator<<(std::ostream& os, Object& data);

    }; // class Object

    std::ostream& operator<<(std::ostream& os, jsnp::Object& object);

} // namespace jsnp

#endif // __JSNP_OBJECT_HPP__