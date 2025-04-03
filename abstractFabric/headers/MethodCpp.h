#ifndef METHODCPP_H
#define METHODCPP_H

#include <vector>

#include "Unit.h"

class MethodCpp : public Unit
{
public:
    enum Modifier {
      STATIC = 1,
      CONST = 1 << 1,
      VIRTUAL = 1 << 2
    };
public:
    MethodCpp(const std::string &name, const std::string& returnType, Flags flags = 0);
    void add(const std::shared_ptr<Unit> &unit, Flags = 0) override;
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // METHODCPP_H
