#ifndef CODEFACTORYCPP_H
#define CODEFACTORYCPP_H

#include "ICodeFactory.h"
#include "ClassCpp.h"
#include "MethodCpp.h"
#include "PrintOperatorCpp.h"

class CodeFactoryCpp : public ICodefactory
{
    std::shared_ptr<Unit> createClass(const std::string &name,
        Unit::Flags flags
    ) const override
    {
        return std::make_shared<ClassCpp>(name, flags);
    }

    std::shared_ptr<Unit> createMethod(const std::string &name,
        const std::string &returnType,
        Unit::Flags flags
    ) const override
    {
        return std::make_shared<MethodCpp>(name, returnType, flags);
    }

    virtual std::shared_ptr<Unit> createPrintOperator(const std::string &text) const override
    {
        return std::make_shared<PrintOperatorCpp>(text);
    }
};

#endif // CODEFACTORYCPP_H
