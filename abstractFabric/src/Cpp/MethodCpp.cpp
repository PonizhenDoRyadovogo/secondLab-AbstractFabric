#include "MethodCpp.h"

MethodCpp::MethodCpp(const std::string& name, const std::string& returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags)
{}

void MethodCpp::add(const std::shared_ptr<Unit>& unit, Flags)
{
    m_body.push_back(unit);
}

std::string MethodCpp::compile(unsigned int level) const
{
    std::string result = generateShift(level);
    if(m_flags & STATIC) {
        result += "static ";
    } else if((m_flags & VIRTUAL) || (m_flags & ABSTRACT)) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if(m_flags & CONST) {
        result += " const";
    }

    if(m_flags & ABSTRACT) {
        result += " = 0;\n";
    } else {
        result += " {\n";
        for(const auto& b: m_body) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
    }

    return result;
}
