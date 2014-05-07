#ifndef HEADBAND_MENU_H
#define HEADBAND_MENU_H
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
#include "headband_item.h"

class HeadBand_Menu : public Headband_Item
{
        Q_OBJECT

public:
    HeadBand_Menu(QWidget* parent, QString _name, QString _price, QString _info, QList<QLabel* > _list_entree, QList<QLabel* > _list_plat, QList<QLabel* > _list_dessert);
    HeadBand_Menu(QWidget* parent, QString file_path);
    void displayNormal();
    void displayExtensible();
    void chargeItem(QString file_path);

private :
    QString info_composition_menu; // si seulement entrée/ plat ou plat/dessert ou entree/plat/dessert
    QList<QLabel* > list_entree;
    QList<QLabel* > list_plat;
    QList<QLabel* > list_dessert;
};

#endif // HEADBAND_MENU_H
