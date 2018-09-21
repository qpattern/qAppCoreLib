#ifndef PERSISTENCEMACROS_H
#define PERSISTENCEMACROS_H

#define QUERY_CLEAR_TABLE(query, table) \
    if (!query.exec(QString("DELETE * FROM %1;").arg(table))) { \
        qWarning() << "Unable to clear table" << table; \
    }

#define QUERY_CREATE_TABLE(name, columns) \
    if (!query.exec(QString("CREATE TABLE %1 (%2);").arg(name).arg(columns))) { \
        qCritical() << ("Unable to create table") << name << ":" << query.lastError(); \
        Q_ASSERT(false); \
    }

#define SCHEMA_COLUMN(name, type, modifier)   QString("%1 %2 %3").arg(name).arg(type).arg(modifier)

#define VALUE_QUOTED(text)                    QString("'%1'").arg(text)

#endif // PERSISTENCEMACROS_H
