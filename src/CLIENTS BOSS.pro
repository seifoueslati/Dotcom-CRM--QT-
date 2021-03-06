#-------------------------------------------------
#
# Project created by QtCreator 2017-10-25T22:07:43
#
#-------------------------------------------------

QT  += core gui
QT+= sql
QT += network
QT += qml quick
CONFIG += mobility
#QT += declarative
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


target.path = /opt/Qt5_CinematicExperience
qml.files = Qt5_CinematicExperience.qml content
qml.path = /opt/Qt5_CinematicExperience
INSTALLS += target qml

TARGET = matetbadalch
TEMPLATE =app
#SUBDIRS
#SUBDIRS += CLIENTS BOSS Qt5_CinematicExperience
# Use ordered build, from first subdir (project_a) to the last (project_b):

#CONFIG += ordered
SOURCES += main.cpp\
    clients.cpp \
    mainwinow.cpp \
    bdd.cpp \
    smtp.cpp \
    eml.cpp \
    gestclient.cpp \
    employe.cpp \
    classemploye.cpp \
    qcustomplot.cpp \
    aftersale.cpp \
    raport.cpp \
    gestproduit.cpp \
    produit.cpp \
    special_button.cpp \
    login.cpp \
    notification.cpp \
    commande.cpp \
    gestioncommande.cpp

HEADERS  += \
    clients.h \
    mainwindow.h \
    bdd.h \
    smtp.h \
    eml.h \
    gestclient.h \
    employe.h \
    classemploye.h \
    qcustomplot.h \
    aftersale.h \
    raport.h \
    gestproduit.h \
    produit.h \
    special_button.h \
    login.h \
    notification.h \
    commande.h \
    gestioncommande.h

FORMS    += \
    clients.ui \
    mainwindow.ui \
    eml.ui \
    employe.ui \
    employe.ui \
    aftersale.ui \
    produit.ui \
    login.ui \
    gestioncommande.ui

DISTFILES += \
    content/images/1.png \
    content/images/10.png \
    content/images/11.png \
    content/images/12.png \
    content/images/13.png \
    content/images/14.png \
    content/images/15.png \
    content/images/16.png \
    content/images/17.png \
    content/images/18.png \
    content/images/19.png \
    content/images/2.png \
    content/images/20.png \
    content/images/3.png \
    content/images/4.png \
    content/images/5.png \
    content/images/6.png \
    content/images/7.png \
    content/images/8.png \
    content/images/9.png \
    content/images/background.png \
    content/images/background3.png \
    content/images/button.png \
    content/images/cc-by_logo.png \
    content/images/cover_nmap.png \
    content/images/grip.png \
    content/images/info.png \
    content/images/panel_bg.png \
    content/images/particle.png \
    content/images/planet_sprite.png \
    content/images/qt_ambassador_logo.png \
    content/images/qt_logo.png \
    content/images/qt_logo2.png \
    content/images/quit_logo.png \
    content/images/sc1.png \
    content/images/sc2.png \
    content/images/sc3.png \
    content/images/sc4.png \
    content/images/sc5.png \
    content/images/settings.png \
    content/images/smoke.png \
    content/images/star.png \
    content/images/stars.png \
    content/images/stars2.png \
    content/images/switch_background.png \
    content/images/switch_frame.png \
    content/images/switch_on.png \
    content/images/switch_thumb.png \
    content/Background.qml \
    content/Button.qml \
    content/CurtainEffect.qml \
    content/DelegateItem.qml \
    content/DetailsView.qml \
    content/InfoView.qml \
    content/InfoViewItem.qml \
    content/MainView.qml \
    content/MoviesModel.qml \
    content/RatingsItem.qml \
    content/SettingsView.qml \
    content/Switch.qml
