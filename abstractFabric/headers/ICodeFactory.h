#ifndef ICODEFACTORY_H
#define ICODEFACTORY_H

#include "Unit.h"

class ICodefactory {
public:
    virtual ~ICodefactory() = default;
    virtual std::shared_ptr<Unit> createClass(const std::string &name,
        Unit::Flags flags,
        bool isNested = false
    ) const = 0;

    virtual std::shared_ptr<Unit> createMethod(const std::string &name,
        std::string &returnType,
        Unit::Flags flags
    ) const = 0;

    virtual std::shared_ptr<Unit> createPrintOperator(const std::string &text) const = 0;
};

#endif // ICODEFACTORY_H
