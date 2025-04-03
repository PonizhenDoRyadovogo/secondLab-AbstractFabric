#include "PrintOperatorCs.h"

PrintOperatorCs::PrintOperatorCs(const std::string &text)
    : m_text(text)
{}

std::string PrintOperatorCs::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
}
