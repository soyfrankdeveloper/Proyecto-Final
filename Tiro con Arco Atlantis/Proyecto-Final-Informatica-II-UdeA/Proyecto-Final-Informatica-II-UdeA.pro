QT += widgets

CONFIG += c++17

SOURCES += \
    Entidades/enemigo.cpp \
    Entidades/entidad.cpp \
    Entidades/jugador.cpp \
    Entidades/obstaculo.cpp \
    Entidades/personaje.cpp \
    Entidades/proyectil.cpp \
    Fisica/fisica.cpp \
    Fisica/fisicacorriente.cpp \
    Fisica/fisicasubmarina.cpp \
    IA/agenteinteligente.cpp \
    Interfaz/escenajuego.cpp \
    Nivel/Nivel.cpp \
    Nivel/Nivel1.cpp \
    Nivel/Nivel2.cpp \
    logica/juego.cpp \
    main.cpp \
    Interfaz/mainwindow.cpp

HEADERS += \
    Entidades/enemigo.h \
    Entidades/entidad.h \
    Entidades/jugador.h \
    Entidades/obstaculo.h \
    Entidades/personaje.h \
    Entidades/proyectil.h \
    Fisica/fisica.h \
    Fisica/fisicacorriente.h \
    Fisica/fisicasubmarina.h \
    IA/agenteinteligente.h \
    Interfaz/escenajuego.h \
    Nivel/Nivel.h \
    Nivel/Nivel1.h \
    Nivel/Nivel2.h \
    logica/juego.h \
    Interfaz/mainwindow.h

FORMS += \
    Interfaz/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc