#include "managewindow.h"
#include "ui_managewindow.h"

#include "addwindow.h"
#include "list.h"
#include "mapwindow.h"

#include <QMenuBar>
#include <QPushButton>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QDebug>
#include <QWebChannel>


ManageWindow::ManageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManageWindow)
{
    ui->setupUi(this);
    setWindowTitle("Manage Goldrone");

    // 메뉴등록
    QMenuBar *menubar = new QMenuBar();

    QMenu *editMenu = menubar->addMenu("&Edit");

    QAction *ac_add = new QAction(tr("Add"),this);
    ac_add->setShortcut(tr("Ctrl+A"));
    ac_add->setStatusTip(tr("Add Drone"));
    connect(ac_add,SIGNAL(triggered(bool)),this,SLOT(AddPage()));

    QAction *ac_delete = new QAction(tr("Delete"),this);
    ac_delete->setShortcut(tr("Ctrl+D"));
    ac_delete->setStatusTip(tr("Delete Drone"));
    connect(ac_delete,SIGNAL(triggered(bool)),this,SLOT(DeletePage()));

    editMenu->addAction(ac_add);
    editMenu->addAction(ac_delete);

    QMenu *manageMenu = menubar->addMenu("&Manage");

    QAction *ac_manage = new QAction(tr("Manage"),this);
    ac_manage->setShortcut(tr("Ctrl+M"));
    ac_manage->setStatusTip(tr("Manage Drones"));
    connect(ac_manage,SIGNAL(triggered(bool)),this,SLOT(ManagePage()));

    manageMenu->addAction(ac_manage);

    setMenuBar(menubar);
    QStatusBar *pStatusbar;
    pStatusbar = statusBar();
    //

    listView = new QVBoxLayout(this);
    List *m_list = new List(this);

    QWebEngineView *m_view = new QWebEngineView(this);   // WebView 생성
    m_view->setUrl(QUrl("qrc:/test2.html"));   // WebView에 출력할 html파일 설정

    QWebChannel *channel = new QWebChannel(m_view->page());
    m_view->page()->setWebChannel(channel);
    channel->registerObject(QString("m_List"),m_list);

    m_view->setHidden(true);


}

ManageWindow::~ManageWindow()
{
    delete ui;
}

void ManageWindow::DeletePage(){

}


void ManageWindow::AddPage(){

    AddWindow *manage = new AddWindow(this);
    manage->show();

}

void ManageWindow::ManagePage(){

    //

}

void ManageWindow::setText(QList<QVariant> arr){

    for(int i = 0; i < arr.size(); i++){
        QString str = arr.at(i).toMap().find("_id").value().toString() +"."+ arr.at(i).toMap().find("address").value().toString();
        QPushButton *button = new QPushButton(str);
        listView->addWidget(button);
        // 화면 전환!

        connect(button,SIGNAL(clicked(bool)),this,SLOT(changeWindow()));
    }

    ui->centralWidget->setLayout(listView);

}

void ManageWindow::changeWindow(){
    QPushButton *button = qobject_cast<QPushButton *>((QObject::sender()));
    QString buttonId = button->text();

    int index = 0;
    int i = 0;

    for(i = 0; i < buttonId.length(); i++){
        if(buttonId.at(i) == '.'){
            index = i;
            break;
        }
    }

    if(index == 0){
        //pass
    }else{
        buttonId.chop(buttonId.length() - index);
    }

    Change(buttonId);
}

void ManageWindow::Change(QString str){
    qDebug() << str;
    MapWindow *map = new MapWindow(this);
    map->SetId(str);
    map->show();
}


