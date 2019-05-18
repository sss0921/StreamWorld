#include "textio.h"

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(textIo, "StreamWorld.TextIo")

TextIo::TextIo()
    : m_file(new QFile())
    , m_data(QStringList())
{
    qCDebug(textIo) << "TextIo";
}

TextIo::~TextIo()
{
    qCDebug(textIo) << "~TextIo";
    delete m_file;
}

bool TextIo::exits(const QString &file)
{
    qCDebug(textIo) << "exits:" << file;
    return QFile::exists(file);
}

bool TextIo::openFile(const QString &file, QFile::OpenMode openMode)
{
    closeFile();

    m_file->setFileName(file);
    if (!m_file->open(openMode | QIODevice::Text)) {
        closeFile();
        qCDebug(textIo) << "file open failed!";
        return false;
    }

    m_textStrem.setDevice(m_file);

    readData();

    return true;
}

int TextIo::lineCount() const
{
    qCDebug(textIo) << "lineCount";
    if (!m_data.isEmpty())
        return m_data.count();

    return 0;
}

QStringList TextIo::outBlock() const
{
    qCDebug(textIo) << "outBlock";
    return m_data;
}

QString TextIo::outLine(int index) const
{
    qCDebug(textIo) << "outLine";
    return m_data.at(index - 1);
}

bool TextIo::inBlock(const QStringList &block)
{
    qCDebug(textIo) << "inBlock";
    // judge open mode is writeOnly
    if (!isOpenMode(QFile::WriteOnly))
        return false;

    for (auto it = block.begin(); it != block.end(); it++)
        m_textStrem << (*it) << endl;

    return true;
}

bool TextIo::inLine(const QString &line)
{
    qCDebug(textIo) << "inLine";
    // judge open mode is writeOnly
    if (!isOpenMode(QFile::WriteOnly))
        return false;

    m_textStrem << line << endl;

    return true;
}

void TextIo::closeFile()
{
    qCDebug(textIo) << "closeFile";
    m_file->close();
}

void TextIo::readData()
{
    qCDebug(textIo) << "readData";
    if (isOpenMode(QFile::ReadOnly)) {
        m_data.clear();

        while (!m_textStrem.atEnd())
            m_data.append(m_textStrem.readLine());

        closeFile();
    }
}

bool TextIo::isOpenMode(QFile::OpenMode openMode)
{
    qCDebug(textIo) << "isOpenMode" << openMode;
    if (m_file->openMode() & openMode)
        return true;

    return false;
}
