//
// Created by guill on 17/08/2023.
//

#ifndef SHIPWRECK_ENGINE_FILE_HPP
#define SHIPWRECK_ENGINE_FILE_HPP

#include <string>

namespace sw
{

    class File
    {
        public:
        static std::string ReadFile(std::string path);
    };

} // sw

#endif //SHIPWRECK_ENGINE_FILE_HPP
