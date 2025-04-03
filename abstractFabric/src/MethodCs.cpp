#include "MethodCs.h"

void MethodCs::add(const std::shared_ptr<Unit> &unit, Flags)
{
    m_body.push_back(unit);
}

std::string MethodCs::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & PRIVATE) {
        result += "private ";
    } else if(m_flags & PRIVATEPROTECTED) {
        result += "private protected";
    } else if(m_flags & PROTECTED) {
        result += "protected";
    } else if(m_flags & INTERNAL)
    {
        result += "internal ";
    } else if(m_flags & PROTECTEDINTERNAL) {
        result += "protetcted internal";
    } else if(m_flags & PUBLIC) {
        result += "public ";
    }

    if(m_flags & STATIC) {
        result += "static";
    }

    result += m_returnType + " " + m_name + "() " + "{\n";
    for(const auto& b: m_body) {
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
