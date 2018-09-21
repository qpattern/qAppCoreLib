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

DISTFILES += \
    $$PWD/exportVariables.pri

android {
    DISTFILES += \
        $$PWD/platform/android/importQmakeVars.gradle \
        $$PWD/platform/android/overrideVersion.gradle
}

debug {
    VERSION = $$sprintf("%1.%2.%3.debug", $$VER_MAJ, $$VER_MIN, $$VER_PAT)
} else {
    VERSION = $$sprintf("%1.%2.%3", $$VER_MAJ, $$VER_MIN, $$VER_PAT)
}

defined(ORGANIZATION_NAME, var) {
    DEFINES += "ORGANIZATION_NAME=\\\"$$ORGANIZATION_NAME\\\""
}

defined(PACKAGE, var) {
    DEFINES += "PACKAGE=\\\"$$PACKAGE\\\""
}
