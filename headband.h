#ifndef HEADBAND_H
#define HEADBAND_H
#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QComboBox>
#include <QMessageBox>
#include <QStringRef>
#include "arrow.h"
#include "scrollareawidget.h"
#include "headbandscrollarea.h"
#include "label_select.h"
#include "headband_meal.h"
#include "headband_menu.h"


/*
 *  Classe Repésentant le bandeau entier (conteneur)
 *
 *  Auteur: SimonTPT
 **/


class Headband: public QWidget
{
    Q_OBJECT

public:
    Headband(QWidget *parent, QString title, int type = -1, bool supp = false);//-1 => pas de boutons '+' ou '-' => pour les menu
    HeadbandScrollArea *getScrollArea() const;
    void addItem(Headband_Item * item);
    //Génère les connect nécessaires
    void addConnects();
    //void setToGreyTint();
    //Enum public comme cela la Mainwindow et toutes les autres classes y ont accès
    //Type de bandeau possible :
    //PLUS -> bandeau de départ, on ne peut pas le supprimer
    //MINUS -> bandeau qui a été ajouté, on peut le supprimer
    enum Type { PLUS, MINUS };

    int getType() const;

    bool getSupp() const;

    QString getTitle() const;
    void setTitle(const QString &value);

    QComboBox *getFilter() const;

    vector<Headband_Item *> getItems() const;

    Headband_Item *getItemSelected() const;

    bool supp; //vrai si le bandeau correspond à un supplément

private:
    int type; // PLUS-> bouton "+" seulement; MINUS-> bouton "-" seuelement.
    QString title;
    QLabel *top;
    QLabel* filterLabel ;
    Arrow* arrowL;
    Arrow* arrowR;
    HeadbandScrollArea *scrollArea;
    ScrollAreaWidget *scrollAreaWidget;
    QComboBox *filter;
    QPushButton *plusOrMinus;
    QGridLayout* gL;
    vector<Headband_Item*> items;
    Headband_Item * itemSelected; // Item selectionné (ie en "plein ecran")

public slots:
    void applyScroll(int dx);
    void normalMode();
    void extensibleMode(Headband_Item *w);
    void plusOrMinusClicked();

signals:
    void addHeadband(Headband *); // Si "+" est enfoncé
    void itemSelect(Headband_Item*);
    void closeRequested(Headband *);
};

#endif // HEADBAND_H
