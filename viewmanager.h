#pragma once
#include <QObject>
#include <sqlite.h>
class ViewManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Winnernumber READ Winnernumber WRITE setWinnernumber)
    Q_PROPERTY(QString CountDatabse READ CountDatabse WRITE setCountDatabse)
public:
    explicit ViewManager(QObject *parent=0);
    QString Winnernumber() {return m_winner;};
    void setWinnernumber(QString value) {m_winner = value;};
    int winnerCode;


    QString CountDatabse(){return m_CountDatabse;};
    void setCountDatabse(QString val){m_CountDatabse = val;};


    Q_INVOKABLE void getPeopleNumber(QString value);
public slots:
    void save();
    void start();
private:
    QString m_winner = 0;
    QString m_CountDatabse = 0;
    explicit ViewManager(const ViewManager& rhs) = delete;
    ViewManager& operator= (const ViewManager& rhs) = delete;
};


