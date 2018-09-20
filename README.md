# Architectural pattern

This library offers some classes to implement an MVC pattern, where the model (M) and controller (C) are written in c++, while the view (V) is in QML.

In brief, this library assumes that you'll instantiate all the manager classes in one place, namely _ApplicationManager_, the main manager, which should extend _qAppCoreLib/controller/AbstractApplicationManager_.

Other managers should be private fields of such class, which will manage their life cycle, overriding three virtual methods of the base class:
* _reset_: it will reset all the internal managers;
* _initializeManagers_: it will initialize all the internal managers, in the correct order; it should return true if all of them were correctly initialized, false otherwise;
* _registerMetatypes_: it will eventually register metatypes to use in the QML code, like for instance model types.

They all should extend _qAppCoreLib/controller/AbstractManager_, and expose the internal model through _Q\_PROPERTY_s so that it is accessible from the QML code.

# How to use it

In your project's _.pro_ file, just add the following:
```make
include($$PWD/qAppCoreLib/qAppCoreLib.pri)
```

You might have to adjust the path, in case this library is not in a folder in the root of the project.

For a simple working example use the repository [qCoreAppLibExample](https://github.com/qpattern/qAppCoreLibExample).
