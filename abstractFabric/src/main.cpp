#include <QCoreApplication>
#include <iostream>

#include "ICodeFactory.h"
#include "CodeFactoryCs.h"
#include "CodeFactoryCpp.h"
#include "CodeFactoryJava.h"

std::string generateProgram(const ICodefactory &factory)
{
    auto myClass = factory.createClass("MyClass", ClassCs::PUBLIC);
    auto myMethod = factory.createMethod("func1", "int", MethodCs::PRIVATE);
    myMethod->add(factory.createPrintOperator("Hello, World"), 0);
    myClass->add(myMethod, 0);
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
        CodefactoryCpp cppFactory;
        std::cout << generateProgram(cppFactory) <<std::endl;
    }
    return a.exec();
}
