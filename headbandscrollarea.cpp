#include "headbandscrollarea.h"

/*
 *  Auteur: SimonTPT
 **/

using namespace std;

HeadbandScrollArea::HeadbandScrollArea(QWidget *parent, bool normal):QScrollArea(parent)
{
    //Rend les scrollbar invisibles
    horizontalScrollBar()->setStyleSheet("QScrollBar {height:0px;}");
    verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
    this->normal = normal;
    cout << normal << endl;
    //Le widget à l'intérieur prend ainsi toute la palce
    setWidgetResizable(true);
}

void HeadbandScrollArea::scrollContent(int dx, int dy)
{

    //Déplacement du widget à l'intérieur
    //On verifie qul'on ne se deplace pas d'une taille plus grande que le widget lui meme
    //On rajoute un petit ofset pour que l'on ne s'arrete pas jsute à lalimiet d'un headband_item, masi juste un peu plus loin
    int u = widget()->x() + dx;
    int v = widget()->x() + widget()->width() - this->width() + dx;

    if( u <= 0 && ( v >= -4 ) ){
        this->viewport()->scroll(dx,dy);
        // cout << widget()->x() + widget()->width()- this->width() << endl;
    }
}

void HeadbandScrollArea::arrowClicked(QString name)
{
    //Déplacement a l'extrémité de la liste dans la scrollArea
    int dx = 0;
    //cout << normal << endl;
    if(name == "arrowL" && normal)
    {
        while(widget()->x() < 0)
        {
            dx ++;
            //cout << dx << endl;
            while( (widget()->x()+dx) > 0)
            {
                dx --;
                // cout << dx << endl;
            }
            //cout << dx << endl;

            this->viewport()->scroll(dx,0);
        }
    }
    else if (name == "arrowR" && normal)
    {
        while( widget()->x() + widget()->width() - this->width() > -4 )
        {
            dx --;
            // cout << dx << endl;
            while( widget()->x() + widget()->width() - this->width() + dx < -4 )
            {
                dx ++;
                //cout << dx << endl;
            }
            this->viewport()->scroll(dx,0);
        }
    }
}



