/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Value.inl
*/

inline jsnp::Value::Value()
    :   m_value(jsnp::Null()),
        m_type(NULL_PTR)
{}

inline jsnp::Value::Value(int number)
    :   m_value(number),
        m_type(NUMBER)
{}

inline jsnp::Value::Value(bool boolean)
    :   m_value(boolean),
        m_type(BOOL)
{}

inline jsnp::Value::Value(std::string str)
    :   m_value(str),
        m_type(STRING)
{}

inline jsnp::Value::Value(Array array)
    :   m_value(array),
        m_type(ARRAY)
{}

inline jsnp::Value::Value(Object object)
    :   m_value(object),
        m_type(OBJECT)

{}

template <>
inline int& jsnp::Value::value()
{ return (std::get<int>(m_value)); }

template <>
inline bool& jsnp::Value::value()
{ return (std::get<bool>(m_value)); }

template <>
inline jsnp::Null& jsnp::Value::value()
{ return (std::get<jsnp::Null>(m_value)); }

template <>
inline std::string& jsnp::Value::value()
{ return (std::get<std::string>(m_value)); }

template <>
inline jsnp::Array& jsnp::Value::value()
{ return (std::get<jsnp::Array>(m_value)); }

template <>
inline jsnp::Object& jsnp::Value::value()
{ return (std::get<jsnp::Object>(m_value)); }