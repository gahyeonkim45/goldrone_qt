#ifndef MANAGEWINDOW_H
#define MANAGEWINDOW_H

#include "QMainWindow"
#include <QVBoxLayout>

namespace Ui {
class ManageWindow;
}

class ManageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageWindow(QWidget *parent = 0);
    ~ManageWindow();
    QVBoxLayout *listView;
    void Change(QString str);
    void setText(QList<QVariant> arr);

private:
    Ui::ManageWindow *ui;

public slots:
    void changeWindow();
    void AddPage();
    void DeletePage();
    void ManagePage();

};

#endif // MANAGEWINDOW_H
