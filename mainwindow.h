#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headband.h"
#include "etiquette.h"
#include "languetteContainer.h"
#include "headbandfactory.h"
#include <QGridLayout>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    LanguetteContainer *languetteContainer;
    QVBoxLayout * bandsLayout;
    QLabel * usefulLabel;
    QList<Headband*> bandList;
    QWidget * bands;



    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void recapLanguette();
    void changeMenu(Headband_Item* hItem);
    void createOptionalHeadband(Headband* hband);
    void removeOptionalHeadband(Headband* hband);
    void confirmMeal();
    void callWater();
    void callBread();
    void callServer();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
