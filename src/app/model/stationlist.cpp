#include "stationlist.h"

StationList::StationList()
    : m_listData(QList<StationGroup *>())
{
}

bool StationList::loadDataFromFile(const QString &fileName)
{
}

bool StationList::writeDataToFile(const QString &fileName)
{
    QStringList out;

    for (auto it = m_listData.begin(); it < m_listData.end(); it++)
        out << (*it)->writeGroup();

    TextIo textIo;
    if (textIo.openFile(fileName, QFile::WriteOnly)) {
        textIo.inBlock(out);
        textIo.closeFile();

        return true;
    }

    return false;
}

int StationList::count()
{
    return m_listData.count();
}

StationGroup *StationList::stationGroup(int index) const
{
    return m_listData.at(index);
}

void StationList::addGroup(StationGroup *group)
{
    m_listData.append(group);
}

void StationList::deleteGroup(int index)
{
    m_listData.removeAt(index);
}
