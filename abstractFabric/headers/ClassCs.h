#ifndef CLASSCS_H
#define CLASSCS_H

#include <vector>
#include "Unit.h"

class ClassCs : public Unit
{
public:
    enum Modifier
    {
        PRIVATE = 1,
        PRIVATEPROTECTED = 1 << 1,
        FILE = 1 << 2,
        PROTECTED = 1 << 3,
        INTERNAL = 1 << 4,
        PROTECTEDINTERNAL = 1 << 5,
        PUBLIC = 1 << 6
    };
public:
    ClassCs(const std::string& name, Flags flags, bool isNested = false)
        : m_name(name), m_flags(flags), m_isNested(isNested)
    {}
    void add(const std::shared_ptr<Unit>& unit, Flags) override;
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_name;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_fields;
    bool m_isNested;
};

#endif // CLASSCS_H
