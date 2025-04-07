#ifndef UNIT_H
#define UNIT_H

#include <memory>
#include <string>

class Unit {
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATEPROTECTED,
        FILE,
        INTERNAL,
        PROTECTEDINTERNAL
    };
    enum Modifier {
        STATIC = 1,
        VIRTUAL = 1 << 1,
        CONST = 1 << 2,
        ABSTRACT = 1 << 3,
        FINAL = 1 << 4
    };
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    virtual void add(const std::shared_ptr<Unit>& , Flags = 0) {
        throw std::runtime_error("Not supported");
    }
    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    virtual std::string generateShift(unsigned int level) const
    {
        static const auto DEFAULT_SHIFT = "    ";
        std::string result;
        for(unsigned int i = 0; i < level; ++i) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_H
