#include "MethodCs.h"

void MethodCs::add(const std::shared_ptr<Unit> &unit, Flags)
{
    m_body.push_back(unit);
}

std::string MethodCs::compile(unsigned int level) const
{
    std::string result;

    //static и virtual нельзя комбинировать
    if(m_flags & STATIC) {
        result += "static ";
    } else if(m_flags & VIRTUAL) {
        result += "virtual ";
    }

    result += m_returnType + " " + m_name + "()" + "{\n";
    for(const auto& b: m_body) {
        result += b->compile(level + 2);
    }
    result += generateShift(level + 1) + "}\n";
    return result;
}
