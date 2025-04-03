#include "ClassJava.h"

void ClassJava::add(const std::shared_ptr<Unit>& unit, Flags flags)
{
    //ToDo: добавить проверку на то, если к нам придет абстрактный метод
    //если это так, то выставить флаг ABSTRACT
    m_fields.push_back(unit);
}

std::string ClassJava::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if(m_flags & PRIVATE) {
        result += "private ";
    }
    else if(m_flags & PUBLIC) {
        result += "public ";
    }
    else if(m_flags & PROTECTED) {
        result += "protected ";
    }
    else if(m_flags & ABSTRACT) {
        result += "abstract ";
    }

    if(m_flags & FINAL) {
        if(m_flags & ~ABSTRACT) {

        }
    }
    result += "class " + m_name;

    if

}
