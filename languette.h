#ifndef LANGUETTE_H
#define LANGUETTE_H
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTableWidget>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <QHeaderView>
using namespace std;

class Languette : public QWidget
{
public:
    Languette(int _width, int _height);
    Languette(int _width, int _height, QList<vector<QString> > _listCommande);
    /*enum NumMenu {Menu1, Menu2, Menu3, MenuEnfant, Carte};
    static const char *NumMenu_STRING[] = {"Menu1", "Menu2", "Menu3", "MenuEnfant", "Carte"};
    enum TypeEntree {};
    static const char *TypeEntree_STRING[] = {};
    enum TypePlat {};
    static const char *TypePlat_STRING[] = {};
    enum TypeDessert {};
    static const char *TypeDessert_STRING[] = {};*/
    vector<QString> foodItem;
    QList<vector<QString> > listCommande;

    void drawAgain();


private:
    int height;
    int width;
    vector<int > entreeIndex;
    vector<int > platIndex;
    vector<int > dessertIndex;
    vector<int > menuIndex;
    /*vector<QTableWidgetItem *> entreeItem;
    vector<QTableWidgetItem *> platItem;
    vector<QTableWidgetItem *> dessertItem;
    vector<QTableWidgetItem *> menuItem;*/

};

#endif // LANGUETTE_H
