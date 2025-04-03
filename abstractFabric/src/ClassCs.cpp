#include "ClassCs.h"

void ClassCs::add(const std::shared_ptr<Unit> &unit, Flags)
{
    m_fields.push_back(unit);
}

std::string ClassCs::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    Flags finalMods = m_flags;
    //у топ-левел классов могут быть только модификаторы public, file и internal
    if(!m_isNested) {
        static const Flags ALLOWED_TOPLEVEL = PUBLIC | INTERNAL | FILE;

        Flags tmpFlags = m_flags & ~ALLOWED_TOPLEVEL;
        //если у нас есть недопустимые модификаторы для топ-левел класса, то сбрасываем флаги
        if(tmpFlags != 0) {
            finalMods = PUBLIC;
        }
    }


    if(finalMods & PRIVATE) {
        result += "private ";
    } else if(finalMods & PRIVATEPROTECTED) {
        result += "private protected ";
    } else if(finalMods & FILE) {
        result += "file ";
    } else if(finalMods & PROTECTED) {
        result += "protected ";
    } else if(finalMods & INTERNAL) {
        result += "internal ";
    } else if(finalMods & PROTECTEDINTERNAL) {
        result += "protected internal ";
    } else if(finalMods & PUBLIC) {
        result += "public ";
    }

    result += "class " + m_name + " {\n";

    for(auto &f: m_fields) {
        result += f->compile(level + 1) + "\n";
    }

    result += generateShift(level) + "}\n;";
    return result;
}
