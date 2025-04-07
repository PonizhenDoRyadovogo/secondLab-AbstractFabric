#ifndef CLASSCPP_H
#define CLASSCPP_H

#include <vector>

#include "Unit.h"

class ClassCpp : public Unit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    ClassCpp(const std::string &name, Flags flags, Flags = 0);
    void add(const std::shared_ptr<Unit> &unit, Flags flags = 0) override;
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_name;
    Flags m_flags;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif // CLASSCPP_H
