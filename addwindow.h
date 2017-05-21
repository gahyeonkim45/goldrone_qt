#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QMainWindow>
#include "sendadd.h"

namespace Ui {
class AddWindow;
}

class AddWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = 0);
    ~AddWindow();
    QString str;

public slots:
    void getAll();

private:
    Ui::AddWindow *ui;
    SendAdd *add;

};

#endif // ADDWINDOW_H
