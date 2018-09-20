#ifndef QAPPCORELIB_CONTROLLER_QMLVIEWMANAGER_H
#define QAPPCORELIB_CONTROLLER_QMLVIEWMANAGER_H

#include <QQmlApplicationEngine>

#include "AbstractManager.h"

class QmlViewManager : public AbstractManager
{
    Q_OBJECT

public:
    explicit QmlViewManager(const QString& qmlFile, QObject* parent = nullptr);

    virtual bool initialize() override;
    virtual void reset()      override;

    /**
     * @brief setContextProperty sets the value of the name property on the root context
     * @param name property's name
     * @param value property's value
     */
    void setContextProperty(const QString& name, QObject* value);

private:
    QQmlApplicationEngine mEngine;
    QString               mQmlFile;
};
#endif // QAPPCORELIB_CONTROLLER_QMLVIEWMANAGER_H
