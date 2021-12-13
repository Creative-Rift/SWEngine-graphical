/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Data.hpp
*/

#ifndef __JSNP_DATA_HPP__
#define __JSNP_DATA_HPP__

#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Value.hpp"

template<class... Ts>
    struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts>
    overloaded(Ts...) -> overloaded<Ts...>;

namespace jsnp
{

    class Data
    {

        private:
            Object m_object;

            void clean_file(std::string& file);
            jsnp::Object take_object(const std::string& file, int& ctr);
            jsnp::Array take_array(const std::string& file, int& ctr);
            jsnp::Token take_token(const std::string& file, int& ctr);
            jsnp::Value take_value(const std::string& file, int& ctr);

        public:
            Data();
            Data(const std::string& filename);
            ~Data() = default;

            void parse(const std::string& filename);
            void save(const std::string& filename);

            Object& operator()() { return (m_object); };

            friend std::ostream& operator<<(std::ostream& os, Data& data);
            friend void operator>>(std::ifstream& os, Data& data);

    }; // class Data

    std::ostream& operator<<(std::ostream& os, jsnp::Data& data);
    void operator>>(std::ifstream& os, jsnp::Data& data);

    #include "Value.inl"
    #include "Array.inl"
    #include "Object.inl"
    #include "Data.inl"

} // namespace jsnp

#endif // __JSNP_DATA_HPP__