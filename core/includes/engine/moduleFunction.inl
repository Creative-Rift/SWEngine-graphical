/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * moduleFunction.inl
 *
 * Description:
 * Implementation of Engine functions for Module
 */

template <ConcreteModule Module, typename... Args>
inline Module& sw::Engine::createModule(Args... args)
{
    if (hasModule())
        sw::Speech::Warning(sw::Log::warning122(FUNCTION));
    else
        setModule(std::make_unique<Module>(args...));
    return (static_cast<Module&>(getModule()));
}

template <ConcreteModule Module>
inline Module& sw::Engine::getModule()
{
    if (!hasModule())
        throw sw::Error(sw::Log::error112(FUNCTION));
    return (static_cast<Module&>(getModule()));
}