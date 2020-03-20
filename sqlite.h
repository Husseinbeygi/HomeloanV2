#pragma once
#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>


class Sqlite
{
public:
    QSqlDatabase db;
    Sqlite();
    void Insert(int lastnumber);
    void Delete(int id);
    QList<QString> ReadAll();
    QString ReadSingle(int id);
    int Count();
    int maxid();
    void Close();
private:
    explicit Sqlite(const Sqlite& rhs) = delete;
    Sqlite& operator= (const Sqlite& rhs) = delete;
};


