QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    system.cpp\
    login.cpp \
    addpackage.cpp \
    addusers.cpp \
    changepassword.cpp \
    deletepackage.cpp \
    deleteusers.cpp \
    editadmininfo.cpp \
    searchpackage.cpp \
    searchusers.cpp \
    updatepackage.cpp \
    updateusers.cpp \
    viewadmininfo.cpp
HEADERS += \
    system.h \
    login.h \
    customers.h \
    admin.h \
    tripPackages.h \
    addpackage.h \
    addusers.h \
    changepassword.h \
    deletepackage.h \
    deleteusers.h \
    editadmininfo.h \
    searchpackage.h \
    searchusers.h \
    updatepackage.h \
    updateusers.h \
    viewadmininfo.h

FORMS += \
    system.ui \
    login.ui \
    addpackage.ui \
    addusers.ui \
    changepassword.ui \
    deletepackage.ui \
    deleteusers.ui \
    editadmininfo.ui \
    searchpackage.ui \
    searchusers.ui \
    updatepackage.ui \
    updateusers.ui \
    viewadmininfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pics.qrc
