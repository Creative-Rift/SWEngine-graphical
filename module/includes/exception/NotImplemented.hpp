/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * NotImplemented.hpp
 *
 * Description:
 * Class can be used to throw an Error
 * if a part of code is not currently implemented
 */

#ifndef __SHIPWRECK_CORE_NOTIMPLEMENTED__HPP__
#define __SHIPWRECK_CORE_NOTIMPLEMENTED__HPP__

#include <string>
#include "Error.hpp"

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



#endif //__SHIPWRECK_CORE_NOTIMPLEMENTED__HPP__
