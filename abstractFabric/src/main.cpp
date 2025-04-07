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
