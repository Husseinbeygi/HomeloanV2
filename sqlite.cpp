#include "sqlite.h"


Sqlite::Sqlite()
{
    QFile file;
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {

        db = QSqlDatabase::addDatabase(DRIVER);
        if(file.exists("Database.db")) {
            db.setDatabaseName("Database.db");

            if(!db.open())
                qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
        } else {

            db.setDatabaseName("Database.db");

            if(!db.open()){
                qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
            }
            else
            {
                QSqlQuery query("CREATE TABLE draw (id INTEGER PRIMARY KEY, Label TEXT)");

                if(!query.isActive())
                    qWarning() << "MainWindow::DatabaseInit - ERROR: " << query.lastError().text();

            }
        }

    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}



void Sqlite::Insert(int lastnumber)
{
    QSqlQuery query;
    QString Q = "INSERT INTO draw(Label) VALUES('%0')";
    for (int i = 1;i <= lastnumber;i++) {
        if(!query.exec(Q.arg(i)))
            qWarning() << "MainWindow::Insert - ERROR: " << query.lastError().text();
    }
}

void Sqlite::Delete(int id)
{
    QSqlQuery query;
    QString Q = "DELETE FROM draw WHERE _rowid_ = %0";
    if(!query.exec(Q.arg(id)))
        qWarning() << "MainWindow::Delete - ERROR: " << query.lastError().text();
}

QList<QString> Sqlite::ReadAll()
{
    QSqlQuery query("SELECT Label FROM draw");
    QList<QString> ret;
    while (query.next())
    {
        QString name = query.value(0).toString();
        ret.append(name);
    }

    return ret;
}

QString Sqlite::ReadSingle(int id)
{
    QSqlQuery query;
    query.prepare("SELECT Label FROM draw WHERE id = ?");
    query.addBindValue(id);

    if(!query.exec())
        qWarning() << "MainWindow::OnReadSingle - ERROR: " << query.lastError().text();

    if(query.first())
        return (query.value(0).toString());
    else
        return ("0");
}

int Sqlite::Count()
{
    QSqlQuery query("SELECT COUNT(*) FROM (SELECT * FROM draw)");
    if(query.first())
        return (query.value(0).toInt());
    return 4040;
}

int Sqlite::maxid()
{
    QSqlQuery query("SELECT _rowid_ FROM draw WHERE _rowid_=(SELECT max(id) FROM draw)");
    if(query.first())
        return (query.value(0).toInt());
    return 4040;
}



void Sqlite::Close()
{
   db.close();
}
