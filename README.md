# Code Generator with Abstract Factory Pattern

Этот проект представляет собой генератор кода, реализованный с использованием паттерна «Абстрактная фабрика». Генерация кода поддерживается для нескольких языков программирования: C++, C#, Java. Проект построен разделяет реализацию для каждого языка в отдельных модулях.

---

## Структура проекта

Проект организован по следующей схеме:

- **src/** – исходные файлы (*.cpp*)
  - **Cpp/** – реализация генерации кода для C++
  - **Cs/** – реализация генерации кода для C#
  - **Java/** – реализация генерации кода для Java

- **headers/** – заголовочные файлы (*.h*)
  - **Cpp/** – объявления классов для генерации C++ кода (например, `ClassCpp.h`, `MethodCpp.h`, `PrintOperatorCpp.h`)
  - **Cs/** – объявления классов для генерации C# кода (например, `ClassCs.h`, `MethodCs.h`, `PrintOperatorCs.h`)
  - **Java/** – объявления классов для генерации Java кода (например, `ClassJava.h`, `MethodJava.h`, `PrintOperatorJava.h`)

- **ICodeFactory.h** – общий интерфейс абстрактной фабрики для создания элементов кода
- **CodeFactoryCs.h**, **CodeFactoryCpp.h**, **CodeFactoryJava.h** – конкретные реализации фабрики для каждого языка
- **Unit.h** – базовый класс для всех элементов синтаксического дерева

---

## Основные возможности

- **Абстрактная фабрика:** Позволяет клиентскому коду генерировать код для различных языков, не завися от конкретной реализации. Для генерации используется единый интерфейс `ICodeFactory`.
- **Поддержка нескольких языков:**  
  - C++: генерация классов, методов и операторов печати с типичными для C++ соглашениями.
  - C#: поддержка модификаторов доступа (например, `public`, `private`, `file`, `private protected`, `internal`, `protected internal`) для top-level и вложенных классов.
  - Java: генерация классов, методов и операторов печати с поддержкой модификаторов (например, `public`, `protected`, `private`, а также `static`, `final`, `abstract`). Особое внимание уделено правилу, что если в классе присутствует абстрактный метод, то класс автоматически становится `abstract`.

- **SOLID дизайн:**  
  - Каждый компонент (класс, метод, оператор) отвечает за свою часть генерации кода.
  - Легкость расширения: добавление нового языка или модификаторов не требует изменения клиентского кода.
  - Клиентский код зависит от абстракций (например, `ICodeFactory`), а не от конкретных реализаций.

---

## UML-диаграмма
![CodeGenerator](https://github.com/user-attachments/assets/ddd77446-3932-476a-b79f-99e19127ce4f)


## Сборка проекта

Проект использует [QMake](https://doc.qt.io/qt-5/qmake-manual.html) и C++17.

### Требования

- Qt (содержащий QCoreApplication и QMake)
- Компилятор, поддерживающий C++17

### Пример файла проекта (.pro)

```qmake
QT = core

CONFIG += c++17 cmdline

INCLUDEPATH += $$PWD/headers \
               $$PWD/headers/Cpp \
               $$PWD/headers/Cs \
               $$PWD/headers/Java

SOURCES += \
        src/Cpp/ClassCpp.cpp \
        src/Cs/ClassCs.cpp \
        src/Java/ClassJava.cpp \
        src/Cpp/MethodCpp.cpp \
        src/Cs/MethodCs.cpp \
        src/Java/MethodJava.cpp \
        src/Cpp/PrintOperatorCpp.cpp \
        src/Cs/PrintOperatorCs.cpp \
        src/Java/PrintOperatorJava.cpp \
        src/main.cpp

HEADERS += \
    headers/Cpp/ClassCpp.h \
    headers/Cs/ClassCs.h \
    headers/Java/ClassJava.h \
    headers/Cpp/CodeFactoryCpp.h \
    headers/Cs/CodeFactoryCs.h \
    headers/Java/CodeFactoryJava.h \
    headers/ICodeFactory.h \
    headers/Cpp/MethodCpp.h \
    headers/Cs/MethodCs.h \
    headers/Java/MethodJava.h \
    headers/Cpp/PrintOperatorCpp.h \
    headers/Cs/PrintOperatorCs.h \
    headers/Java/PrintOperatorJava.h \
    headers/Unit.h
