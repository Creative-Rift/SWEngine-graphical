/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Reference.inl
 *
 * Description:
 * Reference functions implementation
 */

template <typename T>
sw::Reference<T>::Reference()
    :   m_value()
{}

template <typename T>
sw::Reference<T>::Reference(T& value)
    :   m_value(value)
{}

template <typename T>
void sw::Reference<T>::emplace(T& newValue)
{
    m_value.emplace(newValue);
}

template <typename T>
void sw::Reference<T>::erase()
{
    m_value.reset();
}


template <typename T>
bool sw::Reference<T>::hasValue() const
{
    return (m_value.has_value());
}

template <typename T>
T& sw::Reference<T>::value() const
{
    return (m_value.value().get());
}

template <typename T>
T& sw::Reference<T>::operator=(T& newValue)
{
    m_value.emplace(newValue);
    return (m_value.value().get());
}

template <typename T>
T& sw::Reference<T>::operator*() const
{
    return (m_value.value().get());
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const sw::Reference<T>& ref)
{
    os << "Reference <" << *ref << ">\n";
    return (os);
}