#ifndef CODEFACTORYJAVA_H
#define CODEFACTORYJAVA_H

#include "ICodeFactory.h"
#include "ClassJava.h"
#include "MethodJava.h"
#include "PrintOperatorJava.h"

class CodeFactoryJava : public ICodefactory
{
public:
    std::shared_ptr<Unit> createClass(const std::string &name,
        Unit::Flags flags
    ) const override
    {
        return std::make_shared<ClassJava>(name, flags);
    }

    std::shared_ptr<Unit> createMethod(const std::string &name,
        const std::string &returnType,
        Unit::Flags flags
    ) const override
    {
        return std::make_shared<MethodJava>(name, returnType, flags);
    }

    std::shared_ptr<Unit> createPrintOperator(const std::string &text) const override
    {
        return std::make_shared<PrintOperatorJava>(text);
    }
};

#endif // CODEFACTORYJAVA_H
