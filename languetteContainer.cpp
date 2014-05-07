#include "languetteContainer.h"
#include <QGraphicsObject>




LanguetteContainer::~LanguetteContainer()
{

}

LanguetteContainer::LanguetteContainer(QList<QList<QObject*> > bigDataList){

    // -------------- LAYOUT ----------------

    // Container for the widgets (main window)
    this->setFixedSize(760, 855);

    // Vertical layout
    layout = new QVBoxLayout(this);
    // No spacing between widgets
    layout->setSpacing(0);

    // ------------- HEADER VIEW -------------

    QDeclarativeView *qmlView2 = new QDeclarativeView;
    qmlView2->setSource(QUrl::fromLocalFile("top.qml"));
    qmlView2->resize(760,100);

    // Add to layout
    layout->addWidget(qmlView2);

    // Button

    QObject *object =qmlView2->rootObject();
    QObject *buttonTable = object->findChild<QObject*>("table");
    QObject::connect(buttonTable, SIGNAL(clicked()), this, SLOT(tableClick()));

    QObject *buttonTicket = object->findChild<QObject*>("ticket");
    QObject::connect(buttonTicket, SIGNAL(clicked()), this, SLOT(ticketClick()));

    // ------------ TABLE VIEW --------------

    // qml View for the different list views
    qmlView = new QDeclarativeView;

    // Creating model for the qml file from the list of menus
    QList<QVariant> menuList;
    for(int i =0;i<bigDataList.size();i++)
        menuList.append(QVariant::fromValue(bigDataList.at(i)));

    // Send the model to the qml file
    qmlView->rootContext()->setContextProperty("menuModel", QVariant::fromValue(menuList));
    qmlView->setSource(QUrl::fromLocalFile("main.qml"));

    // Set size for the list views
    qmlView->resize(760,755);

    // Add to layout
    layout->addWidget(qmlView);


    // ---------- TICKET VIEW -------------

    languette=new Languette(760,755);
    languette->resize(760,755);
    languette->setVisible(true);

    // Add to layout
    layout->addWidget(languette);
    qmlView->setVisible(false);

}

// Select Table mode

void LanguetteContainer::tableClick(){
    languette->setVisible(false);
    qmlView->setVisible(true);
}

// Select Ticket mode

void LanguetteContainer::ticketClick(){
    languette->setVisible(true);
    qmlView->setVisible(false);

}

void LanguetteContainer::updateTableContent(QList<QList<QObject*> > bigDataList, QList<vector<QString> > _listCommande){

   // qml View for the different list views
    layout->removeWidget(qmlView);
    qmlView->setVisible(false);
   qmlView = new QDeclarativeView;

   // Creating model for the qml file from the list of menus
   QList<QVariant> menuList;
   for(int i =0;i<bigDataList.size();i++)
       menuList.append(QVariant::fromValue(bigDataList.at(i)));

   // Send the model to the qml file
   qmlView->rootContext()->setContextProperty("menuModel", QVariant::fromValue(menuList));
   qmlView->setSource(QUrl::fromLocalFile("main.qml"));

   // Set size for the list views
   qmlView->resize(760,755);

   // Add to layout
   layout->addWidget(qmlView);

   bool isLanguetteVisible = languette->isVisible();
   layout->removeWidget(languette);
   languette->setVisible(false);
   languette=new Languette(760,755, _listCommande);
  // languette->resize(760,855);
   languette->setVisible(isLanguetteVisible);
   qmlView->setVisible(!isLanguetteVisible);

   // Add to layout
   layout->addWidget(languette);

}
