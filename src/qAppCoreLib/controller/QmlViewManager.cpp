#include "QmlViewManager.h"

#include <QQmlContext>

QmlViewManager::QmlViewManager(const QString& qmlFile, QObject* parent)
    : AbstractManager(parent)
    , mQmlFile(qmlFile)
{}

bool QmlViewManager::initialize()
{
    mEngine.addImportPath("qrc:///");
    mEngine.load(QUrl(mQmlFile));
    return !mEngine.rootObjects().isEmpty();
}

void QmlViewManager::reset()
{}

void QmlViewManager::setContextProperty(const QString& name, QObject* value)
{
    mEngine.rootContext()->setContextProperty(name, value);
}
