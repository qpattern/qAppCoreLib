#ifndef QAPPCORELIB_CONTROLLER_ABSTRACTPERSISTENCEMANAGER_H
#define QAPPCORELIB_CONTROLLER_ABSTRACTPERSISTENCEMANAGER_H

#include <QSqlDatabase>

#include <qAppCoreLib/controller/AbstractManager.h>

class AbstractPersistenceManager : public AbstractManager
{
    Q_OBJECT

public:
    explicit AbstractPersistenceManager(QObject* parent = nullptr);
    virtual ~AbstractPersistenceManager() = default;

    /**
     * @brief clearTables clears all the tables with the specified names
     * @param tablesNames list of the names of the tables to clear
     */
    void clearTables(const QStringList& tablesNames);

protected:
    /**
     * @brief initializeDb initializes the DB file
     * @param storagePath path of the DB file
     * @param driver DB driver to use (see QSqlDatabase::addDatabase for details)
     * @param connectionName name to use for the connection
     */
    void initializeDb(const QString& storagePath, const QString& driver = "QSQLITE", const QString& connectionName = "cache");

    /**
     * @brief createSchema creates the schema of the DB
     * @return true if the schema was succesfully created, false otherwise
     */
    virtual bool createSchema() = 0;

    /**
     * @brief open opens the connection with the DB
     * @return true if the connection is opened, false otherwise
     */
    bool open();

    QSqlDatabase mDb;
};

#endif // QAPPCORELIB_CONTROLLER_ABSTRACTPERSISTENCEMANAGER_H
