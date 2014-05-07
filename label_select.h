#ifndef LABEL_SELECT_H
#define LABEL_SELECT_H
#include <QLabel>
#include <iostream>

class Label_select : public QLabel
{
public:
    Label_select(QWidget* parent=0 , QString _name ="inconnu");

private:
    bool selected;
    QString name;

protected :

    void mousePressEvent(QMouseEvent *);
};

#endif // LABEL_SELECT_H
