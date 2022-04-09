/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AModule.inl
 *
 * Description:
 * Implementation of Module function.
 */

inline sw::AModule::AModule()
    :   m_isLoad(false)
{}

inline bool sw::AModule::isLoad() const
{
    return (m_isLoad);
}

inline std::string sw::AModule::type() const
{
    return ("AModule");
}

inline std::ostream& operator<<(std::ostream& os, const sw::AModule& module)
{
    os  << "Module of type : '" << module.type() << "'\n"
        << "\tIs Load : " << std::boolalpha << module.isLoad() << "\n";
    return (os);
}