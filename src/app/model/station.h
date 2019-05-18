#ifndef STATION_H
#define STATION_H

#include <QStringList>

class Station
{
public:
    Station();
    Station(const QString &name, const QString &address);

    Station station() const;
    void setStatio(const Station &name);

    QString name() const;
    void setName(const QString &name);

    QString address() const;
    void setAddress(const QString &address);

private:
    QString m_name;
    QString m_address;
};

#endif // STATION_H
