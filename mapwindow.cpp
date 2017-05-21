#include "mapwindow.h"
#include "ui_mapwindow.h"

#include <QWebChannel>
#include <QDebug>
#include <QJsonObject>
#include <QJSValue>
#include <QVariant>

MapWindow::MapWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MapWindow)
{
    ui->setupUi(this);

    setWindowTitle("Goldrone_Map");

}

MapWindow::~MapWindow()
{
    delete ui;
}

void MapWindow::SetId(QString num){

    id = num;

    qDebug() << "Map" << id;

    // HTML의 javascript로부터 데이터를 읽어올 오브젝트
    m_locInfo = new LocationInfo(this);
    m_locInfo->setStr(num);

    /** Case 2,WebVew를 직접 생성하는 경우 **/
    m_view2 = new QWebEngineView(this);   // WebView 생성
    m_view2->setUrl(QUrl("qrc:/map.html"));   // WebView에 출력할 html파일 설정
    m_view2->setGeometry(4,12,501,281);   // WebView의 위치와 크기 설정오브젝트를 직접 바로 주입
    m_view2->page()->setProperty("num",QVariant::fromValue(id));


    QWebChannel *channel = new QWebChannel(m_view2->page());
    m_view2->page()->setWebChannel(channel);

    channel->registerObject(QString("locInfo"),m_locInfo);

}

void MapWindow::changeLocation(int i)
{
    if(i == 0){
        ui->leLat01->setText(QString::number(m_locInfo->m_location1.rx()));
        ui->leLng01->setText(QString::number(m_locInfo->m_location1.ry()));
    }else if( i == 1 ){
        ui->leLat02->setText(QString::number(m_locInfo->m_location2.rx()));
        ui->leLng02->setText(QString::number(m_locInfo->m_location2.ry()));
    }
}

void MapWindow::sltAddObject()
{
    QWebChannel *channel = new QWebChannel(m_view2->page());
    m_view2->page()->setWebChannel(channel);
    channel->registerObject(QString("locInfo"),m_locInfo);
}


