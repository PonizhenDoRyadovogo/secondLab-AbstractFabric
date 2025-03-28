#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <vector>

#include "IClass.h"

class ClassCpp : public IClass
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    explicit ClassCpp(const std::string& name);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;
};

#endif // CLASSUNIT_H
