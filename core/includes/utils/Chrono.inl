/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Chrono.inl
 *
 * Description:
 * Chrono functions implementation
 */

inline sw::Chrono::Chrono(ctorState state) :
    m_isRunning(false)
{
    if (state == Lauch) {
        m_isRunning = true;
        start();
    }
}

inline void sw::Chrono::start()
{
    m_start = std::chrono::steady_clock::now();
    m_end = m_start;
    m_tour = m_start;
    m_isRunning = true;
}

inline void sw::Chrono::stop()
{
    m_end = std::chrono::steady_clock::now();
    m_isRunning = false;
}

inline void sw::Chrono::tour()
{
    m_tour = m_end;
}

inline double sw::Chrono::getElapsedTime() const
{
    if (m_isRunning)
        m_end = std::chrono::steady_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_tour).count();
    return (step / 1000);
}

inline double sw::Chrono::getTotalTime() const
{
    if (m_isRunning)
        m_end = std::chrono::steady_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count();
    return (step / 1000);
}

inline bool sw::Chrono::isRunning() const
{
    return (m_isRunning);
}

inline std::ostream& operator<<(std::ostream& os, const sw::Chrono& chrono)
{
    os  << "Chrono :\n"
        << "\nIn progress : " << std::boolalpha << chrono.isRunning() << "\n"
        << "\nElapsed time : " << chrono.getElapsedTime() << "\n"
        << "\nTotal time : " << chrono.getTotalTime() << "\n";
    return (os);
}