QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    HTMLHighlighter.cpp \
    JavaScriptHighlighter.cpp \
    aboutdialog.cpp \
    codeeditor.cpp \
    cxxhighlighter.cpp \
    hyperlinkhighlighter.cpp \
    main.cpp \
    mainwindow.cpp \
    pythonhighlighter.cpp \
    replacedialog.cpp \
    searchdialog.cpp

HEADERS += \
    HTMLHighlighter.h \
    JavaScriptHighlighter.h \
    aboutdialog.h \
    codeeditor.h \
    cxxhighlighter.h \
    hyperlinkhighlighter.h \
    mainwindow.h \
    pythonhighlighter.h \
    replacedialog.h \
    searchdialog.h

FORMS += \
    aboutdialog.ui \
    mainwindow.ui \
    replacedialog.ui \
    searchdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

DISTFILES += \
    style/dark.qss \
    style/light.qss
