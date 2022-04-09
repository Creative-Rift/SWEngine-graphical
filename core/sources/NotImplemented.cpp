/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * NotImplemented.cpp
 *
 * Description:
 * NotImplemented Error functions implementation
 */

#include "NotImplemented.hpp"

sw::NotImplemented::NotImplemented() :
sw::Error("Function not implemented!", "0")
{}

sw::NotImplemented::NotImplemented(const std::string &message, std::string code) :
sw::Error(message, code)
{}