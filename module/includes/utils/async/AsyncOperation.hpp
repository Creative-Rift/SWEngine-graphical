/*
** ShipWreck Engine , 2022
** AsyncOperation.hpp
*/

#ifndef SHIPWRECK_ENGINE_ASYNCOPERATION_HPP
#define SHIPWRECK_ENGINE_ASYNCOPERATION_HPP

#include <thread>

#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT AsyncOperation
    {
    public:
        AsyncOperation();


        ~AsyncOperation();

        virtual bool isDone();
        void finish();

    protected:
        std::shared_ptr<std::thread> m_thread;
    };

    #include "AsyncOperation.inl"
}

#endif //SHIPWRECK_ENGINE_ASYNCOPERATION_HPP
