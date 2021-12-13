/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Chrono.inl
*/

inline sw::Chrono::Chrono() :
    m_isRunning(false)
{}

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

inline double sw::Chrono::getElapsedTime()
{
    if (m_isRunning)
        m_end = std::chrono::steady_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_tour).count();
    return (step / 1000);
}

inline double sw::Chrono::getTotalTime()
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