#include "PrintOperatorJava.h"

PrintOperatorJava::PrintOperatorJava(const std::string &text)
    : m_text(text)
{}

std::string PrintOperatorJava::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
}
