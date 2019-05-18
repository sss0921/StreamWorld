#include "station.h"

Station::Station()
    : m_name(QString())
    , m_address(QString())
{
}

Station::Station(const QString &name, const QString &address)
    : m_name(name)
    , m_address(address)
{
}

QString Station::station() const
{
    return m_name + "#" + m_address;
}

void Station::setStation(const QString &station)
{
    m_name = station.split("#").at(0);
    m_address = station.split("#").at(1);
}

QString Station::name() const
{
    return m_name;
}

void Station::setName(const QString &name)
{
    m_name = name;
}

QString Station::address() const
{
    return m_address;
}

void Station::setAddress(const QString &address)
{
    m_address = address;
}
