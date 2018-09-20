QT *= quick quickcontrols2

INCLUDEPATH += \
    $$PWD/src

HEADERS += \
	$$PWD/src/qAppCoreLib/controller/AbstractApplicationManager.h \
	$$PWD/src/qAppCoreLib/controller/AbstractManager.h \
	$$PWD/src/qAppCoreLib/controller/QmlViewManager.h

SOURCES += \
	$$PWD/src/qAppCoreLib/controller/AbstractApplicationManager.cpp \
	$$PWD/src/qAppCoreLib/controller/AbstractManager.cpp \
    $$PWD/src/qAppCoreLib/controller/QmlViewManager.cpp
