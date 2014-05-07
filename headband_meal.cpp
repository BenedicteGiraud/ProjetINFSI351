#include "headband_meal.h"

using namespace std;

Headband_Meal::Headband_Meal(QWidget* parent, QString _name, QString _price, QList<Label_select* > _ingredient_list, QString _image_path) : Headband_Item(parent, _name, _price)
{

    ingredients = _ingredient_list;
    image_path = _image_path;
    filePath = "";

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

Headband_Meal::Headband_Meal(QWidget* parent, QString file_path, bool menu, bool suppl) : Headband_Item(parent){

    filePath = file_path;
    this->chargeItem(file_path, menu, suppl);
    setAutoFillBackground(true);
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

void Headband_Meal::displayNormal(){

    widgetNormal = new QWidget(this);

    widgetNormal->setFixedHeight(this->parentWidget()->height()*2/3-10);
    widgetNormal->setFixedWidth(this->parentWidget()->width()*3/15);

    QVBoxLayout* principal_layout1 = new QVBoxLayout(widgetNormal);
    principal_layout1->setSpacing(0);

    QLabel* label_name = new QLabel(name);
    label_name->setAlignment(Qt::AlignCenter);
    QLabel* label_price = new QLabel(price);
    if (price == "-1"){
        label_price->setText("Inclus");
    }else{
        label_price->setText(price + " €");
    }
    label_price->setAlignment(Qt::AlignCenter);

    QIcon* icon = new QIcon(image_path);
    QPixmap pix = icon->pixmap(QSize(widgetNormal->height()*9/10,widgetNormal->height()*9/10));
    QLabel* label_im = new QLabel();
    label_im->setPixmap(pix);
    label_im->setAlignment(Qt::AlignCenter);

    principal_layout1->addWidget(label_im);
    principal_layout1->addWidget(label_name);
    principal_layout1->addWidget(label_price);

    widgetNormal->setLayout(principal_layout1);
    widgetNormal->layout()->setMargin(0);
    widgetNormal->setStyleSheet("padding:3px;background-color: #00aaee; color:white"/*Bug avec les contours, il y a superposition*/);
    label_im->setStyleSheet("border-style : none");
    label_name->setStyleSheet("border-style : none");
    label_price->setStyleSheet("border-style : none");
}

//visualisation en mode extensible
void Headband_Meal::displayExtensible(){

    widgetExtensible = new QWidget(this);

    widgetExtensible->setFixedHeight(widgetNormal->height());
    widgetExtensible->setFixedWidth(this->parentWidget()->width()*12/15);
    QGridLayout * principal_layout2 = new QGridLayout(widgetExtensible);


    QHBoxLayout * sub_layout1 = new QHBoxLayout();

    QIcon* icon = new QIcon(image_path);
    QPixmap pix = icon->pixmap(QSize(widgetExtensible->height()*8/10,widgetExtensible->height()*8/10));
    QLabel* label_im = new QLabel();
    label_im->setPixmap(pix);

    QLabel* label_name = new QLabel(name);
    QLabel* label_price = new QLabel(price);
    if (price == "-1"){
        label_price->setText("Inclus");
    }else{
        label_price->setText(price + " €");
    }

    sub_layout1->addWidget(label_im);
    sub_layout1->addWidget(label_name);
    sub_layout1->addWidget(label_price);
    label_im->setStyleSheet("border-style : none");
    label_name->setStyleSheet("border-style : none");
    label_price->setStyleSheet("border-style : none");

    // dans ce layout, tous les ingrédients désélectionnables
    QGridLayout* sub_layout2 = new QGridLayout();
    QLabel* lab = new QLabel();
    lab->setText("ingrédients : ");
    sub_layout2->addWidget(lab, 0, 0);
    lab->setStyleSheet("border-style : none");
    int i=1;
    for (QList<Label_select*>::iterator it=ingredients.begin(); it< ingredients.end(); it++){
        sub_layout2->addWidget((*it), floor(i/10) , i%10);
        (*it)->setStyleSheet("border-style : none");
        i++;
    }

    principal_layout2->addLayout(sub_layout1,0,0);
    principal_layout2->addLayout(sub_layout2, 1, 0);
    widgetExtensible->setLayout(principal_layout2);
    widgetExtensible->layout()->setMargin(0);
    widgetExtensible->setStyleSheet("padding:3px;background-color: #00aaee; color:white");
}

//lecture à partir d'un fichier des informations relative au plat
void Headband_Meal::chargeItem(QString file_path, bool menu, bool suppl){

    this->suppl = suppl;
    QFile file(qPrintable(file_path));

    if (file.open( QIODevice::ReadOnly  | QIODevice ::Text) ){
        QTextStream stream(&file);

        name = stream.readLine();

        //si c'est un menu, pas de prix ou prix supplément
        //si c'est à la carte prix normal

        if (!menu){
            price = stream.readLine();
            // on enlève le prix supplément aucun intérêt
            QString dump;
            dump = stream.readLine();
        }else{
            if (suppl){
                //on enlève le prix standard
                QString dump;
                dump = stream.readLine();
                QString interm_price;
                interm_price = stream.readLine();
                price = "+" + interm_price;
            }else{
                price = "-1";
                QString dump;
                dump = stream.readLine();
                dump = stream.readLine();
            }
        }

        image_path = stream.readLine();
        QString number_ingredient;
        number_ingredient = stream.readLine();


        ingredients.clear();
        QString temp;
        for (int i=0; i<number_ingredient.toInt(); i++){
            temp = stream.readLine();
            ingredients.push_back(new Label_select(this->parentWidget(), temp));
        }

        file.close();
    }else{
        cerr << "erreur lecture fichier" << endl;
    }
}

bool Headband_Meal::getSuppl() const
{
return suppl;
}


