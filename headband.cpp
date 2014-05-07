#include "headband.h"

/*
 *  Auteur: SimonTPT
 **/

using namespace std;


// Constructeur pour les Bandeau de base
Headband::Headband(QWidget* parent, QString title, int type, bool supp): QWidget(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->type = type;
    this->supp = supp;
    //Taille et arrière plan
    setFixedWidth(parent->width());
    setFixedHeight(165);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);

    //Layout en grille
    gL = new QGridLayout(this);

    //QString contenat le titre (entrees,plats,...)
    this->title = title;
    if( supp )
        top = new QLabel(this->title + " ( en supplément du menu ) : ",this);
    else
        top = new QLabel(this->title + " : ",this);

    top->setAlignment(Qt::AlignHCenter);

    //Bouton de filtre
    filterLabel = new QLabel("Filtre :",this);
    filter = new QComboBox(this);
    filter->addItem("Aucun");
    filter->addItem("Nouveautés");
    filter->addItem("Spécialités");
    filter->addItem("Petits prix");

    QHBoxLayout* hbl = new QHBoxLayout();
    //Boutons pour ajouter/retirer bandeau
    if( type == PLUS)
    {
        plusOrMinus = new QPushButton("+",this);
        plusOrMinus->setFixedWidth(plusOrMinus->sizeHint().height());
        hbl->addWidget(plusOrMinus);
    }
    else if(type == MINUS)
    {
        plusOrMinus = new QPushButton("-",this);
        plusOrMinus->setFixedWidth(plusOrMinus->sizeHint().height());
        hbl->addWidget(plusOrMinus);
    }else{
        plusOrMinus = NULL;
    }

    //QWidget contenant les flèches
    arrowL = new Arrow(this,"arrowL");
    arrowR = new Arrow(this,"arrowR");

    //Au milieu on a une scrollArea contenant un scrollAreaWidget, qui contient tous les headband_item
    scrollArea = new HeadbandScrollArea(this,true);
    scrollAreaWidget = new ScrollAreaWidget(scrollArea);
    scrollArea->setWidget(scrollAreaWidget);

    //Ajout des widget au layout
    // Le layout fait : 14 cases de large et 3 cases de haut
    gL->addWidget(filterLabel,0,0,1,1);
    gL->addWidget(filter,0,1,1,2);
    gL->addWidget(top,0,1,1,12);
    gL->addLayout(hbl,0,12,1,1);
    gL->addWidget(arrowL,1,0,3,1);
    gL->addWidget(scrollArea,1,1,3,12);
    gL->addWidget(arrowR,1,13,3,1);

    itemSelected = NULL;

    this->show();
}

//Fait scroller le viewport de la scrollArea
void Headband::applyScroll(int dx)
{
    scrollArea->scrollContent(dx,0);
}

//Mode la scrollArea contient toutes les icones en petite taille
void Headband::normalMode()
{
    //On remet le titre normal, on maj l'item selectionné
    itemSelected = NULL;
    //On recree un scrollArea contenant tous les plats
    QObject::disconnect(arrowR,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    QObject::disconnect(arrowL,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    scrollArea->close();
    if( supp )
        top ->setText(this->title + " ( en supplément du menu ) : ");
    else
        top ->setText(this->title + " : ");

    scrollArea = new HeadbandScrollArea(this,true);
    scrollAreaWidget = new ScrollAreaWidget(scrollArea);
    scrollArea->setWidget(scrollAreaWidget);
    for(unsigned int i = 0; i < items.size(); i ++)
    {
        scrollAreaWidget->addHeadbandItem(items[i]);
    }
    //QObject::disconnect(scrollArea);
    QObject::connect(arrowL,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    QObject::connect(arrowR,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    gL->addWidget(scrollArea,1,1,3,12);
}

//Mode ou seul un plat est visible en "grand ecran"
void Headband::extensibleMode(Headband_Item *w)
{
    //On supprime la scrollArea courante, on met le titre "selectionné" , on maj l'item selectionné
    QObject::disconnect(arrowR,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    QObject::disconnect(arrowL,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    scrollArea->close();
    itemSelected = w;
    emit itemSelect(itemSelected);
    //On enleve le "s" à la fin du nom du bandeau pour que cela soit grammaticalemetn correct.
    QStringRef subString(&title,0,title.length()-1);
    top->setText(subString.toString() + " sélectionné(e) : ");

    //Dans ce cas, la scrollArea ne contien plus qu'un seul widget : le plat seletionné
    scrollArea = new HeadbandScrollArea(this,false);
    scrollAreaWidget = new ScrollAreaWidget(scrollArea);
    scrollArea->setWidget(scrollAreaWidget);
    scrollAreaWidget->addHeadbandItem(w);
    QObject::connect(arrowL,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    QObject::connect(arrowR,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    gL->addWidget(scrollArea,1,1,3,12);
}

void Headband::plusOrMinusClicked()
{
    if (type == PLUS)
    {
        emit addHeadband(this);
    }

    else if(type == MINUS)
    {
        //On demande confirmation avant de supprimer le bandeau
        QMessageBox msgBox(QMessageBox::Question, "Supprimer le bandeau " + title , "Voulez-vous réellement supprimer ce bandeau ? Le plat sélectionné sera perdu.", QMessageBox::Yes | QMessageBox::No);
        msgBox.setWindowFlags(Qt::WindowStaysOnTopHint);
        if(msgBox.exec() == QMessageBox::Yes){
            msgBox.close();
            emit closeRequested(this);
        }
    }
}

HeadbandScrollArea *Headband::getScrollArea() const
{
    return scrollArea;
}

void Headband::addItem(Headband_Item *item)
{
    //Tester si supplément ou pas
    //Si oui changer le prix affiché par un méthode de headbandItem
    scrollAreaWidget->addHeadbandItem(item);
    items.push_back(item);
}

void Headband::addConnects()
{
    //On connecte le bouton plusOrMinus pour qu'il envoie un signal à destinaiton de la mainWindow
    //Indiquant si l'utilisateur souhaite ajouter ou retirer un bandeau
    if(plusOrMinus != NULL)
        QObject::connect(plusOrMinus,SIGNAL(released()),this,SLOT(plusOrMinusClicked()));
    //On connecte les fleches pour qu'elle envoient à une extrémité de la liste
    QObject::connect(arrowL,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    QObject::connect(arrowR,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));

    //On connecte le scrollAreaWidget pour que l'on sache lorsuqe l'utilisateur scroll
    QObject::connect(scrollAreaWidget,SIGNAL(scrolling(int)),this,SLOT(applyScroll(int)));
    for(unsigned int i = 0 ; i<items.size() ; i++)
    {
        QObject::connect(items[i], SIGNAL(scrolling(int)),this,SLOT(applyScroll(int)));
        QObject::connect(items[i], SIGNAL(setExtensibleMode(Headband_Item*)),this, SLOT(extensibleMode(Headband_Item*)));
        QObject::connect(items[i], SIGNAL(setNormalMode()),this, SLOT(normalMode()));
    }
}

Headband_Item *Headband::getItemSelected() const
{
    return itemSelected;
}

vector<Headband_Item *> Headband::getItems() const
{
    return items;
}

QComboBox *Headband::getFilter() const
{
    return filter;
}

QString Headband::getTitle() const
{
    return title;
}

void Headband::setTitle(const QString &value)
{
    title = value;
}

bool Headband::getSupp() const
{
    return supp;
}


int Headband::getType() const
{
    return type;
}


//Methode pour griser si le bandeau n'appartient pas au menu
//Pas la bonne solution à mon avis
/*void Headband::setToGreyTint()
{
    QColor myGray = QColor(200,200,200);

    //On grise le bandeau
    this->setPalette(myGray);
    this->scrollAreaWidget->setPalette(myGray);

    //On grise les boutons
    QPalette p0 = plusOrMinus->palette();
    p0.setColor(QPalette::Window,Qt::red);
    plusOrMinus->setPalette( p0);

    //plusOrMinus->setAutoFillBackground(true);

    //On grise le titre
    QPalette p1 = top->palette();
    QBrush brush(QColor(110,110,110));
    brush.setStyle(Qt::SolidPattern);
    p1.setBrush(QPalette::Active, QPalette::WindowText, brush);
    top->setText(title + " ( en supplément du menu ) : ");
    top->setPalette(p1);

    for(unsigned int i = 0; i < items.size(); i++)
    {
        //Méthode qui rend les headbandItem grisé avec non plus le prix affiché, mais les supplément.
    }
}*/
