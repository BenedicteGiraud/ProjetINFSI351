#ifndef HEADBAND_ITEM_H
#define HEADBAND_ITEM_H
#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QMouseEvent>
#include <iostream>
#include <QIcon>
#include <math.h>
#include <QTextStream>
#include "label_select.h"


class Headband_Item : public QWidget
{

    Q_OBJECT

public:
    Headband_Item(QWidget* parent) : QWidget(parent){}
    Headband_Item(QWidget* parent, QString name, QString price);
    virtual void displayNormal()=0;
    virtual void displayExtensible()=0;
    QString name;
    QString price;

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    QString filePath;
    bool extensible;
    QWidget* widgetNormal;
    QWidget* widgetExtensible;
    QStackedLayout* stack_layout;
    bool move;
    int dx;
    static const int V = 3;
    QPoint pos;
    QPoint init;

signals:
    void scrolling(int dx);
    void setNormalMode();
    void setExtensibleMode(Headband_Item* w);
};

#endif // HEADBAND_ITEM_H
