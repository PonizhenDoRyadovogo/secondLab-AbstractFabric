#include "Unit.h"
#include "ClassCpp.h"
#include "MethodCpp.h"
#include "PrintOperatorCpp.h"

#include <QCoreApplication>
#include <iostream>

std::string generateProgram()
{
    ClassCpp myClass("MyClass");
    myClass.add(std::make_shared<MethodCpp>("testFunc1", "void", 0), ClassCpp::PUBLIC);
    myClass.add(std::make_shared<MethodCpp>("testFunc2", "void", MethodCpp::STATIC), ClassCpp::PRIVATE);
    myClass.add(std::make_shared<MethodCpp>("testFunc3", "void", MethodCpp::VIRTUAL | MethodCpp::CONST), ClassCpp::PUBLIC);
    auto method = std::make_shared<MethodCpp>("testFunc4", "void", MethodCpp::STATIC);
    method->add(std::make_shared<PrintOperatorCpp>("Hello, world!\\n"));
    myClass.add(method, ClassCpp::PROTECTED);
    return myClass.compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << generateProgram() <<std::endl;
    return a.exec();
}
