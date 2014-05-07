#ifndef HEADBANDFACTORY_H
#define HEADBANDFACTORY_H

#include "headband.h"
/*
 *  Classe permettant l'instanciation des Bandeaux contenant les entrées, plats ou desserts.
 *
 *  Auteur: SimonTPT
 **/
class HeadbandFactory
{
public:
    //Créé un bandeau contenant toutes les entrées à la carte
    static Headband* buildMenus(QWidget * parent);
    //Renvoie les 3 bandeaux correspondants au choix à la carte
    static vector<Headband*> buildCard(QWidget * parent);
    //Renvoie les 3 bandeaux correspondants au choix pour Menu1
    static vector<Headband*> buildMenu1(QWidget * parent);
    //Renvoie les 3 bandeaux correspondants au choix pour Menu2
    static vector<Headband*> buildMenu2(QWidget * parent);

    //Créé un bandeau contenant toutes les entrées à la carte, suppl=true ==> les entrées sont un supplément au menu
    static Headband* buildStarters(QWidget * parent, int type, bool suppl);
    //Créé un bandeau contenant toutes les plats principaux à la carte, suppl=true ==> les plats sont un supplément au menu
    static Headband *buildMainCourses(QWidget * parent, int type, bool suppl);
    //Créé un bandeau contenant toutes les desserts à la carte, suppl=true ==> les desserts sont un supplément au menu
    static Headband* buildDesserts(QWidget * parent, int type , bool suppl);


};

#endif // HEADBANDFACTORY_H
