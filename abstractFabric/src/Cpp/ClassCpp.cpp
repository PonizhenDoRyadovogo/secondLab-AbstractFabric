#include <vector>

#include "ClassCpp.h"
#include "MethodCpp.h"

const std::vector<std::string> ClassCpp::ACCESS_MODIFIERS = {"public", "protected", "private"};

ClassCpp::ClassCpp(const std::string &name, Flags flags, Flags)
    :m_name(name), m_flags(flags)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void ClassCpp::add(const std::shared_ptr<Unit>& unit, Flags flags)
{
    if(auto method = std::dynamic_pointer_cast<MethodCpp>(unit)) {
        if(method->hasModifier(ABSTRACT)) {
            m_flags &= ~FINAL; //если метод чисто виртуальный, то сбрасываем флаг с final
        }
    }
    int accessModifier = PRIVATE;
    if(flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string ClassCpp::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + m_name;
    if(m_flags & FINAL) {
        result += " final";
    }
    result += "{\n";
    for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if(m_fields[i].empty()) {
            continue;
        }
        result += generateShift(level) + ACCESS_MODIFIERS[i] + ":\n";
        for(const auto& f: m_fields[i]) {
            result += f->compile(level + 1);
        }
        result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}
