#ifndef METHODCS_H
#define METHODCS_H

#include <vector>
#include "Unit.h"

class MethodCs : public Unit
{
public:
    MethodCs(const std::string &name, const std::string &returnType, Flags flags = 1)
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
