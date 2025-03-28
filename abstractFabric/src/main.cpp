#include "Unit.h"
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

#include <QCoreApplication>
#include <iostream>

std::string generateProgram()
{
    ClassCpp myClass("MyClass");
    myClass.add(std::make_shared<MethodUnit>("testFunc1", "void", 0), ClassCpp::PUBLIC);
    myClass.add(std::make_shared<MethodUnit>("testFunc2", "void", MethodUnit::STATIC), ClassCpp::PRIVATE);
    myClass.add(std::make_shared<MethodUnit>("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassCpp::PUBLIC);
    auto method = std::make_shared<MethodUnit>("testFunc4", "void", MethodUnit::STATIC);
    method->add(std::make_shared<PrintOperatorUnit>("Hello, world!\\n"));
    myClass.add(method, ClassCpp::PROTECTED);
    return myClass.compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << generateProgram() <<std::endl;
    return a.exec();
}
