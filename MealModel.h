
#ifndef MealModel_H
#define MealModel_H

#include <QObject>

class MealModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString type READ type WRITE settype NOTIFY typeChanged)
    Q_PROPERTY(QString name READ name WRITE setname NOTIFY nameChanged)
    Q_PROPERTY(QString price READ price WRITE setprice NOTIFY priceChanged)

public:
    MealModel(QObject *parent=0);
    MealModel(const QString &type, const QString &name, const QString &price, QObject *parent=0);

    QString type() const;
    void settype(const QString &type);

    QString name() const;
    void setname(const QString &name);

    QString price() const;
    void setprice(const QString &price);

signals:
    void nameChanged();
    void typeChanged();
    void priceChanged();

private:
    QString m_type;
    QString m_name;
    QString m_price;
};

#endif // MealModel_H
