#include "languette.h"

Languette::Languette(int _width, int _height) : QWidget()
{
    width = _width;
    height = _height;

    drawAgain();

    this->setMinimumSize(_width,_height);


}

Languette::Languette(int _width, int _height, QList<vector<QString> > _listCommande){

    listCommande = _listCommande;
    width = _width;
    height = _height;

    drawAgain();

    this->setMinimumSize(_width,_height);

}

void Languette::drawAgain(){


    QTableWidget * table = new QTableWidget(this);//"QHeaderView {background-color: red;}"
    //table->setStyleSheet( "selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5, stop: 0 #FF92BB, stop: 1 white);");
    table->setShowGrid(false);
    table->verticalHeader()->hide();
    //table->horizontalHeader()->hide();
    int row = listCommande.size() +9;
    int column = 3;
    //int widthColumn = (int)(width-59)/column; //Pour des colonnes de même taille
    table->setRowCount(row);
    table->setColumnCount(column);

    int widthColumn1 = (int)(width-45)/4;
    int widthColumn2 = (int)(width-45)/4;
    int widthColumn0 = (int)(width-45) - widthColumn1 - widthColumn2;

    int xTable = 20;
    int yTable = 0;
    int widthTable = width-40;
    int heightTable = height;
    table->setGeometry(xTable,yTable,widthTable,heightTable);
    //table->resizeColumnsToContents();
    /* for (int c = 0; c < column; c++){
           table->setColumnWidth(c , widthColumn);
       }*/
    table->setColumnWidth(0 , widthColumn0);
    table->setColumnWidth(1 , widthColumn1);
    table->setColumnWidth(2 , widthColumn2);

    table->verticalHeader()->setUpdatesEnabled(false);

    for ( int i = 0; i < row; i++)
        table->verticalHeader()->resizeSection(i, 30);

    table->verticalHeader()->setUpdatesEnabled(true);
    /*QTableWidgetItem * tmp;
       vector<QTableWidgetItem *> 	tableItems;
       for (int r = 0; r < row; r++){
           for (int c = 0; c < column; c++){
               //tableItems.push_back(table->item( r, c ));
               tableItems.push_back(tmp);
           }
       }*/
    /*for(int s = 0; s < tableItems.size(); s++){
           tableItems[s]->setFlags(Qt::NoItemFlags);
       }*/
    //QTableView * tableView = new QTableView(table);
    //tableView->setEditTriggers(Qt::NoEditTriggers);////???????
    QTableWidgetItem * article = new QTableWidgetItem("Article");
    QTableWidgetItem * quantite = new QTableWidgetItem("Quantité");
    QTableWidgetItem * prix = new QTableWidgetItem("Prix");

    table->setHorizontalHeaderItem(0,article);
    table->setHorizontalHeaderItem(1,quantite);
    table->setHorizontalHeaderItem(2,prix);

    QFont font("Arial", 12, QFont::Bold);
    QFont font2("Arial", 11, QFont::Bold);

    float totalCommande = 0;
    for(int i = 0; i < listCommande.size(); i++){
        if (listCommande[i][2] != "Inclus")
            totalCommande += (listCommande[i])[2].toFloat();
        if((listCommande[i])[0] == "Entrées"){
            entreeIndex.push_back(i);
        }
        else if((listCommande[i])[0] == "Plats"){
            platIndex.push_back(i);
        }
        else if((listCommande[i])[0] == "Desserts"){
            dessertIndex.push_back(i);
        }
        else if((listCommande[i])[0] == "Menus"){
            menuIndex.push_back(i);
        }
    }


    int eSize = 0, pSize = 0, dSize = 0, mSize = 0;
    if ((entreeIndex.size()>0))
        eSize = entreeIndex.size();
    if ((platIndex.size()>0))
        pSize = platIndex.size();
    if ((dessertIndex.size()>0))
        dSize = dessertIndex.size();
    if ((menuIndex.size()>0))
        mSize = menuIndex.size();



    QTableWidgetItem * entree = new QTableWidgetItem("ENTREE(S)");
    entree->setFont(font);
    entree->setFlags(entree->flags() ^ Qt::ItemIsEditable);
    table->setItem(0,0,entree);

    for(int j = 0; j < eSize; j++){
        QTableWidgetItem * entree1 = new QTableWidgetItem(listCommande[entreeIndex[j]][1]);
        entree1->setFlags(entree1->flags() ^ Qt::ItemIsEditable);
        entree1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(j+1,0,entree1);

        QTableWidgetItem * quantite1 = new QTableWidgetItem("1");
        quantite1->setFlags(quantite1->flags() ^ Qt::ItemIsEditable);
        quantite1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(j+1,1,quantite1);

        QTableWidgetItem * prix1 = new QTableWidgetItem(listCommande[entreeIndex[j]][2]+"€");
        prix1->setFlags(prix1->flags() ^ Qt::ItemIsEditable);
        prix1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(j+1,2,prix1);

    }

    QTableWidgetItem * plat = new QTableWidgetItem("PLAT(S)");
    plat->setFont(font);
    plat->setFlags(plat->flags() ^ Qt::ItemIsEditable);
    table->setItem(eSize + 2,0,plat);
    for(unsigned int j = 0; j < pSize; j++){
        QTableWidgetItem * plat1 = new QTableWidgetItem(listCommande[platIndex[j]][1]);
        plat1->setFlags(plat1->flags() ^ Qt::ItemIsEditable);
        plat1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(eSize + 3 + j,0,plat1);

        QTableWidgetItem * quantite1 = new QTableWidgetItem("1");
        quantite1->setFlags(quantite1->flags() ^ Qt::ItemIsEditable);
        quantite1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(eSize + 3 + j,1,quantite1);

        QTableWidgetItem * prix1 = new QTableWidgetItem(listCommande[platIndex[j]][2]+"€");
        prix1->setFlags(prix1->flags() ^ Qt::ItemIsEditable);
        prix1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(eSize + 3 + j,2,prix1);

    }

    QTableWidgetItem * dessert = new QTableWidgetItem("DESSERT(S)");
    dessert->setFont(font);
    dessert->setFlags(dessert->flags() ^ Qt::ItemIsEditable);
    table->setItem(pSize+eSize+4,0,dessert);
    for(int j = 0; j < dSize; j++){
        QTableWidgetItem * dessert1 = new QTableWidgetItem(listCommande[dessertIndex[j]][1]);
        dessert1->setFlags(dessert1->flags() ^ Qt::ItemIsEditable);
        dessert1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(pSize+eSize+ 5 + j,0,dessert1);

        QTableWidgetItem * quantite1 = new QTableWidgetItem("1");
        quantite1->setFlags(quantite1->flags() ^ Qt::ItemIsEditable);
        quantite1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(pSize+eSize+ 5 + j,1,quantite1);

        QTableWidgetItem * prix1 = new QTableWidgetItem(listCommande[dessertIndex[j]][2]+"€");
        prix1->setFlags(prix1->flags() ^ Qt::ItemIsEditable);
        prix1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(pSize+eSize+ 5 + j,2,prix1);

    }

    QTableWidgetItem * menu = new QTableWidgetItem("MENU");
    menu->setFont(font);
    menu->setFlags(menu->flags() ^ Qt::ItemIsEditable);
    table->setItem(pSize+eSize+6+dSize,0,menu);
    for(int j = 0; j < mSize; j++){
        QTableWidgetItem * menu1 = new QTableWidgetItem(listCommande[menuIndex[j]][1]);
        menu1->setFlags(menu1->flags() ^ Qt::ItemIsEditable);
        menu1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(pSize+eSize+ 7 + j + dSize,0,menu1);

        QTableWidgetItem * quantite1 = new QTableWidgetItem("1");
        quantite1->setFlags(quantite1->flags() ^ Qt::ItemIsEditable);
        quantite1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(pSize+eSize+ 7 + j + dSize,1,quantite1);

        QTableWidgetItem * prix1 = new QTableWidgetItem(listCommande[menuIndex[j]][2]+"€");
        prix1->setFlags(prix1->flags() ^ Qt::ItemIsEditable);
        prix1->setTextAlignment(Qt::AlignHCenter);
        table->setItem(pSize+eSize+ 7 + j + dSize,2,prix1);

    }




    QTableWidgetItem * total = new QTableWidgetItem("TOTAL");
    total->setFont(font);
    total->setFlags(total->flags() ^ Qt::ItemIsEditable);
    table->setItem(eSize+pSize+dSize+mSize+8,0,total);

    QString tot = QString::number(totalCommande);
    QTableWidgetItem * total1 = new QTableWidgetItem(tot+"€");
    total1->setFont(font2);
    total1->setFlags(total1->flags() ^ Qt::ItemIsEditable);
    total1->setTextAlignment(Qt::AlignHCenter);
    table->setItem(eSize+pSize+dSize+mSize+8,2,total1);

}


