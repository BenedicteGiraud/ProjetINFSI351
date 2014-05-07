#ifndef ETIQUETTE_H
#define ETIQUETTE_H
#include <QLabel>
#include <QPixmap>
#include <QMouseEvent>

class Etiquette : public QLabel
{
   Q_OBJECT

    public:

        int centerX;
        int minPosY;
        int maxPosY;
        int isUp;
        QPoint * offset ;
        QWidget * languette;
        QWidget * confirmButton;
        QPixmap * langUpIm ;
        QPixmap * langDownIm ;


        Etiquette(QWidget * content, QWidget * button, QWidget * parent);
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void moveEvent(QMoveEvent * event);

    public slots:
        void initMove();

    signals:
        void updateLanguetteInfo();





};

#endif // ETIQUETTE_H
