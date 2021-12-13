/*
** EPITECH PROJECT, 2021
** NotImplemented.hpp
** File description:
** NotImplemented.hpp
*/

#ifndef __NOTIMPLEMENTED__HPP
#define __NOTIMPLEMENTED__HPP

#include <string>
#include "error/Error.hpp"

namespace sw
{
    class NotImplemented : public sw::Error
    {
    private:
        const std::string m_message;
    public:
        NotImplemented(NotImplemented const&) = delete;
        NotImplemented(NotImplemented &&) = delete;
        NotImplemented& operator=(NotImplemented const &) = delete;
        NotImplemented& operator=(NotImplemented&&) = delete;

        NotImplemented();
        explicit NotImplemented(const std::string &message, std::string code);
    }; // class NotImplemented

} // namespace sw



#endif //__NOTIMPLEMENTED__HPP
