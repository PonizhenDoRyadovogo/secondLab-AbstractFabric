#ifndef CLASSJAVA_H
#define CLASSJAVA_H

#include <vector>
#include "Unit.h"

class ClassJava : public Unit
{
public:
    enum Modifier {
        PRIVATE = 1,
        PUBLIC = 1 << 1,
        PROTECTED = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };
public:
    ClassJava(const std::string &name, Flags modifiers)
        :m_name(name), m_flags(modifiers)
    {}
    void add(const std::shared_ptr<Unit>& unit, Flags flags = 0) override;
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_name;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_fields;
};

#endif // CLASSJAVA_H
