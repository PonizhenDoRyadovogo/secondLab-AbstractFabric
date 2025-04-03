QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/headers

SOURCES += \
        src/ClassCpp.cpp \
        src/ClassCs.cpp \
        src/ClassJava.cpp \
        src/MethodCpp.cpp \
        src/MethodCs.cpp \
        src/MethodJava.cpp \
        src/PrintOperatorCpp.cpp \
        src/PrintOperatorCs.cpp \
        src/PrintOperatorJava.cpp \
        src/main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    headers/ClassCpp.h \
    headers/ClassCs.h \
    headers/ClassJava.h \
    headers/MethodCpp.h \
    headers/MethodCs.h \
    headers/MethodJava.h \
    headers/PrintOperatorCpp.h \
    headers/PrintOperatorCs.h \
    headers/PrintOperatorJava.h \
    headers/Unit.h
