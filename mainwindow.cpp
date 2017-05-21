#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "managewindow.h"
#include "addwindow.h"

#include <QMenuBar>
#include <QPushButton>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Goldrone");

    //
    QString img_path = "C:/Users/kosta/Documents/List/image/drone.png";
    QImage img(img_path);
    QPixmap buf = QPixmap::fromImage(img);

    ui->label->setPixmap(buf);
    //

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddPage(){

    AddWindow *add = new AddWindow(this);
    add->show();

}

void MainWindow::DeletePage(){



}

void MainWindow::ManagePage(){

   ManageWindow *manage = new ManageWindow(this);
   manage->resize(600,500);
   manage->show();

}

