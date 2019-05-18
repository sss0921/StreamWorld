#include "stationgroup.h"

StationGroup::StationGroup()
    : m_groupName(QString())
    , m_groupData(QList<Station *>())
{
}

QString StationGroup::name() const
{
    return m_groupName;
}

void StationGroup::setName(const QString &name)
{
    m_groupName = name;
}

void StationGroup::loadGroup(const QStringList &item)
{
    for (auto it = item.begin(); it != item.end(); it++) {
        QString left = (*it).split("#").at(0);
        QString right = (*it).split("#").at(1);

        if (left == QString("groupName")) {
            m_groupName = right;
            m_groupData.clear();
        } else {
            Station *station = new Station(left, right);
            m_groupData.append(station);
        }
    }
}

QStringList StationGroup::writeGroup() const
{
    QStringList stringList;

    QString title = "groupName#" + m_groupName;
    stringList.append(title);

    for (auto it = m_groupData.begin(); it != m_groupData.end(); it++) {
        QString data = (*it)->station();
        stringList.append(data);
    }

    return stringList;
}

int StationGroup::count()
{
    return m_groupData.count();
}

Station *StationGroup::station(int index)
{
    return m_groupData[index];
}

void StationGroup::addStation(Station *station)
{
    m_groupData.append(station);
}

void StationGroup::deleteStation(int index)
{
    m_groupData.removeAt(index);
}
