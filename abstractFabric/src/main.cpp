#include <QCoreApplication>
#include <iostream>

#include "ICodeFactory.h"
#include "CodeFactoryCs.h"
#include "CodeFactoryCpp.h"
#include "CodeFactoryJava.h"

std::string generateProgram(const ICodefactory &factory)
{
    auto myClass = factory.createClass("MyClass", Unit::PUBLIC);
    auto myMethod = factory.createMethod("func1", "int", Unit::PRIVATE);
    myMethod->add(factory.createPrintOperator("Hello, World"), 0);
    myClass->add(myMethod, Unit::PRIVATEPROTECTED);
    auto nestedClass = factory.createClass("NestedClass", Unit::PUBLIC);
    myClass->add(nestedClass, Unit::PROTECTED);
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
