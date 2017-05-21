#include "locationinfo.h"
#include "mapwindow.h"

#include <QVariantList>
#include <QVariant>

LocationInfo::LocationInfo(QObject *parent) : QObject(parent)
{
    m_win = (MapWindow *)parent;
}

void LocationInfo::sltLocationChanged(float x, float y,int i)
{
    if(i == 0){

        m_location1.setX(x);
        m_location1.setY(y);

    }else if(i == 1 ){

        m_location2.setX(x);
        m_location2.setY(y);

    }

    m_win->changeLocation(i);
}

void LocationInfo::setStr(QString str){
    qDebug() << "setStr" << str;
    temp = str;
}


void LocationInfo::SayHello(const QString &username){
    Droneid = temp;
    qDebug()<<(username);
    emit GetDroneid(Droneid);
}



