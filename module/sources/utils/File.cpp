//
// Created by guill on 17/08/2023.
//

#include <fstream>
#include <sstream>

#include "File.hpp"
#include "exception/FileException.hpp"

std::string sw::File::ReadFile(std::string path)
{
    std::fstream file(path);
    std::stringstream fileBuffer;

    if (!file.is_open())
        throw sw::FileException("Template file cannot be open. (" + path + ")");
    auto buffer = file.rdbuf();
    fileBuffer << buffer;
    file.close();
    return fileBuffer.str();
}
