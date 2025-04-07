# Генератор кода с использованием паттерна "Абстрактная фабрика"

Этот проект представляет собой генератор кода, реализованный с использованием паттерна «Абстрактная фабрика». Генерация кода поддерживается для нескольких языков программирования: C++, C#, Java. Проект разделяет реализацию для каждого языка в отдельных модулях. 

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
  - C++: генерация классов, методов и операторов печати с типичными для C++ соглашениями. Из-за использования одного enum для модификторов, если клиент передаст в качестве модификатора метода модификатор `abstract`, то в коде такой метод станет чисто виртуальным, то есть:
```c++
virtual returnType nameMethod() = 0{}
```
Также, если на вход пришел модификаор доступа для класса (что нужно для C# и Java), то он просто проигнорируется. Есть возможность делать класс с ключевым словом `final`, то есть отнаследоваться от такого класса уже нельзя (естественно есть проверка на то, что если в класс помещается чисто виртуальный метод, то `final` не ставится).
  - C#: поддержка модификаторов доступа (например, `public`, `private`, `file`, `private protected`, `internal`, `protected internal`) для top-level и вложенных классов.
  - Java: генерация классов, методов и операторов печати с поддержкой модификаторов (например, `public`, `protected`, `private`, а также `static`, `final`, `abstract`). Особое внимание уделено правилу, что если в классе присутствует абстрактный метод, то класс автоматически становится `abstract`.

- **SOLID дизайн:**  
  - Каждый компонент (класс, метод, оператор) отвечает за свою часть генерации кода.
  - Легкость расширения: добавление нового языка или модификаторов не требует изменения клиентского кода.
  - Клиентский код зависит от абстракций (например, `ICodeFactory`), а не от конкретных реализаций.

---
## Пример клиентского кода
```c++
#include <QCoreApplication>
#include <iostream>

#include "ICodeFactory.h"
#include "CodeFactoryCs.h"
#include "CodeFactoryCpp.h"
#include "CodeFactoryJava.h"

std::string generateProgram(const ICodefactory &factory)
{
    auto myClass = factory.createClass("MyClass", Unit::FINAL, Unit::FILE);
    auto myMethod = factory.createMethod("func1", "int", Unit::ABSTRACT | Unit::STATIC | Unit::CONST);
    myMethod->add(factory.createPrintOperator("Hello, World"), 0);
    myClass->add(myMethod, Unit::PRIVATEPROTECTED);
    auto nestedClass = factory.createClass("NestedClass", Unit::ABSTRACT, Unit::PUBLIC);
    myClass->add(nestedClass, Unit::PROTECTED);
    nestedClass->add(factory.createMethod("func2", "void", Unit::ABSTRACT), Unit::PROTECTED);
    auto printMethod = factory.createMethod("printMethod", "void", Unit::FINAL);
    printMethod->add(factory.createPrintOperator("Hello, World!\\n"), 0);
    nestedClass->add(printMethod, Unit::PRIVATE);
    auto doubleNestedClass = factory.createClass("BlaBla", 0, Unit::PRIVATE);
    doubleNestedClass->add(factory.createMethod("func3", "double", Unit::VIRTUAL), Unit::PUBLIC);
    nestedClass->add(doubleNestedClass, Unit::PUBLIC);
    auto methodLog = factory.createMethod("log", "bool", Unit::STATIC | Unit::CONST);
    methodLog->add(factory.createPrintOperator("logging..."));
    myClass->add(methodLog, Unit::PROTECTEDINTERNAL);
    return myClass->compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        std::cout<<"=== C# code ===\n";
        CodeFactoryCs csFactory;
        std::cout << generateProgram(csFactory) <<std::endl;
    }
    {
        std::cout<<"=== C++ code ===\n";
        CodeFactoryCpp cppFactory;
        std::cout << generateProgram(cppFactory) <<std::endl;
    }
    {
        std::cout<<"=== Java code ===\n";
        CodeFactoryJava javaFactory;
        std::cout << generateProgram(javaFactory) <<std::endl;
    }
    return a.exec();
}

```
### Результат работы
```
=== C# code ===
file abstract class MyClass{
    protected abstract class NestedClass{
        public class BlaBla{
            public virtual double func3(){
                }

            };

        protected abstract void func2();

        private void printMethod(){
            Console.WriteLine("Hello, World!\n");
            }

        };

    private protected static int func1();

    protetcted internal static bool log(){
        Console.WriteLine("logging...");
        }

};

=== C++ code ===
class MyClass{
protected:
    class NestedClass{
    public:
        class BlaBla{
        public:
            virtual double func3() {
            }

        };

    protected:
        virtual void func2() = 0;

    private:
        void printMethod() {
            printf("Hello, World!\n");
        }

    };

private:
    static int func1() const = 0;
    static bool log() const {
        printf("logging...");
    }

};

=== Java code ===
public abstract class MyClass(){
    protected abstract class NestedClass(){
        public class BlaBla(){
            public double func3(){
            }

            };

        protected abstract void func2();

        private final void printMethod(){
            System.out.println("Hello, World!\n");
        }

        };

    private static abstract int func1();
    private static bool log(){
        System.out.println("logging...");
    }

};
```

## UML-диаграмма
![CodeGenerator (1)](https://github.com/user-attachments/assets/0c8907a4-d4af-455b-a71b-4ae706fe56fc)



## Сборка проекта

Проект использует [QMake](https://doc.qt.io/qt-5/qmake-manual.html) и C++17.

### Требования

- Qt
- Компилятор, поддерживающий C++17
