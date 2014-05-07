#-------------------------------------------------
#
# Project created by QtCreator 2014-04-14T12:17:36
#
#-------------------------------------------------

QT       += core gui declarative

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetIHM
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    headband.cpp \
    label_select.cpp \
    headbandscrollarea.cpp \
    headband_item.cpp \
    scrollareawidget.cpp \
    etiquette.cpp \
    MealModel.cpp \
    languette.cpp \
    languetteContainer.cpp \
    headbandfactory.cpp \
    headband_menu.cpp \
    headband_meal.cpp

HEADERS  += mainwindow.h \
    headband.h \
    arrow.h \
    label_select.h \
    headbandscrollarea.h \
    headband_item.h \
    scrollareawidget.h \
    languette.h \
    etiquette.h \
    MealModel.h \
    languette.h \
    languetteContainer.h \
    headbandfactory.h \
    headband_menu.h \
    headband_meal.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    images/plat.jpg \
    images/couleur.png \
    images/arrowR.png \
    images/arrowL.png \
    plats/spaghetti.txt \
    plats/spaghetti.jpg \
    plats/salade_nicoise.txt \
    plats/salade_nicoise.jpg \
    top.qml \
    main.qml \
    arrowL.png \
    arrowR.png

RESOURCES += \
    Ressources.qrc
