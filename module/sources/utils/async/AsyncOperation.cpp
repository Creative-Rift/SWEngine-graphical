/*
** ShipWreck Engine , 2022
** AsyncOperation.cpp
*/

#include "AsyncOperation.hpp"

sw::AsyncOperation::~AsyncOperation()
= default;

bool sw::AsyncOperation::isDone()
{
    return (m_thread->joinable());
}

void sw::AsyncOperation::finish()
{
    m_thread->join();
}
