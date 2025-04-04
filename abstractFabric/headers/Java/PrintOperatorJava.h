#ifndef PRINTOPERATORJAVA_H
#define PRINTOPERATORJAVA_H

#include "Unit.h"

class PrintOperatorJava : public Unit
{
public:
    PrintOperatorJava(const std::string &text);
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_text;
};

#endif // PRINTOPERATORJAVA_H
