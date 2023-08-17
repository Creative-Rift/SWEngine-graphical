/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2023
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/


#ifndef KITCHEN_FILEEXCEPTION_HPP
#define KITCHEN_FILEEXCEPTION_HPP

#include <exception>
#include <string>

namespace sw
{
    class FileException : public std::exception
    {
        private:
            std::string m_what;
        public:
            explicit FileException(std::string reason);
            [[nodiscard]] const char * what() const noexcept override;
    };
}

#endif //KITCHEN_FILEEXCEPTION_HPP
