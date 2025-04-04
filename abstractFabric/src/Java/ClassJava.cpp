#include "ClassJava.h"
#include "MethodJava.h"

const std::vector<std::string> ClassJava::ACCESS_MODIFIERS = {"public", "protected", "private"};

ClassJava::ClassJava(const std::string &name, Flags flags, Flags accessModifier)
    :m_name(name), m_flags(flags)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
    if(accessModifier < ACCESS_MODIFIERS.size()) {
       m_accessModifier = accessModifier;
    } else {
        m_accessModifier = PUBLIC;
    }
}

void ClassJava::add(const std::shared_ptr<Unit>& unit, Flags flags)
{
    if(auto method = std::dynamic_pointer_cast<MethodJava>(unit)) {
        if(method->hasModifier(ABSTRACT)) {
            m_flags |= ABSTRACT;
        }
    }
    int accessModifier = PRIVATE;
    if(flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string ClassJava::compile(unsigned int level) const
{
    std::string result = (level == 0) ? generateShift(level) : "";

    result += (level == 0) ? (ACCESS_MODIFIERS[m_accessModifier] + " ") : "";
    if(m_flags & FINAL) {
        if((m_flags & ABSTRACT) == 0) {
            result += "final ";
        }
        else {
            result += "abstract ";
        }
    } else if(m_flags & ABSTRACT) {
        result += "abstract ";
    }

    result += "class " + m_name + "(){\n";
    for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if(m_fields[i].empty()) {
            continue;
        }

        for(const auto& f: m_fields[i]) {
            result += generateShift(level + 1);
            result += ACCESS_MODIFIERS[i] + " ";
            result += f->compile(level + 1);
        }
        result += "\n";
    }
    if(level != 0) {
        result += generateShift(level + 1) + "};\n";
    } else {
        result += generateShift(level) + "};\n";
    }
    return result;

}
