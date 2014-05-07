#include "etiquette.h"
#include <QTimer>



Etiquette::Etiquette(QWidget * content, QWidget *button, QWidget * parent)
    : QLabel(parent)
{
    centerX = 768/2 - 100;
    minPosY = 115;
    offset = new QPoint();
    langUpIm= new QPixmap(":/Images/images/LangeutteUp.png");
    langDownIm= new QPixmap(":/Images/images/LanguetteDown.png");
    setPixmap(*langUpIm);
    setFixedSize((*langUpIm).rect().size());
    languette = content;
    confirmButton = button;
    isUp = false;
    maxPosY = parent->height()-60;
    QTimer::singleShot(50, this, SLOT(initMove()));

}

void Etiquette::mousePressEvent(QMouseEvent* event)
{
    event->accept(); // do not propagate
    if (isWindow())
        *offset = event->globalPos() - pos();
    else
        *offset = event->pos();

    //IMPORTANT if the etiquette is down and gets pressed, to be pulled to the top, then update the languette info
    if (!isUp)
        emit updateLanguetteInfo();

}

void Etiquette::mouseMoveEvent(QMouseEvent* event)
{
    event->accept(); // do not propagate
    isUp = false;

    if (isWindow()){
        QPoint newPos = event->globalPos() - *offset;
        newPos.setX(centerX);
        if (newPos.y() <= minPosY){
            newPos.setY(minPosY);
            isUp = true;
        } else if (newPos.y() >= maxPosY){
            newPos.setY(maxPosY);
        }
        move(newPos);

    } else {
        QPoint newPos = mapToParent(event->pos() - *offset);
        newPos.setX(centerX);
        if (newPos.y() <= minPosY){
            newPos.setY(minPosY);
            isUp = true;
        } else if (newPos.y() >= maxPosY){
            newPos.setY(maxPosY);
        }
        move(newPos);
    }
}

void Etiquette::mouseReleaseEvent(QMouseEvent* event)
{
    event->accept(); // do not propagate
    *offset = QPoint();
    if (!isUp){
        setPixmap(*langUpIm);
        move(centerX, maxPosY);
    } else {
        setPixmap(*langDownIm);
    }
}

void Etiquette::moveEvent(QMoveEvent * event)
{
   languette->move(languette->x(), this->y()+50);
}

void Etiquette::initMove(){
    move(centerX, maxPosY);
    confirmButton->move(2.2 * centerX, maxPosY);

}

