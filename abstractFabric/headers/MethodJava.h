#ifndef METHODJAVA_H
#define METHODJAVA_H

#include <vector>
#include "Unit.h"

class MethodJava : public Unit
{
public:
    enum Modifier {
        PRIVATE = 1,
        PUBLIC = 1 << 1,
        PROTECTED = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4,
        STATIC = 1 << 5
    };
public:
    MethodJava(const std::string &name, const std::string &returnType, Flags flags = 0)
        :m_name(name), m_returnType(returnType), m_flags(flags)
    {}
    void add(const std::shared_ptr<Unit> &unit, Flags = 0) override;
    std::string compile(unsigned int level = 0) const override;
    bool hasModifier(Modifier m) const {
        return (m_flags & m) != 0;
    }
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // METHODJAVA_H
