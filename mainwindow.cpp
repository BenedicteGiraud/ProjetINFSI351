#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    setFixedHeight(768); //1024
    setFixedWidth(768);

    //Define page structure
    QWidget * page = new QWidget(this);
    page->setFixedWidth(this->width());
    page->setFixedHeight(this->height());
    page->setStyleSheet("background-color:white;");
    QVBoxLayout * pageLayout = new QVBoxLayout();


    //Define the fixed header
    QWidget * header = new QWidget(page);
    header->setFixedWidth(page->width());
    QGridLayout * headerLayout = new QGridLayout();
    headerLayout->setHorizontalSpacing(2);
    headerLayout->setVerticalSpacing(2);

    QLabel * numTable = new QLabel();
    QPixmap numTableIm(":/Images/images/NumTable.png");
   // numTable->setStyleSheet("margin-right: 5px");
    numTable->setPixmap(numTableIm);
    numTable->setFixedSize(numTableIm.rect().size());

    QLabel * banner = new QLabel(header);
    QPixmap bannerIm(":/Images/images/Banner.png");
    banner->setPixmap(bannerIm);
    banner->setFixedSize(bannerIm.rect().size());

    QPushButton * pain = new QPushButton("");
    QPixmap painIm(":/Images/images/Pain.png");
    QIcon painIcon(painIm);
    pain->setIcon(painIcon);
    pain->setIconSize(painIm.rect().size());
    pain->setFixedSize(painIm.rect().size());

    QPushButton * eau = new QPushButton("");
    QPixmap eauIm(":/Images/images/eau.png");
    QIcon eauIcon(eauIm);
    eau->setIcon(eauIcon);
    eau->setIconSize(eauIm.rect().size());
    eau->setFixedSize(eauIm.rect().size());

    QPushButton * serveur = new QPushButton("");
    QPixmap serveurIm(":/Images/images/Serveur.png");
    QIcon serveurIcon(serveurIm);
    serveur->setIcon(serveurIcon);
    serveur->setIconSize(serveurIm.rect().size());
    serveur->setFixedSize(serveurIm.rect().size());


    headerLayout->addWidget(numTable, 0, 0, 2, 0);
    headerLayout->addWidget(banner, 0, 1, 2, 1);
    headerLayout->addWidget(serveur,0, 2, 2, 2);
    headerLayout->addWidget(pain, 0, 3);
    headerLayout->addWidget(eau, 1, 3);
    header->setLayout(headerLayout);


    //Define the widget containing all the meals (Tabs)
    QTabWidget * repasFrame = new QTabWidget(page);

    //For one Meal, define the widget containing all the bands
    QWidget * area = new QWidget(repasFrame);
    QScrollArea * sArea = new QScrollArea(area);
    QPalette * palette = new QPalette();
    palette->setColor(QPalette::Background, Qt::white);
    sArea->setPalette(*palette);
    sArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sArea->setFixedWidth(page->width() -20);
    sArea->setFixedHeight(page->height() - header->height() - 125);

    bands = new QWidget();
    bands->setFixedWidth(page->width() -25);
   // bands->setMinimumHeight(page->height() - header->height() - 125);
    bands->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
    bandsLayout = new QVBoxLayout(bands);
    Headband* menus = HeadbandFactory::buildMenus(bands);
    bandList.append(menus);
    bandsLayout->addWidget(menus);
    usefulLabel = new QLabel();
    bandsLayout->addWidget(usefulLabel);
    bands->setLayout(bandsLayout);
    sArea->setWidget(bands);


    repasFrame->setFixedWidth(page->width());
    repasFrame->setFixedHeight(page->height() - header->height());
    repasFrame->addTab(area, "Repas 1");
    repasFrame->addTab(new QLabel(), "+");


    //Define the confirmation button
    QPushButton * confirmButton = new QPushButton("");
    QPixmap confirmIm(":/Images/images/Confirm.jpg");
    QIcon confirmIcon(confirmIm);
    confirmButton->setIcon(confirmIcon);
    confirmButton->setIconSize(confirmIm.rect().size());
    confirmButton->setFixedSize(confirmIm.rect().size());


    //Define the 'languette' and its 'etiquette'
    QList<QList<QObject*> > bigDataList;
    languetteContainer = new LanguetteContainer(bigDataList);
    languetteContainer->setFixedSize(760, 855);
    Etiquette * etiquette = new Etiquette(languetteContainer, confirmButton, page);


    //Link final page layouts
    pageLayout->addWidget(header);
    pageLayout->addWidget(repasFrame);
    pageLayout->addWidget(etiquette);
    pageLayout->addWidget(confirmButton);
    pageLayout->addWidget(languetteContainer);
    page->setLayout(pageLayout);


    //connect all slots
    connect(etiquette, SIGNAL(updateLanguetteInfo()), this, SLOT(recapLanguette()));
    connect(menus, SIGNAL(itemSelect(Headband_Item*)), this, SLOT(changeMenu(Headband_Item*)));
    connect(confirmButton, SIGNAL(clicked()), this, SLOT(confirmMeal()));
    connect(pain, SIGNAL(clicked()), this, SLOT(callBread()));
    connect(eau, SIGNAL(clicked()), this, SLOT(callWater()));
    connect(serveur, SIGNAL(clicked()), this, SLOT(callServer()));

    setCentralWidget(page);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recapLanguette(){

     languetteContainer->languette->listCommande.clear();

    //creating the current menu
    QList<QObject*> myMenu;
    bool isSelected = false;
    bool card = false;
    vector<QString> * foodItem = new vector<QString>();
    QList<vector<QString> > *listCommande = new QList<vector<QString> >();
    if (bandList.at(0)->getItemSelected() != NULL){ //prevent the case where items are selected but no menu
        for(int w = 0 ; w < bandList.size() ; w++){
            Headband* b = bandList.at(w);
            Headband_Item* bi = b->getItemSelected();
            if (bi != NULL){
                if(b->getTitle()=="Menus" && bi->name == "A la carte")
                {
                    card = true;
                }
                else if (!(b->supp) && (b->getTitle()!="Menus") && !card && !dynamic_cast<Headband_Meal*>(bi)->getSuppl() ){
                   cout << dynamic_cast<Headband_Meal*>(bi)->getSuppl() << endl;
                    myMenu.append(new MealModel(b->getTitle(), bi->name, "Inclus"));
                    foodItem->push_back(b->getTitle());
                    foodItem->push_back(bi->name);
                    foodItem->push_back("Inclus");
                    listCommande->push_back(*foodItem);
                    foodItem->clear();

                } else {
                    myMenu.append(new MealModel(b->getTitle(), bi->name, bi->price + " €"));
                    foodItem->push_back(b->getTitle());
                    foodItem->push_back(bi->name);
                    foodItem->push_back(bi->price);
                    listCommande->push_back(*foodItem);
                    foodItem->clear();
                }
            }
            isSelected = true;
        }
    }

    // List of the menus
    QList<QList<QObject*> > bigDataList;
    if (isSelected)
        bigDataList.append(myMenu);


    languetteContainer->updateTableContent(bigDataList, *listCommande);

}


void MainWindow::changeMenu(Headband_Item* hItem){

    QString name = hItem->name;
    vector<Headband*> v;
    if (name == "Menu 1")
        v = HeadbandFactory::buildMenu1(bands);
    else if (name =="Menu 2")
        v = HeadbandFactory::buildMenu2(bands);
    else if (name == "A la carte")
        v = HeadbandFactory::buildCard(bands);

    int size = bandList.size();
    for (int k = 1 ; k < size ; k++ ){
        bandsLayout->removeWidget(bandList.at(1));
        bandList.removeAt(1);
    }

    for(unsigned int i = 0 ; i < v.size() ; i ++ )
    {
        bandsLayout->addWidget(v[i]);
        bandList.push_back(v[i]);
        connect(v[i], SIGNAL(addHeadband(Headband*)), this, SLOT(createOptionalHeadband(Headband*)));
    }

   bandsLayout->addWidget(usefulLabel);
   bands->setMinimumHeight(165 * bandList.size()+100);

}

void MainWindow::createOptionalHeadband(Headband* hband){

    bandsLayout->removeWidget(usefulLabel);
    QString title = hband->getTitle();
    Headband* band;
    if (title == "Entrées")
        band = HeadbandFactory::buildStarters(bands, Headband::MINUS, true);
    else if (title == "Plats")
        band = HeadbandFactory::buildMainCourses(bands, Headband::MINUS, true);
    else if (title == "Desserts")
        band = HeadbandFactory::buildDesserts(bands, Headband::MINUS, true);

    bandsLayout->addWidget(band);
    bandList.append(band);
    bandsLayout->addWidget(usefulLabel);
    connect(band, SIGNAL(closeRequested(Headband*)), this, SLOT(removeOptionalHeadband(Headband*)));
    bands->setMinimumHeight(165 * bandList.size() +100);


}

void MainWindow::removeOptionalHeadband(Headband* hband){

    bandsLayout->removeWidget(hband);
    bandList.removeOne(hband);
    delete(hband);
    bands->setFixedHeight(165 * bandList.size() +100);
    bands->setMinimumHeight(165 * bandList.size()+100);


}

void MainWindow::confirmMeal(){
    QMessageBox msgBox(QMessageBox::Question, "Confirmer votre repas", "Voulez-vous envoyer votre commande en cuisine ?", QMessageBox::Yes | QMessageBox::No);
    msgBox.setWindowFlags(Qt::WindowStaysOnTopHint);
    if(msgBox.exec() == QMessageBox::Yes){
        msgBox.close();
    }
}

void MainWindow::callWater(){
    QMessageBox msgBox(QMessageBox::Warning, "Service", "Une carafe d'eau vous sera apportée d'ici quelques instants !", QMessageBox::Yes);
    msgBox.setWindowFlags(Qt::WindowStaysOnTopHint);
    if(msgBox.exec() == QMessageBox::Yes){
        msgBox.close();
    }
}
void MainWindow::callBread(){
    QMessageBox msgBox(QMessageBox::Warning, "Service", "Une corbeille de pain vous sera apportée d'ici quelques instants !", QMessageBox::Yes);
    msgBox.setWindowFlags(Qt::WindowStaysOnTopHint);
    if(msgBox.exec() == QMessageBox::Yes){
        msgBox.close();
    }
}

void MainWindow::callServer(){
    QMessageBox msgBox(QMessageBox::Warning, "Service", "Un serveur arrivera à votre table d'ici quelques instants!", QMessageBox::Yes);
    msgBox.setWindowFlags(Qt::WindowStaysOnTopHint);
    if(msgBox.exec() == QMessageBox::Yes){
        msgBox.close();
    }
}


