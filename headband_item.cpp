#include "headband_item.h"

using namespace std;

Headband_Item::Headband_Item(QWidget* parent, QString _name, QString _price) : QWidget(parent)
{
    name = _name;
    price = _price;
    move = false;

    //par défaut les item ne sont pas étendus, ce sont des simples boutons au départ
    extensible = false;
    stack_layout = new QStackedLayout(this);

}

void Headband_Item::mousePressEvent(QMouseEvent *event)
{
    init = event->pos();
    pos = init;
}

void Headband_Item::mouseReleaseEvent(QMouseEvent *)
{
    //cout << "release dans item" << endl;
    if (!move)
    {
        if (extensible){
            stack_layout->setCurrentIndex(0);
            this->setFixedSize(widgetNormal->size());
            emit setNormalMode();
            extensible = false;
        }else{
            cout << widgetExtensible->width() << " " << widgetExtensible->height() << endl;
            stack_layout->setCurrentIndex(1);
            this->setFixedSize(widgetExtensible->size());
            extensible = true;
            emit setExtensibleMode(this);
        }
    }
    else
    {
        move = false;
    }
}

void Headband_Item::mouseMoveEvent(QMouseEvent * event)
{

    move = true;
    pos = event->pos();
    int newdx = pos.x()-init.x();

    //Test se basant sur l'hypothèse d'un mouvement relativement continu.
    //On évite ainsi des erreurs du aux approximations des positions qui  sont nécéssairemetn des entiers
    //Si le dx précédent et le nouveau ont meme signe, alors on valide le mouvement.
    if(dx*newdx > 0)
    {
        //if()
        emit scrolling(V*newdx);
    }
    init = pos;
    dx = newdx;
    //cout << dx << endl;
}

