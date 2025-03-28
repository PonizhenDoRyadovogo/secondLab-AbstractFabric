#ifndef ICLASS_H
#define ICLASS_H

#include <vector>
#include <Unit.h>

class IClass : public Unit
{
public:
    virtual ~IClass() = default;
    IClass(const std::string& name)
        : m_name(name)
    {}
    virtual void add(const std::shared_ptr<Unit>& unit, Flags flags) = 0;
    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif // ICLASS_H
