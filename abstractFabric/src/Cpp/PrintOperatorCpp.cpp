#include "PrintOperatorCpp.h"

PrintOperatorCpp::PrintOperatorCpp(const std::string &text)
    : m_text(text)
{}

std::string PrintOperatorCpp::compile(unsigned int level) const
{
    return generateShift(level) + "printf(\"" + m_text + "\");\n";
}
