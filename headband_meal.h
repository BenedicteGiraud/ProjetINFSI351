#ifndef HEADBAND_MEAL_H
#define HEADBAND_MEAL_H
#include <QString>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <iostream>
#include <QIcon>
#include <math.h>
#include <QTextStream>
#include "label_select.h"
#include "headband_item.h"

class Headband_Meal : public Headband_Item
{
    Q_OBJECT

public:

    Headband_Meal(QWidget* parent, QString name, QString price, QList<Label_select* > ingredient_list, QString image);
    Headband_Meal(QWidget* parent, QString file_path,bool menu, bool suppl = false);
    void displayNormal();
    void displayExtensible();
    void chargeItem(QString file_path, bool menu, bool suppl = false);

    bool getSuppl() const;

private :
    QList<Label_select* > ingredients;
    QString image_path;
    bool suppl;

};



#endif // HEADBAND_MEAL_H
