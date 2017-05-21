#include "list.h"
#include "managewindow.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QVariantMap>
#include <QString>
#include <QJsonDocument>
#include <qDebug>
#include <QVariantList>
#include <QMap>

List::List(QObject *parent) : QObject(parent)
{
    m_win = (ManageWindow *)parent;
}

void List::AddWid(QString str){

    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
   // qDebug() << "QJsonDocument" << doc;
    QVariantMap result;

    QList<QVariant> temp;

    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            result = doc.toVariant().toMap();
        }
        else
        {
            qDebug() << "Document is not an object" << endl;
        }
    }
    else
    {
        qDebug() << "Invalid JSON...\n" << str << endl;
    }

    temp = result["data"].toList();

    //qDebug() << "QVariantMap" << result["data"].toList().type();

    //qDebug() << "QVariantMap" << temp.at(0).toMap().find("address").value();

    m_win->setText(temp);

}
