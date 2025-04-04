QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/headers/Cpp \
               $$PWD/headers/Cs \
               $$PWD/headers/Java \
               $$PWD/headers

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

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
