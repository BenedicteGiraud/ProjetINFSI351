#include <QDebug>
 #include "MealModel.h"

 MealModel::MealModel(QObject *parent)
     : QObject(parent)
 {
 }

 MealModel::MealModel(const QString &type, const QString &name, const QString &price, QObject *parent)
     : QObject(parent), m_type(type), m_name(name), m_price(price)
 {
 }

 QString MealModel::type() const
 {
     return m_type;
 }

 void MealModel::settype(const QString &type)
 {
     if (type != m_type) {
         m_type = type;
         emit typeChanged();
     }
 }

 QString MealModel::name() const
 {
     return m_name;
 }

 void MealModel::setname(const QString &name)
 {
     if (name != m_name) {
         m_name = name;
         emit nameChanged();
     }
 }

 QString MealModel::price() const
 {
     return m_price;
 }

 void MealModel::setprice(const QString &price)
 {
     if (price != m_price) {
         m_price = price;
         emit priceChanged();
     }
 }
