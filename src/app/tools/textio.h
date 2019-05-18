#ifndef TEXTIO_H
#define TEXTIO_H

#include <QFile>
#include <QTextStream>

class TextIo
{
public:
    TextIo();
    ~TextIo();

    bool exits(const QString &file);

    bool openFile(const QString &file, QFile::OpenMode openMode);
    void closeFile();

    int lineCount() const;

    QStringList outBlock() const;
    QString outLine(int index) const;

    bool inBlock(const QStringList &block);
    bool inLine(const QString &line);

private:
    void readData();
    bool isOpenMode(QFile::OpenMode openMode);

    QFile *m_file;
    QTextStream m_textStrem;
    QStringList m_data;
};

#endif // TEXTIO_H
