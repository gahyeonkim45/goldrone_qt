#ifndef LOCATIONINFO_H
#define LOCATIONINFO_H

#include <QObject>
#include <QPointF>
#include <QString>
#include <QVariant>

class MapWindow;

class LocationInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString droneid MEMBER Droneid NOTIFY GetDroneid)

public:
    explicit LocationInfo(QObject *parent = 0);
    QPointF m_location1;
    QPointF m_location2;
    void setStr(QString str);

private:
    MapWindow *m_win;
    QString temp;
    QString Droneid;

public slots:
    // html의 javascript로부터 호출될 시그널 함수
    // public영역이 아닌 slots 영역에 정의해야함을 주의!!!
    void sltLocationChanged(float x, float y,int i);
    void SayHello(const QString &text);

signals:
    void GetDroneid(const QString $droneid);
};

#endif // LOCATIONINFO_H
