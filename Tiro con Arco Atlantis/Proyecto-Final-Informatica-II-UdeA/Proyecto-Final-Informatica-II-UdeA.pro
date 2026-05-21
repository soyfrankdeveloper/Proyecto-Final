QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Entidades/enemigo.cpp \
    Entidades/entidad.cpp \
    Entidades/jugador.cpp \
    Entidades/personaje.cpp \
    Entidades/proyectil.cpp \
    Fisica/fisica.cpp \
    Fisica/fisicacorriente.cpp \
    Fisica/fisicasubmarina.cpp \
    IA/agenteinteligente.cpp \
    logica/juego.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Entidades/enemigo.h \
    Entidades/entidad.h \
    Entidades/jugador.h \
    Entidades/personaje.h \
    Entidades/proyectil.h \
    Fisica/fisica.h \
    Fisica/fisicacorriente.h \
    Fisica/fisicasubmarina.h \
    IA/agenteinteligente.h \
    logica/juego.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
