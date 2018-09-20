#include "AbstractApplicationManager.h"

AbstractApplicationManager::AbstractApplicationManager(const QString& qmlFile, QObject* parent)
    : AbstractManager(parent)
    , mViewManager(qmlFile)
{}

bool AbstractApplicationManager::initialize()
{
    bool ok = initializeManagers();
    Q_ASSERT(ok);

    registerMetatypes();

    ok = ok && mViewManager.initialize();
    Q_ASSERT(ok);

    return ok;
}

bool AbstractApplicationManager::initializeManagers()
{
    return true;
}
