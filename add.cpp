#include "add.h"
#include "addwindow.h"

#include <QString>
#include <QDebug>
#include <QObject>

Add::Add(QObject *parent) : QObject(parent)
{
    m_win = (AddWindow *)parent;
}

void Add::SayHello(const QString &username){
    Addinfo = str;
    qDebug()<<(str);
    emit GetAddInfo(Addinfo);
}

void Add::setStr(QString temp){
    str = temp;
}


