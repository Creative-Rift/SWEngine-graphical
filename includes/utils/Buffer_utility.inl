#pragma once

std::string getEventType(const sw::Type &evt)
{
    switch(evt)
    {
        case sw::Type::None:
            return ("None");
        case sw::Type::Mouse:
            return ("Mouse button");
        case sw::Type::Position:
            return ("Mouse position");
        case sw::Type::Keyboard:
            return ("Keyboard");
        case sw::Type::Scroll:
            return ("Scroll");
    }
    return "None";
};

std::string getEventAction(const sw::Type &evt, const int &act)
{
    switch(evt)
    {
        default:
            return ("None");
        case sw::Type::Mouse:
            switch(act)
            {
                case GLFW_PRESS:
                    return "Pressed";
                case GLFW_RELEASE:
                    return "Released";
            }
        case sw::Type::Keyboard:
            switch(act)
            {
                case GLFW_PRESS:
                    return "Pressed";
                case GLFW_RELEASE:
                    return "Released";
                case GLFW_REPEAT:
                    return "Down";
                case (-1):
                    return "Up";
            }
    }
    return "None";
};

void dumpEvent(const sw::EventInfo* jaj)
{
    for (size_t i = 0 ; i < sw::MAX_BUFFER; ++i)
    {
        switch(jaj[i].m_t)
        {
            case sw::Type::None:
                break;
            case sw::Type::Mouse:
                std::cout << "Event type is " + sw::getEventType(jaj[i].m_t) << " action is: " + sw::getEventAction(jaj[i].m_t, jaj[i].m_ki.second) << std::endl;
                break;
            case sw::Type::Position:
                std::cout << "Event type is " + sw::getEventType(jaj[i].m_t) << " positions are: " << jaj[i].m_os.first << "," << jaj[i].m_os.second << std::endl;
                break;
            case sw::Type::Keyboard:
                std::cout << "Event type is " + sw::getEventType(jaj[i].m_t) << " action is: " + sw::getEventAction(jaj[i].m_t, jaj[i].m_ki.second) << std::endl;
                break;
            case sw::Type::Scroll:
                std::cout << "Event type is " + sw::getEventType(jaj[i].m_t) << " scroll values are: " << jaj[i].m_os.first << "," << jaj[i].m_os.second << std::endl;
                break;
        }
    }
};