/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Speech.cpp
 *
 * Description:
 * Speech functions implementation
 */

#include "utils/Speech.hpp"
#include "config/Config.hpp"

std::vector<std::pair<std::string, std::string>> sw::Speech::m_logList;
std::vector<std::pair<std::string, std::string>> sw::Speech::m_lastLogList;

std::map<std::string, std::map<std::string, std::vector<std::string>>> sw::Speech::m_listSpeech;

SW_CORE_API_EXPORT bool sw::Speech::colorized   = false;
SW_CORE_API_EXPORT bool sw::Speech::displayed   = true;
SW_CORE_API_EXPORT bool sw::Speech::dispError   = true;
SW_CORE_API_EXPORT bool sw::Speech::dispWarning = true;
SW_CORE_API_EXPORT bool sw::Speech::dispDebug   = true;
SW_CORE_API_EXPORT bool sw::Speech::dispInfo    = true;
SW_CORE_API_EXPORT bool sw::Speech::clearOnPlay = false;
SW_CORE_API_EXPORT bool sw::Speech::dispTime = true;
SW_CORE_API_EXPORT bool sw::Speech::stack = true;

bool sw::Speech::isBlackList(std::string code)
{
    std::string targetChar;
    bool log;
    bool exec;
    bool action;
    bool target;

    if (code.empty())
        return (false);
    targetChar.push_back(code.at((colorized ? 6 : 1)));
    log = std::find(m_listSpeech["Black"]["Log"].begin(), m_listSpeech["Black"]["Log"].end(), targetChar) != m_listSpeech["Black"]["Log"].end();
    targetChar.clear();
    targetChar.push_back(code.at((colorized ? 7 : 2)));
    exec = std::find(m_listSpeech["Black"]["Exec"].begin(), m_listSpeech["Black"]["Exec"].end(), targetChar) != m_listSpeech["Black"]["Exec"].end();
    targetChar.clear();
    targetChar.push_back(code.at((colorized ? 8 : 3)));
    action = std::find(m_listSpeech["Black"]["Action"].begin(), m_listSpeech["Black"]["Action"].end(), targetChar) != m_listSpeech["Black"]["Action"].end();
    targetChar.clear();
    targetChar.push_back(code.at((colorized ? 9 : 4)));
    target = std::find(m_listSpeech["Black"]["Target"].begin(), m_listSpeech["Black"]["Target"].end(), targetChar) != m_listSpeech["Black"]["Target"].end();
    return (log || exec || action ||target);
}

bool sw::Speech::isWhiteList(std::string code)
{
    std::string targetChar;
    bool log;
    bool exec;
    bool action;
    bool target;

    if (code.empty())
        return (false);
    targetChar.push_back(code.at((colorized ? 6 : 1)));
    log = std::find(m_listSpeech["White"]["Log"].begin(), m_listSpeech["White"]["Log"].end(), targetChar) != m_listSpeech["White"]["Log"].end();
    targetChar.clear();
    targetChar.push_back(code.at((colorized ? 7 : 2)));
    exec = std::find(m_listSpeech["White"]["Exec"].begin(), m_listSpeech["White"]["Exec"].end(), targetChar) != m_listSpeech["White"]["Exec"].end();
    targetChar.clear();
    targetChar.push_back(code.at((colorized ? 8 : 3)));
    action = std::find(m_listSpeech["White"]["Action"].begin(), m_listSpeech["White"]["Action"].end(), targetChar) != m_listSpeech["White"]["Action"].end();
    targetChar.clear();
    targetChar.push_back(code.at((colorized ? 9 : 4)));
    target = std::find(m_listSpeech["White"]["Target"].begin(), m_listSpeech["White"]["Target"].end(), targetChar) != m_listSpeech["White"]["Target"].end();
    return (log || exec || action ||target);
}

std::string sw::Speech::time()
{
    if (!dispTime) {
        if (colorized)
            return (std::string("\033[38;5;218m--:--:--") + Color::White);
        else
            return ("--:--:--");
    }

    time_t now = std::time(0);
    tm *stime = std::localtime(&now);
    std::stringstream sstr;

    if (colorized)
        sstr << std::setfill('0')
             << "\033[38;5;218m" << std::setw(2) << stime->tm_hour
             << Color::White << ":"
             << "\033[38;5;218m" << std::setw(2) << stime->tm_min
             << Color::White << ":"
             << "\033[38;5;218m" << std::setw(2) << stime->tm_sec
             << Color::White;
    else
        sstr << std::setfill('0')
             << std::setw(2) << stime->tm_hour
             << ":"
             << std::setw(2) << stime->tm_min
             << ":"
             << std::setw(2) << stime->tm_sec;
    return (sstr.str());
}

void sw::Speech::Info(const Log& log)
{
    Info(log.message, log.code);
}

void sw::Speech::Debug(const Log& log)
{
    Debug(log.message, log.code);
}

void sw::Speech::Warning(const Log& log)
{
    Warning(log.message, log.code);
}

void sw::Speech::Error(const Log& log)
{
    Error(log.message, log.code);
}

void sw::Speech::Error(const std::string& message, const std::string& code)
{
    if (!dispError)
        return;

    std::stringstream stime;
    std::stringstream smess;

    if (colorized) {
        stime << Color::Bold << "[" << time() << "] ";
        smess << "[" << Color::Magenta << (code != "0" ? code : " =D ") << Color::White << "] "
              << Color::LightRed << "Error: "
              << Color::Reset << message
              << std::endl;
    } else {
        stime << "[" << time() << "] ";
        smess << "[" << (code != "0" ? code : " =D ") << "] "
              << "Error: "
              << message
              << std::endl;
    }
    m_logList.push_back(std::make_pair(stime.str(), smess.str()));
}

void sw::Speech::Warning(const std::string& message, const std::string& code)
{
    if (!dispWarning)
        return;

    std::stringstream stime;
    std::stringstream smess;

    if (colorized) {
        stime << Color::Bold << "[" << time() << "] ";
        smess << "[" << Color::Magenta << (code != "0" ? code : " =D ") << Color::White << "] "
              << Color::LightYellow << "Warning: "
              << Color::Reset << message
              << std::endl;
    } else {
        stime << "[" << time() << "] ";
        smess << "[" << (code != "0" ? code : " =D ") << "] "
              << "Warning: "
              << message
              << std::endl;
    }
    m_logList.push_back(std::make_pair(stime.str(), smess.str()));
}

void sw::Speech::Debug(const std::string& message, const std::string& code)
{
    if (!dispDebug)
        return;

    std::stringstream stime;
    std::stringstream smess;

    if (colorized) {
        stime << Color::Bold << "[" << time() << "] ";
        smess << "[" << Color::Magenta << (code != "0" ? code : " =D ") << Color::White << "] "
              << Color::Cyan << "Debug: "
              << Color::Reset << message
              << std::endl;
    } else {
        stime << "[" << time() << "] ";
        smess << "[" << (code != "0" ? code : " =D ") << "] "
              << "Debug: "
              << message
              << std::endl;
    }
    m_logList.push_back(std::make_pair(stime.str(), smess.str()));
}

void sw::Speech::Info(const std::string& message, const std::string& code)
{
    if (!dispInfo)
        return;

    std::stringstream stime;
    std::stringstream smess;

    if (colorized) {
        stime << Color::Bold << "[" << time() << "] ";
        smess << "[" << Color::Magenta << (code != "0" ? code : " =D ") << Color::White << "] "
              << Color::Green << "Info: "
              << Color::Reset << message
              << std::endl;
    } else {
        stime << "[" << time() << "] ";
        smess << "[" << (code != "0" ? code : " =D ") << "] "
              << "Info: "
              << message
              << std::endl;
    }
    m_logList.push_back(std::make_pair(stime.str(), smess.str()));
}

static bool isSame(std::vector<std::pair<std::string, std::string>> list1, std::vector<std::pair<std::string, std::string>> list2)
{
    int ctr1 = list1.size() - 1;
    int ctr2 = list2.size() - 1;

    while (ctr1 >= 0 && ctr2 >= 0) {
        if (list1[ctr1].second == list2[ctr2].second) {
            ctr1 -= 1;
            ctr2 -= 1;
            if (ctr1 == -1) {
                return (true);
            }
        }
        else
            ctr1 -= 1;
    }
    return (false);
}

void sw::Speech::flush(std::ostream& os)
{
    if (!displayed)
        return;

    static sw::Chrono chrono(sw::Chrono::Lauch);
    static std::vector<std::pair<std::string, std::string>> savedLog;
    bool same = false;

    if (stack)
        same = isSame(m_logList, m_lastLogList);
    if (same) {
        if (m_logList.size() == m_lastLogList.size() && chrono.getElapsedTime() < 1) {
            m_logList.clear();
            return;
        }
        chrono.start();

        unsigned line = (m_logList.size() <= m_lastLogList.size() ? m_logList.size() : m_lastLogList.size());
        os << "\033[" + std::to_string(line) + "A";
    }

    for (auto& [time, mess] : m_logList) {
        if (!isWhiteList(mess) && isBlackList(mess)) {
            std::remove(m_logList.begin(), m_logList.end(), std::pair<std::string, std::string>(time, mess));
            continue;
        }
        os << time << mess;
    }

    m_lastLogList = m_logList;
    m_logList.clear();
}

void sw::Speech::clearConsole(std::ostream& os)
{
    os << "\033[2J\033[1;1H";
}

std::ostream& operator<<(std::ostream& os, sw::Speech& speech)
{
    speech.flush(os);
    return (os);
}

void sw::Speech::clearLog()
{
    m_lastLogList.clear();
    m_logList.clear();
}

void sw::Speech::setDisplayed(bool value)
{
    displayed = value;
}

void sw::Speech::addBlackList(std::string list, std::string element)
{
    if (list == std::string("Log"))
        m_listSpeech["Black"]["Log"].emplace_back(element);
    if (list == std::string("Exec"))
        m_listSpeech["Black"]["Exec"].emplace_back(element);
    if (list == std::string("Action"))
        m_listSpeech["Black"]["Action"].emplace_back(element);
    if (list == std::string("Target"))
        m_listSpeech["Black"]["Target"].emplace_back(element);
}

void sw::Speech::addWhiteList(std::string list, std::string element)
{
    if (list == std::string("Log"))
        m_listSpeech["White"]["Log"].emplace_back(element);
    if (list == std::string("Exec"))
        m_listSpeech["White"]["Exec"].emplace_back(element);
    if (list == std::string("Action"))
        m_listSpeech["White"]["Action"].emplace_back(element);
    if (list == std::string("Target"))
        m_listSpeech["White"]["Target"].emplace_back(element);
}

void sw::Speech::ConfigSpeech()
{

    sw::Speech::colorized = sw::Config::m_config["Debug"]["Colorized"].as<bool>();
    sw::Speech::displayed = sw::Config::m_config["Debug"]["Display_Console"].as<bool>();
    sw::Speech::dispError = sw::Config::m_config["Debug"]["Display_Error"].as<bool>();
    sw::Speech::dispWarning = sw::Config::m_config["Debug"]["Display_Warning"].as<bool>();
    sw::Speech::dispInfo = sw::Config::m_config["Debug"]["Display_Info"].as<bool>();
    sw::Speech::dispDebug = sw::Config::m_config["Debug"]["Display_Debug"].as<bool>();
    sw::Speech::clearOnPlay = sw::Config::m_config["Debug"]["ClearOnPlay"].as<bool>();
    for (auto element : sw::Config::m_config["Debug"]["BlackList_Log"])
        sw::Speech::addBlackList("Log", element.as<std::string>());
    for (auto element : sw::Config::m_config["Debug"]["BlackList_Executor"])
        sw::Speech::addBlackList("Exec", element.as<std::string>());
    for (auto element : sw::Config::m_config["Debug"]["BlackList_Action"])
        sw::Speech::addBlackList("Action", element.as<std::string>());
    for (auto element : sw::Config::m_config["Debug"]["BlackList_Target"])
        sw::Speech::addBlackList("Target", element.as<std::string>());
    for (auto element : sw::Config::m_config["Debug"]["WhiteList_Log"])
        sw::Speech::addWhiteList("Log", element.as<std::string>());
    for (auto element : sw::Config::m_config["Debug"]["WhiteList_Executor"])
        sw::Speech::addWhiteList("Exec", element.as<std::string>());
    for (auto element : sw::Config::m_config["Debug"]["WhiteList_Action"])
        sw::Speech::addWhiteList("Action", element.as<std::string>());
    for (auto element : sw::Config::m_config["Debug"]["WhiteList_Target"])
        sw::Speech::addWhiteList("Target", element.as<std::string>());
}