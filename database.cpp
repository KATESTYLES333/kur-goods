#include "database.h"
#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
{
    if(!QFile(DATABASE_PATH).exists()){
        restoreDataBase();
    }
    else{
       openDataBase();
    }
}

bool Database::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("server");
    db.setDatabaseName(DATABASE_PATH);
    return db.open();
}

void Database::restoreDataBase()
{
    openDataBase();
    createTables();
    insertIntoTables();
}

void Database::createTables()
{
    QSqlQuery query;
    query.exec(COUNTRIES_TABLE);
    query.exec(BRANDS_TABLE);
    query.exec(SIZES_TABLE);
    query.exec(GOODS_TABLE);
}

void Database::insertIntoTables()
{

}

bool Database::insertIntoTableCountries(QVariant country)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Countries(c_name) VALUES(:c_name)");
    query.bindValue(":c_name", country.toString());
    return query.exec();
}

bool Database::insertIntoTableBrands(QVariant brands)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Brands (brands_name) VALUES (:brands_name)");
    query.bindValue(":brands_name", brands.toString());
    return query.exec();
}

bool Database::insertIntoTableGoods(QVariant goods)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Goods(g_name) VALUES (:g_name)");
    query.bindValue(":g_name", goods.toString());
    return query.exec();
}

/*bool Database::queryRun(QSqlQuery& query, const char* table_name)
{
        if(!query.exec())
        {
            qDebug() << "error in " << table_name;
            qDebug() << query.lastError().text();
            return false;
        }
       // qDebug() << "ok";
        return true;
}*/

