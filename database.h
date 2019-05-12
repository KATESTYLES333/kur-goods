#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRelation>
#include <QSqlRecord>
#include <QFile>
#include <QStandardPaths>
#include "util.h"
#include <QMessageBox>
#include <QObject>
#include "queries.h"


class Database : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase db;
public:
    explicit Database(QObject *parent = nullptr);
    bool openDataBase();
    void restoreDataBase();
    void createTables();
    void insertIntoTables();
    static bool insertIntoTableCountries(QVariant country);
    static bool insertIntoTableBrands(QVariant brands);
    static bool insertIntoTableGoods(QVariant goods);
private:
    static bool DataBasequeryRun(QSqlQuery& query, const char* table_name);
   // bool queryRun(QSqlQuery& query, const char* table_name);
signals:

public slots:
};

#endif // DATABASE_H
