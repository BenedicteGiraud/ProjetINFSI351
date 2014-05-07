#ifndef SCROLLAREAWIDGET_H
#define SCROLLAREAWIDGET_H
#include <QWidget>
#include <QHBoxLayout>
#include <iostream>
#include <QMouseEvent>
#include <vector>
#include "headband_item.h"
/*
 *  Classe conteneur des icones de plats. Il est ajoutée dans la scrollArea
 *
 *  Auteur: SimonTPT
 **/

using namespace std;

class ScrollAreaWidget : public QWidget
{
    Q_OBJECT
public:
    ScrollAreaWidget(QWidget* parent);
    void addHeadbandItem(Headband_Item *item);
//    void addHeadbandMenu(Headband_Menu *item);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);

private:
    QPoint init;
    QPoint pos;
    QHBoxLayout* bL;
    //Multiplicateur pour la vitesse du scrolling
    static const int V = 3;
    int dx;

signals:
    void scrolling(int dx);
};

#endif // SCROLLAREAWIDGET_H
