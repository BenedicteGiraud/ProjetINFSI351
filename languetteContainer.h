#ifndef LANGUETTECONTAINER_H
#define LANGUETTECONTAINER_H

#include <QStringList>
#include <QVariant>
#include <QDeclarativeView>
#include <QVBoxLayout>
#include "MealModel.h"
#include <QDeclarativeContext>
#include <QPushButton>
#include "languette.h"



class LanguetteContainer : public QWidget
{
    Q_OBJECT
    
public:
    LanguetteContainer(QList<QList<QObject*> > bigDataList);
    ~LanguetteContainer();
    void updateTableContent(QList<QList<QObject*> > bigDataList, QList<vector<QString> > _listCommande);

    Languette * languette;


public slots:
    void tableClick();
    void ticketClick();

private:


    QVBoxLayout *layout;
    QDeclarativeView *qmlView;



};

#endif // LanguetteContainer_H
