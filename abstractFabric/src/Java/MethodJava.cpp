#include "MethodJava.h"

void MethodJava::add(const std::shared_ptr<Unit> &unit, Flags)
{
    m_body.push_back(unit);
}

std::string MethodJava::compile(unsigned int level) const
{
    std::string result;

    if(m_flags & STATIC) {
        result += "static ";
    }
    if(m_flags & ABSTRACT) {
        result += "abstract ";
    } else if (m_flags & FINAL) {
        result += "final ";
    }

    result += m_returnType + " " + m_name + "()";
    if((m_flags & ABSTRACT) == 0) {
        result += "{\n";
        for(const auto& b: m_body) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
    } else {
        result += ";\n";
    }

    return result;
}

