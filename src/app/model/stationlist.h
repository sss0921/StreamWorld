#ifndef STATIONLIST_H
#define STATIONLIST_H

#include "tools/textio.h"
#include "stationgroup.h"

class StationList
{
public:
    StationList();

    bool loadDataFromFile(const QString &fileName);
    bool writeDataToFile(const QString &fileName);

    int count();
    StationGroup *stationGroup(int index) const;

    void addGroup(StationGroup *group);
    void deleteGroup(int index);

private:
    QList<StationGroup *> m_listData;
};

#endif // STATIONLIST_H
