#ifndef METHODCS_H
#define METHODCS_H

#include <vector>
#include "Unit.h"

class MethodCs : public Unit
{
public:
    enum Modifier
    {
        PRIVATE = 1,
        PRIVATEPROTECTED = 1 << 1,
        PROTECTED = 1 << 2,
        INTERNAL = 1 << 3,
        PROTECTEDINTERNAL = 1 << 4,
        PUBLIC = 1 << 5,
        STATIC = 1 << 6
    };
public:
    MethodCs(const std::string &name, const std::string &returnType, Flags flags = 0)
        :m_name(name), m_returnType(returnType), m_flags(flags)
    {}
    void add(const std::shared_ptr<Unit> &unit, Flags = 0) override;
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // METHODCS_H
