#include "ClassCs.h"

const std::vector<std::string> ClassCs::ACCESS_MODIFIERS = {"public", "protected", "private", "private protected",
                                                            "file", "internal", "protetcted internal"};

ClassCs::ClassCs(const std::string &name, Flags modifier)
    :m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
    if(modifier < ACCESS_MODIFIERS.size()) {
        m_accessModifier = modifier;
    } else {
        m_accessModifier = INTERNAL;
    }
}

void ClassCs::add(const std::shared_ptr<Unit> &unit, Flags flags)
{
    int accessModifier = PRIVATE;
    if(flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string ClassCs::compile(unsigned int level) const
{
    std::string result = generateShift(level);
    Flags finalMods = m_accessModifier;
    //у топ-левел классов могут быть только модификаторы public, file и internal
    if(level == 0) {
        if(m_accessModifier != PUBLIC & m_accessModifier != FILE & m_accessModifier != INTERNAL) {
            finalMods = INTERNAL;
        }
    }

    result += ACCESS_MODIFIERS[finalMods] + " class " + m_name + "{\n";

    for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if(m_fields[i].empty()) {
            continue;
        }

        for(const auto& f: m_fields[i]) {
            result += generateShift(level + 1);
            result += ACCESS_MODIFIERS[i] + " ";
            result += f->compile(0);
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
