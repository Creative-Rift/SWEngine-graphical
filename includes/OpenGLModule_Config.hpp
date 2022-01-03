//
// Created by Admin on 03/01/2022.
//

#ifndef SWENGINE_OPENGLMODULE_OPENGLMODULE_CONFIG_HPP
#define SWENGINE_OPENGLMODULE_OPENGLMODULE_CONFIG_HPP

#if defined(_WIN32)
    #define SW_GRAPH_MODULE_WINDOWS_SYSTEM
#elif defined(__unix__)
    #if defined(__linux__)
        #define SW_GRAPH_MODULE_LINUX_SYSTEM
    #else
        #error Unsupported UNIX system
    #endif

#else

    #error Unsupported system
#endif

#if defined(SW_GRAPH_MODULE_WINDOWS_SYSTEM)
    #define SW_GRAPH_MODULE_EXPORT __declspec(dllexport)
    #define SW_GRAPH_MODULE_IMPORT __declspec(dllimport)
#endif

#endif //SWENGINE_OPENGLMODULE_OPENGLMODULE_CONFIG_HPP
