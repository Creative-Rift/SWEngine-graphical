/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Token.inl
*/

template <>
inline int& jsnp::Token::value()
{ return (std::get<int>(second)); }

template <>
inline bool& jsnp::Token::value()
{ return (std::get<bool>(second)); }

template <>
inline jsnp::Null& jsnp::Token::value()
{ return (std::get<jsnp::Null>(second)); }

template <>
inline std::string& jsnp::Token::value()
{ return (std::get<std::string>(second)); }

template <>
inline jsnp::Array& jsnp::Token::value()
{ return (std::get<jsnp::Array>(second)); }

template <>
inline jsnp::Object& jsnp::Token::value()
{ return (std::get<jsnp::Object>(second)); }