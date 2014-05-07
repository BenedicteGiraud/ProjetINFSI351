#ifndef ARROW_H
#define ARROW_H
#include <QWidget>
#include <QString>
#include <QPainter>
#include <QStyleOption>
#include <QMouseEvent>
/*
 *  Classe Repésentant un flèche
 *
 *  Auteur: SimonTPT
 **/


class Arrow: public QWidget
{
    Q_OBJECT
private :
    QString name;

public:
    Arrow(QWidget * parent, QString name):QWidget(parent)
    {
        this->name = name;
        //L'image remplit la zone qui lui est allouée
        setStyleSheet(" border-image: url(:/Images/images/"+name+".png) ");
    }

    inline void mouseReleaseEvent(QMouseEvent *)
    {
        emit click(name);
    }
    //Méthode permettant d'utiliser le stylesheet border-image, malgré le fait que
    //arrow soit un QWidget et Q_OBJET
    inline void paintEvent(QPaintEvent *)
    {
      QStyleOption o;
      o.initFrom(this);
      QPainter p(this);
      style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    }

signals:
    //Les fleches permettent d'atteindre les extrémités de la liste
    //Signaux à destination de headbandScrollArea
    void click(QString name);

};

#endif // ARROW_H
