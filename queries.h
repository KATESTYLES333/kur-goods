#ifndef QUERIES_H
#define QUERIES_H

#define COUNTRIES_TABLE "create table Countries(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
c_name VARCHAR(255)\
)"

#define BRANDS_TABLE "create table Brands(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
brands_name VARCHAR(255)\
)"

#define SIZES_TABLE "create table Sizes(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
size_name VARCHAR(255)\
)"

#define GOODS_TABLE "create table Goods(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
g_name VARCHAR(255),\
g_price INTEGER,\
g_brand INTEGER,\
g_country INTEGER,\
FOREIGN KEY (g_brand) REFERENCES Brands (id)\
)"

#define SELECT_BRANDS "select id, brands from BRANDS"

#endif // QUERIES_H
