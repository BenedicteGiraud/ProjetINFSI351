#include "headbandfactory.h"


Headband *HeadbandFactory::buildMenus(QWidget *parent)
{
    Headband* h = new Headband(parent,"Menus");

    h->addItem(new HeadBand_Menu(h, ":/Menus/menus/AlaCarte.txt"));
    h->addItem(new HeadBand_Menu(h, ":/Menus/menus/AlaCarte.txt"));
    h->addItem(new HeadBand_Menu(h, ":/Menus/menus/Menu1.txt"));
    h->addItem(new HeadBand_Menu(h, ":/Menus/menus/Menu1.txt"));
    h->addItem(new HeadBand_Menu(h, ":/Menus/menus/Menu2.txt"));
    h->addItem(new HeadBand_Menu(h, ":/Menus/menus/Menu2.txt"));
    h->addItem(new HeadBand_Menu(h, ":/Menus/menus/Menu2.txt"));

    h->addConnects();
    return h;
}

vector<Headband *> HeadbandFactory::buildCard(QWidget * parent)
{
    vector<Headband*> v;
    v.push_back(buildStarters(parent,Headband::PLUS,false));
    v.push_back(buildMainCourses(parent,Headband::PLUS,false));
    v.push_back(buildDesserts(parent,Headband::PLUS,false));

    return v;
}

vector<Headband *> HeadbandFactory::buildMenu1(QWidget * parent)
{
    //Dans le Menu 1 seuls des plats sont compris, les entrées et desserts sont en supplément
    vector<Headband*> v ;
    v.push_back(buildStarters(parent,Headband::PLUS,true));
    //Plats compris dans ce menu
    Headband * h = new Headband(parent,"Plats", Headband::PLUS, false);
    h->addItem(new Headband_Meal(h, ":/Plats/plats/spaghetti.txt",true));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/boeuf_bourguignon.txt", true));
    h->addConnects();
    v.push_back(h);
    v.push_back(buildDesserts(parent,Headband::PLUS,true));
    return v;
}

vector<Headband *> HeadbandFactory::buildMenu2(QWidget *parent)
{
    vector<Headband*> v ;
    //Entrees comprises dans le Menu
    Headband * h0 = new Headband(parent,"Entrées", Headband::PLUS, false/* L'entree fait partie du menu*/);
    h0->addItem(new Headband_Meal(h0, ":/Plats/plats/salade_nicoise.txt",true/* Cette entree est comprise dans le menu*/));
    h0->addConnects();
    v.push_back(h0);
    //Plats compris dans le Menu
    Headband * h1 = new Headband(parent,"Plats", Headband::PLUS, false);
    h1->addItem(new Headband_Meal(h1, ":/Plats/plats/spaghetti.txt", true));
    h1->addItem(new Headband_Meal(h1, ":/Plats/plats/boeuf_bourguignon.txt",true,true));
    h1->addConnects();
    v.push_back(h1);
    v.push_back(buildDesserts(parent,Headband::PLUS,true));
    return v;
}


Headband *HeadbandFactory::buildStarters(QWidget *parent, int type, bool suppl)
{
    Headband* h = new Headband(parent,"Entrées", type, suppl);

    //On ajoutes toutes les entrées disponbles à la carte dans le bandeau
    h->addItem(new Headband_Meal(h, ":/Plats/plats/salade_nicoise.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/salade_nicoise.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/salade_nicoise.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/salade_nicoise.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/salade_nicoise.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/salade_nicoise.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/salade_nicoise.txt", false, suppl));

    h->addConnects();
    return h;

}

Headband *HeadbandFactory::buildMainCourses(QWidget * parent, int type, bool suppl)
{
    Headband* h = new Headband(parent,"Plats", type, suppl);

    //On ajoutes toutes les entrées disponbles à la carte dans le bandeau
    h->addItem(new Headband_Meal(h, ":/Plats/plats/spaghetti.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/boeuf_bourguignon.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/spaghetti.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/boeuf_bourguignon.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/boeuf_bourguignon.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/spaghetti.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/spaghetti.txt", false, suppl));

    h->addConnects();
    return h;
}

Headband *HeadbandFactory::buildDesserts(QWidget * parent, int type, bool suppl)
{
    Headband* h = new Headband(parent,"Desserts", type, suppl);

    //On ajoutes toutes les entrées disponbles à la carte dans le bandeau
    h->addItem(new Headband_Meal(h, ":/Plats/plats/tarte_citron.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/creme_brulee.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/tarte_citron.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/tarte_citron.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/tarte_citron.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/creme_brulee.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/creme_brulee.txt", false, suppl));
    h->addItem(new Headband_Meal(h, ":/Plats/plats/creme_brulee.txt", false, suppl));

    h->addConnects();
    return h;
}
