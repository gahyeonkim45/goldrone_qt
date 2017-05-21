#ifndef LIST_H
#define LIST_H

#include <QString>
#include <QObject>
#include <QJsonObject>
#include <QJsonValue>

class ManageWindow;

class List : public QObject
{
    Q_OBJECT

public:
    explicit List(QObject *parent = 0);

private:
    ManageWindow *m_win;

public slots:
    void AddWid(QString arr);

};

#endif // LIST_H
