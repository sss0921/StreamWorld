#ifndef STATIONGROUP_H
#define STATIONGROUP_H

#include "station.h"

class StationGroup
{
public:
    StationGroup();

    QString name() const;
    void setName(const QString &name);

    void loadGroup(const QStringList &item);
    QStringList writeGroup() const;

    int count();
    Station *station(int index);
    void addStation(Station *station);
    void deleteStation(int index);

private:
    QString m_groupName;
    QVector<Station *> m_groupData;
};

#endif // STATIONGROUP_H
