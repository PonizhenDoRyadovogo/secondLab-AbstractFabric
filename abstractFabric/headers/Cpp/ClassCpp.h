#ifndef CLASSCPP_H
#define CLASSCPP_H

#include <vector>

#include "Unit.h"

class ClassCpp : public Unit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    ClassCpp(const std::string &name, Flags modifier = 0);
    void add(const std::shared_ptr<Unit> &unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif // CLASSCPP_H
