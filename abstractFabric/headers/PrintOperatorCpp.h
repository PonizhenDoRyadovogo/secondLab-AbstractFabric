#ifndef PRINTOPERATORCPP_H
#define PRINTOPERATORCPP_H

#include "Unit.h"

class PrintOperatorCpp : public Unit
{
public:
    PrintOperatorCpp(const std::string &text);
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_text;
};

#endif // PRINTOPERATORCPP_H
