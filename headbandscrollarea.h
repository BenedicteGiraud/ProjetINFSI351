#ifndef HEADBANDSCROLLAREA_H
#define HEADBANDSCROLLAREA_H
#include <QScrollArea>
#include <QScrollBar>
#include <iostream>
/*
 *  Classe représentnat la scrollArea au centre du bandeau, qui contient toutes
 *  les icones des plats, entrées,...
 *
 *  Auteur: SimonTPT
 **/

class Headband;

class HeadbandScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    HeadbandScrollArea(QWidget * parent, bool normal);
    void scrollContent(int dx, int dy);

private:
    bool normal;// indique si le headband parent est en mode normal ou pas

public slots:
    void arrowClicked(QString name);
};

#endif // HEADBANDSCROLLAREA_H
