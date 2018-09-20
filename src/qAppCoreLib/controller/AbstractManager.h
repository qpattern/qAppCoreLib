#ifndef QAPPCORELIB_CONTROLLER_ABSTRACTMANAGER_H
#define QAPPCORELIB_CONTROLLER_ABSTRACTMANAGER_H

#include <QObject>

class AbstractManager : public QObject
{
    Q_OBJECT

public:
    explicit AbstractManager(QObject* parent = nullptr);

    /**
     * @brief initialize initialize the manager
     * @return true it the manager is initialized correctly, false otherwise
     */
    virtual bool initialize() = 0;

    /**
     * @brief reset reset the state of the manager
     */
    virtual void reset()      = 0;
};
#endif // QAPPCORELIB_CONTROLLER_ABSTRACTMANAGER_H
