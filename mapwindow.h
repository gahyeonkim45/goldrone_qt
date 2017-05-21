#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include "locationinfo.h"
#include <QtWebEngineWidgets/QWebEngineView>
#include <QMainWindow>
#include <QString>

namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0);
    ~MapWindow();
    QString id; // 선택 드론 id !!!!

    void changeLocation(int i);

private:
    Ui::MapWindow *ui;

    QWebEngineView *m_view1;
    QWebEngineView *m_view2;

    LocationInfo *m_locInfo;

public slots:
    void sltAddObject();
    void SetId(QString id);

};

#endif // MAPWINDOW_H
