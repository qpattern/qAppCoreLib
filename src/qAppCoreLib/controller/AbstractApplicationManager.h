#ifndef QAPPCORELIB_CONTROLLER_ABSTRACT_APPLICATION_MANAGER_H
#define QAPPCORELIB_CONTROLLER_ABSTRACT_APPLICATION_MANAGER_H

#include "AbstractManager.h"
#include "QmlViewManager.h"

class AbstractApplicationManager : public AbstractManager
{
    Q_OBJECT

public:
    explicit AbstractApplicationManager(const QString& qmlFile, QObject* parent = nullptr);

    virtual bool initialize() override;

protected:
    /**
     * @brief initializeManagers initialize all managers
     * @return true if the managers are properly initialized, false otherwise
     */
    virtual bool initializeManagers();

    /**
     * @brief registerMetatypes register c++ type to qml
     */
    virtual void registerMetatypes() = 0;

protected:
    QmlViewManager mViewManager;
};
#endif // QAPPCORELIB_CONTROLLER_ABSTRACT_APPLICATION_MANAGER_H
