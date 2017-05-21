#include "sendadd.h"
#include "addwindow.h"

#include <QString>
#include <QDebug>
#include <QObject>

SendAdd::SendAdd(QObject *parent) : QObject(parent)
{
    m_win = (AddWindow *)parent;
}

void SendAdd::SayHello(const QString &username){
    Addinfo = str;
    qDebug()<<(str);
    emit GetAddInfo(Addinfo);
}

void SendAdd::setStr(QString temp){
    str = temp;
}


