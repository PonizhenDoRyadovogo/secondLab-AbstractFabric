#ifndef CLASSCS_H
#define CLASSCS_H

#include <vector>
#include "Unit.h"

class ClassCs : public Unit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    ClassCs(const std::string &name, Flags modifier = 5);
    void add(const std::shared_ptr<Unit>& unit, Flags flags = 3) override;
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_name;
    Flags m_accessModifier;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif // CLASSCS_H
