#ifndef PRINTOPERATORCS_H
#define PRINTOPERATORCS_H

#include "Unit.h"

class PrintOperatorCs : public Unit
{
public:
    PrintOperatorCs(const std::string &text);
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_text;
};


#endif // PRINTOPERATORCS_H
