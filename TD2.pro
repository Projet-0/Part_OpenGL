# configuration Qt
QT       += core gui

equals(QT_MAJOR_VERSION, 5) {
        QT += opengl widgets
} else:equals(QT_MAJOR_VERSION, 6) {
        QT += openglwidgets
}

TEMPLATE  = app

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
} else:macx {
        LIBS     += -framework OpenGL
} else {
        LIBS     += -lGL -lGLU
}

# nom de l'exe genere
TARGET 	  = TD2

# fichiers sources/headers
SOURCES	+= main.cpp myglwidget.cpp planet.cpp \
    cube.cpp
HEADERS += myglwidget.h planet.h \
    cube.h
