#ifndef CODEFACTORYCS_H
#define CODEFACTORYCS_H

#include "ICodeFactory.h"
#include "ClassCs.h"
#include "MethodCs.h"
#include "PrintOperatorCs.h"

class CodeFactoryCs : public ICodefactory
{
    std::shared_ptr<Unit> createClass(const std::string &name,
        Unit::Flags flags,
        bool isNested = false
    ) const override
    {
        return std::make_shared<ClassCs>(name, flags, isNested);
    }

    std::shared_ptr<Unit> createMethod(const std::string &name,
        std::string &returnType,
        Unit::Flags flags
    ) const override
    {
        return std::make_shared<MethodCs>(name, returnType, flags);
    }

    std::shared_ptr<Unit> createPrintOperator(const std::string &text) const override
    {
        return std::make_shared<PrintOperatorCs>(text);
    }
};

#endif // CODEFACTORYCS_H
