/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Config.hpp
 *
 * Description:
 * The configuration header file.
 * It is used to make necessary configurations in the Engine
 * depending on your operating system.
 */

#ifndef __SWENGINE_CORE_CONFIG_HPP__
#define __SWENGINE_CORE_CONFIG_HPP__

#define GRAPHICAL_MODULE

#if defined(_WIN32)
    #define SW_CORE_WINDOWS_SYSTEM
#elif defined(__unix__)
    #if defined(__linux__)
        #define SW_CORE_LINUX_SYSTEM
    #else
        #error Unsupported UNIX system
    #endif

#else

    #error Unsupported system
#endif

#if defined(SW_CORE_WINDOWS_SYSTEM)
    #define SW_CORE_API_EXPORT __declspec(dllexport)
    #define SW_CORE_API_IMPORT __declspec(dllimport)
#else
    #define SW_CORE_API_EXPORT
    #define SW_CORE_API_IMPORT
#endif

#endif //__SWENGINE_CORE_CONFIG_HPP__
