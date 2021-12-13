/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Object.inl
*/

/*
    INSERT FRONT
*/
template <typename T>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, T value)
{
    if (std::is_convertible<T, std::string>::value)
        return (emplace_front(key, std::string(value)));
    throw std::exception();
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, jsnp::Null null)
{
    (void)null;
    m_tokens.push_front(std::make_pair(key, jsnp::Value()));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, int number)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(number)));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, bool boolean)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(boolean)));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, std::string str)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(str)));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, jsnp::Array array)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(array)));
    return (m_tokens.front());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_front(std::string key, jsnp::Object object)
{
    m_tokens.push_front(std::make_pair(key, jsnp::Value(object)));
    return (m_tokens.front());
}

/*
    INSERT AT
*/
template <typename T>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, T value, unsigned index)
{
    if (std::is_convertible<T, std::string>::value)
        return (emplace_at(key, std::string(value), index));
    throw std::exception();
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, jsnp::Null null, unsigned index)
{
    (void)null;
    auto it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value()));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, int number, unsigned index)
{
    auto it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(number)));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, bool boolean, unsigned index)
{
    auto it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(boolean)));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, std::string str, unsigned index)
{
    auto it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(str)));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, jsnp::Array array, unsigned index)
{
    auto it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(array)));
    return (*it);
}

template <>
inline jsnp::Token& jsnp::Object::emplace_at(std::string key, jsnp::Object object, unsigned index)
{
    auto it = m_tokens.insert(std::next(m_tokens.begin(), index), std::make_pair(key, jsnp::Value(object)));
    return (*it);
}

/*
    INSERT BACK
*/
template <typename T>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, T value)
{
    if (std::is_convertible<T, std::string>::value)
        return (emplace_back(key, std::string(value)));
    throw std::exception();
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, jsnp::Null null)
{
    (void)null;
    m_tokens.push_back(std::make_pair(key, jsnp::Value()));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, int number)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(number)));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, bool boolean)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(boolean)));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, std::string str)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(str)));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, jsnp::Array array)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(array)));
    return (m_tokens.back());
}

template <>
inline jsnp::Token& jsnp::Object::emplace_back(std::string key, jsnp::Object object)
{
    m_tokens.push_back(std::make_pair(key, jsnp::Value(object)));
    return (m_tokens.back());
}

/*
    REMOVE
*/
inline void jsnp::Object::remove(const std::string& key)
{
    for (auto it = m_tokens.begin(); it != m_tokens.end(); it++)
        if (it->first == key) {
            m_tokens.erase(it);
            break;
        }
}

/*
    INSERT
*/
inline jsnp::Token& jsnp::Object::insert_front(jsnp::Token& token)
{
    m_tokens.push_front(token);
    return (m_tokens.front());
}

inline jsnp::Token& jsnp::Object::insert_at(jsnp::Token& token, unsigned index)
{
    auto it = m_tokens.insert(std::next(m_tokens.begin(), index), token);
    return (*it);
}

inline jsnp::Token& jsnp::Object::insert_back(jsnp::Token& token)
{
    m_tokens.push_back(token);
    return (m_tokens.back());
}

/*
    OTHER
*/
inline jsnp::Token& jsnp::Object::operator[](const std::string& key)
{
    for (auto& obj : m_tokens)
        if (obj.first == key)
            return (obj);
    throw std::exception();
}