/*
** ShipWreck Engine , 2022
** AsyncOperation.inl
*/

inline AsyncOperation::AsyncOperation() :
m_thread{std::make_shared<std::thread>()}
{}