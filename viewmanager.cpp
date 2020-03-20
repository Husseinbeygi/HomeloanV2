#include "viewmanager.h"

ViewManager::ViewManager(QObject *parent) :
    QObject(parent)
{
    Sqlite db;
    /* Get the Count in db: */
    int i = db.Count();
    setCountDatabse(QString::number(i));
}

void ViewManager::getPeopleNumber(QString value)
{
    QFile f;
    Sqlite db;
    int i = db.Count();
    qDebug() << value;
    qDebug() << i;
    if(i == 0){
        db.Insert(value.toInt());
    }
}

void ViewManager::save()
{
    Sqlite db;
    db.Delete(winnerCode);
}

void ViewManager::start()
{
    Sqlite db;

    /* Get the Count in db: */
    int i = db.maxid();
    qDebug() << i;
    if(i != 0){
        /* initialize random seed: */
        srand (time(NULL));

        /* generate secret number between 1 and i: */
        int rndnum = rand() % i + 1;

        /* Get Label for Generated Number: */
        QString f = db.ReadSingle(rndnum);
        qDebug() << rndnum;
        qDebug() << f;
        if (f == "0") {
            start();
        }else {

            setWinnernumber(f);
            winnerCode = rndnum;

        }
        db.Close();
    }
}

