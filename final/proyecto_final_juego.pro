QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    NivelEntrevista.cpp \
    NivelEscenaCrimen.cpp \
    NivelResolucion.cpp \
    dialogo.cpp \
    inventario.cpp \
    juego.cpp \
    lisa.cpp \
    main.cpp \
    mainwindow.cpp \
    nivel.cpp \
    objetointeractivo.cpp \
    pista.cpp \
    sospechoso.cpp

HEADERS += \
    NivelEntrevista.h \
    NivelEscenaCrimen.h \
    NivelResolucion.h \
    dialogo.h \
    inventario.h \
    juego.h \
    lisa.h \
    mainwindow.h \
    nivel.h \
    objetointeractivo.h \
    pista.h \
    sospechoso.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target