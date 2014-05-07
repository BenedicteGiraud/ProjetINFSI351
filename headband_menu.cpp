#include "headband_menu.h"
#include <QListView>

using namespace std;

/*
 *  Auteur: audreyTPT
 **/

/*il s'agit de la classe qui correspond au widget affichant le menu.
 *Lorsqu'on clique dessus, le widget s'agrandit pour monter des informations supplémentaires
 *on peut alors visualiser le nom, le prix, les entrees/plats/desserts disponibles dans ce menu.
 **/

HeadBand_Menu::HeadBand_Menu(QWidget* parent, QString _name, QString _price, QString _info, QList<QLabel* > _list_entree , QList<QLabel* > _list_plat , QList<QLabel* > _list_dessert) : Headband_Item(parent, _name, _price)
{
    filePath = "";
    info_composition_menu = _info;
    list_entree = _list_entree;
    list_plat = _list_plat;
    list_dessert = _list_dessert;
    //pour créer les deux widgets
    this->displayNormal();
    this->displayExtensible();
    stack_layout->addWidget(widgetNormal);
    stack_layout->addWidget(widgetExtensible);

    //initialistion taille du widget.

    this->setLayout(stack_layout);
    this->setFixedSize(widgetNormal->size());
    this->layout()->setMargin(0);
}

//constructeur d'un menu à partir d'un fichier texte
/*on utilise un stacklayout pour placer deux widgets
*(un pour la visualisation minime et l'autre pour celle dite extensible)
*/

HeadBand_Menu::HeadBand_Menu(QWidget* parent, QString file_path) : Headband_Item(parent)
{
    filePath= file_path;
    this->chargeItem(file_path);

    if (list_entree.size() !=0 ){
        info_composition_menu += "Entrée";
    }
    if (list_plat.size() !=0 && list_entree.size() !=0){
        info_composition_menu += "/Plat";
    }else if(list_plat.size() !=0){
        info_composition_menu += "Plat";
    }
    if (list_dessert.size() !=0 ){
        info_composition_menu += "/Dessert";
    }

    //par défaut les item ne sont pas étendus, ce sont des simples boutons au départ
    extensible = false;
    stack_layout = new QStackedLayout(this);
    move = false;

    //pour créer les deux widgets
    this->displayNormal();
    this->displayExtensible();
    stack_layout->addWidget(widgetNormal);
    stack_layout->addWidget(widgetExtensible);

    this->setLayout(stack_layout);
    this->setFixedSize(widgetNormal->size());
    this->layout()->setMargin(0);

}

//visualisation mode minimale
void HeadBand_Menu::displayNormal(){

    widgetNormal = new QWidget(this);

    widgetNormal->setFixedHeight(this->parentWidget()->height()*2/3-10);
    widgetNormal->setFixedWidth(this->parentWidget()->width()*3/15);
    cout << widgetNormal->size().width() << " " << widgetNormal->size().height() << endl;

    QVBoxLayout* principal_layout1 = new QVBoxLayout(widgetNormal);

    QLabel* label_name = new QLabel(name);
    principal_layout1->addWidget(label_name);
    label_name->setAlignment(Qt::AlignCenter);
    if (price != "-1"){
        QLabel* label_price = new QLabel(price+" €");
        label_price->setAlignment(Qt::AlignCenter);
        label_price->setStyleSheet("border-style : none");
        principal_layout1->addWidget(label_price);
    }
    QLabel* label_info = new QLabel(info_composition_menu);
    principal_layout1->addWidget(label_info);
    label_info->setAlignment(Qt::AlignCenter);

    widgetNormal->setLayout(principal_layout1);
    widgetNormal->layout()->setMargin(0);
    widgetNormal->setStyleSheet("padding:3px;background-color: #00aaee; color:white");
    label_name->setStyleSheet("border-style : none");
    label_info->setStyleSheet("border-style : none");

}

//visualisation en mode extensible
void HeadBand_Menu::displayExtensible(){

    widgetExtensible = new QWidget(this);
    cout << widgetNormal->size().width() << " " << widgetNormal->size().height() << endl;
    //widgetExtensible->setFixedSize(widgetNormal->size());
    // cout << this->parentWidget()->width()*12/15 << endl;
    widgetExtensible->setFixedHeight(widgetNormal->height());
    cout << widgetExtensible->height() << endl;
    widgetExtensible->setFixedWidth(this->parentWidget()->width()*12/15);
    //cout << this->parentWidget()->width()*12/15 << endl;
    QGridLayout * principal_layout2 = new QGridLayout(widgetExtensible);

    QHBoxLayout * sub_layout1 = new QHBoxLayout();

    QLabel* label_name = new QLabel(name);
    QLabel* label_price = new QLabel(price +" €");
    if (price == "-1"){
        label_price->setText("");
    }
    QLabel* label_info = new QLabel(info_composition_menu);

    sub_layout1->addWidget(label_name);
    sub_layout1->addWidget(label_price);
    sub_layout1->addWidget(label_info);

    label_name->setStyleSheet("border-style : none");
    label_price->setStyleSheet("border-style : none");
    label_info->setStyleSheet("border-style : none");

    //dans ce layout, mettre les listes des entrees/plats/desserts disponibles
    QGridLayout* sub_layout2 = new QGridLayout();
    QLabel* lab_entree = new QLabel("Entrées : ");
    sub_layout2->addWidget(lab_entree, 0, 0);
    lab_entree->setStyleSheet("border-style : none");

    if (list_entree.size() !=0){
        for (int i =0; i<list_entree.size(); i++){
            sub_layout2->addWidget(list_entree[i], 0, 2*i+1);
            list_entree[i]->setStyleSheet("border-style : none");
            list_entree[i]->setAlignment(Qt::AlignCenter);
            if (i!=list_entree.size()-1){
                QLabel* label_ou = new QLabel("ou");
                sub_layout2->addWidget(label_ou, 0, 2*i+2);
                label_ou->setStyleSheet("border-style : none");
                label_ou->setAlignment(Qt::AlignCenter);
            }
        }
    }else{
        QLabel* label_no_entree = new QLabel("En supplément");
        sub_layout2->addWidget(label_no_entree, 0,1);
        label_no_entree->setStyleSheet("border-style : none");
    }


    QLabel* lab_plat = new QLabel("Plats : ");
    sub_layout2->addWidget(lab_plat, 1, 0);
    lab_plat->setStyleSheet("border-style : none");

    if (list_plat.size() !=0){
        for (int i =0; i<list_plat.size(); i++){
            sub_layout2->addWidget(list_plat[i], 1, 2*i+1);
            list_plat[i]->setStyleSheet("border-style : none");
            list_plat[i]->setAlignment(Qt::AlignCenter);
            if (i!=list_plat.size()-1){
                QLabel* label_ou = new QLabel("ou");
                sub_layout2->addWidget(label_ou, 1, 2*i+2);
                label_ou->setStyleSheet("border-style : none");
                label_ou->setAlignment(Qt::AlignCenter);
            }
        }
    }else{
        QLabel* label_no_plat = new QLabel("En supplément");
        sub_layout2->addWidget(label_no_plat, 1,1);
        label_no_plat->setStyleSheet("border-style : none");
    }

    QLabel* lab_dessert = new QLabel("Desserts : ");
    sub_layout2->addWidget(lab_dessert, 2, 0);
    lab_dessert->setStyleSheet("border-style :none");

    if(list_dessert.size() !=0){
        for (int i =0; i<list_dessert.size(); i++){
            sub_layout2->addWidget(list_dessert[i], 2, 2*i+1);
            list_dessert[i]->setStyleSheet("border-style : none");
            list_dessert[i]->setAlignment(Qt::AlignCenter);
            if (i!=list_dessert.size()-1){
                QLabel* label_ou = new QLabel("ou");
                sub_layout2->addWidget(label_ou, 2, 2*i+2);
                label_ou->setStyleSheet("border-style : none");
                label_ou->setAlignment(Qt::AlignCenter);
            }
        }
    }else{
        QLabel* label_no_dessert = new QLabel("En supplément");
        sub_layout2->addWidget(label_no_dessert, 2,1);
        label_no_dessert->setStyleSheet("border-style : none");
    }


    principal_layout2->addLayout(sub_layout1,0,0);
    principal_layout2->addLayout(sub_layout2, 1, 0);
    widgetExtensible->setLayout(principal_layout2);
    widgetExtensible->layout()->setMargin(0);
    widgetExtensible->setStyleSheet("padding:3px;background-color: #00aaee; color:white");
}

//lecture à partir d'un fichier des informations relative au plat
void HeadBand_Menu::chargeItem(QString file_path){

    QFile file(qPrintable(file_path));

    if (file.open( QIODevice::ReadOnly  | QIODevice ::Text) ){
        QTextStream stream(&file);
        // readLine dans le cas de noms composés

        name = stream.readLine();
        price = stream.readLine();

        QString number_entree;
        number_entree = stream.readLine();

        list_entree.clear();
        QString temp;
        for (int i=0; i<number_entree.toInt(); i++){
            temp = stream.readLine();
            list_entree.push_back(new QLabel(temp));
        }

        QString number_plat;
        number_plat = stream.readLine();

        list_plat.clear();
        for (int i=0; i<number_plat.toInt(); i++){
            temp = stream.readLine();
            list_plat.push_back(new QLabel(temp));
        }

        QString number_dessert;
        number_dessert = stream.readLine();

        list_dessert.clear();
        for (int i=0; i<number_dessert.toInt(); i++){
            temp = stream.readLine();
            list_dessert.push_back(new QLabel(temp));
        }

        file.close();
    }else{
        cerr << "erreur lecture fichier" << endl;
    }
    //cout << image_path.toStdString() << endl;

}
