#ifndef METHODCPP_H
#define METHODCPP_H

#include <vector>

#include "Unit.h"

class MethodCpp : public Unit
{
public:
    MethodCpp(const std::string &name, const std::string& returnType, Flags flags = 0);
    void add(const std::shared_ptr<Unit> &unit, Flags) override;
    std::string compile(unsigned int level = 0) const override;
    bool hasModifier(Flags m) const {
        return (m_flags & m) != 0;
    }
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // METHODCPP_H
