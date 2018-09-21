#include "AbstractPersistenceManager.h"

#include <QDebug>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>

#include <qAppCore/persistence/PersistenceMacros.h>

AbstractPersistenceManager::AbstractPersistenceManager(QObject* parent)
    : AbstractManager(parent)
{}

void AbstractPersistenceManager::clearTables(const QStringList& tablesNames)
{
    if (open()) {
        QSqlQuery query(mDb);

        for (const QString& name : tablesNames) {
            QUERY_CLEAR_TABLE(query, name)
        }

    } else {
        qCritical() << "[ERROR] <PersistenceManager::clear> Unable to open the DB connection:" << mDb.lastError();
    }
}

void AbstractPersistenceManager::initializeDb(const QString& storagePath, const QString& driver, const QString& connectionName)
{
    mDb = QSqlDatabase::addDatabase(driver, connectionName);
    mDb.setDatabaseName(storagePath);

    QDir dbDir = QFileInfo(storagePath).dir();
    if (!dbDir.exists() && !dbDir.mkpath(dbDir.absolutePath())) {
        qWarning() << ("Unable to create containing folder:") << QFileInfo(storagePath).dir().absolutePath();
    }

    qInfo() << ("<PersistenceManager::initialize> Connecting to DB:") << mDb.databaseName();
}

bool AbstractPersistenceManager::open()
{
    if (mDb.isOpen()) {
        return true;
    }
    return mDb.open();
}
