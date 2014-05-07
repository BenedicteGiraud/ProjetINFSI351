#include "label_select.h"
using namespace std;


Label_select::Label_select(QWidget* parent, QString _name) : QLabel(parent)
{
    selected = true;
    name = _name;
    this->setText(_name);
}

void Label_select::mousePressEvent(QMouseEvent *)
{

    if (selected){
        //cout << "selected false" << endl;
        selected = false;
        this->setText("<s>"+name+"</s>");
    }else{
        //cout << "selected" << endl;
        selected = true;
        this->setText("<p>"+name+"</p>");
    }
}

