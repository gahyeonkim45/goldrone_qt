#ifndef SENDADD_H
#define SENDADD_H

#include <QString>
#include <QObject>

class AddWindow;

class SendAdd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString addinfo MEMBER Addinfo NOTIFY GetAddInfo)

public:
    explicit SendAdd(QObject *parent = 0);
    void setStr(QString temp);

private:
    QString str;
    QString Addinfo;
    AddWindow *m_win;

public slots:
    // html의 javascript로부터 호출될 시그널 함수
    // public영역이 아닌 slots 영역에 정의해야함을 주의!!!
    void SayHello(const QString &text);

signals:
    void GetAddInfo(const QString $addinfo);

};

#endif // SENDADD_H
