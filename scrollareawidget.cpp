#include "scrollareawidget.h"

/*
 *  Auteur: SimonTPT
 **/

using namespace std;

ScrollAreaWidget::ScrollAreaWidget(QWidget *parent):QWidget(parent)
{
    //setPalette(QPalette(Qt::cyan));
   // setAutoFillBackground(true);

    //Le layout est un ensemble de boxes horizontales
    bL = new QHBoxLayout(this);
    this->layout()->setMargin(0);
}

void ScrollAreaWidget::addHeadbandItem(Headband_Item *item)
{
    bL->addWidget(item);
}

//Méthodes nécessaire pour le scroll
void ScrollAreaWidget::mousePressEvent(QMouseEvent *event)
{
    init = event->pos();
    pos = init;
}
void ScrollAreaWidget::mouseMoveEvent(QMouseEvent *event)
{
    pos = event->pos();
    int newdx = pos.x()-init.x();

    //Test se basant sur l'hypothèse d'un mouvement relativement continu.
    //On évite ainsi des erreurs du aux approximations des positions qui  sont nécéssairemetn des entiers
    //Si le dx précédent et le nouveau ont meme signe, alors on valide le mouvement.
    if(dx*newdx > 0)
    {
        emit scrolling(V*newdx);
    }
    //cout << "bl " << bL->geometry().topLeft().x()  << endl;
    //cout << "this " << this->parentWidget()->geometry().topLeft().x() << endl;
    init = pos;
    dx = newdx;
}








