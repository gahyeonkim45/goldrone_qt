#include "addwindow.h"
#include "sendadd.h"
#include "ui_addwindow.h"

#include <QMenuBar>
#include <QPushButton>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QDebug>
#include <QWebChannel>

AddWindow::AddWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
    setWindowTitle("Add Goldrone");

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(getAll()));

}

void AddWindow::getAll(){

    str = ui->nameEdit->toPlainText();
    str += "-";
    str += ui->latEdit->toPlainText();
    str += "-";
    str += ui->lonEdit->toPlainText();
    str += "-";
    str += ui->addressEdit->toPlainText();

    qDebug() << "getAll()" << str;

    //

    SendAdd *add = new SendAdd(this);
    add->setStr(str);


    QWebEngineView *m_view = new QWebEngineView(this);   // WebView 생성
    m_view->setUrl(QUrl("qrc:/add.html"));   // WebView에 출력할 html파일 설정

    QWebChannel *channel = new QWebChannel(m_view->page());
    m_view->page()->setWebChannel(channel);
    channel->registerObject(QString("m_Add"),add);

    m_view->setHidden(true);

    //

}


AddWindow::~AddWindow()
{
    delete ui;
}




