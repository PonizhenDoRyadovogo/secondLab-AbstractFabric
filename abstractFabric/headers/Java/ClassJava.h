#ifndef CLASSJAVA_H
#define CLASSJAVA_H

#include <vector>
#include "Unit.h"

class ClassJava : public Unit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    ClassJava(const std::string &name, Flags flags, Flags accessModifier = 0);
    void add(const std::shared_ptr<Unit>& unit, Flags flags = 3) override;
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_name;
    Flags m_accessModifier;
    Flags m_flags;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif // CLASSJAVA_H
