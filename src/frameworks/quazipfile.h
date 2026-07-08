/**
 * @file quazipfile.h
 * @brief Minimal QuaZipFile stub for compilation without the real library.
 * TODO: Replace with real QuaZip when available.
 */
#ifndef QUAZIPFILE_H
#define QUAZIPFILE_H

#include <QIODevice>
#include <QString>
#include "quazip.h"

struct QuaZipFileInfo {
    QString name;
    uint compressedSize;
    uint uncompressedSize;
};

struct QuaZipNewInfo {
    QuaZipNewInfo(const QString &name, const QString &file = QString())
        : mName(name), mFile(file) {}
    QString mName;
    QString mFile;
};

#define UNZ_OK 0

class QuaZipFile : public QIODevice
{
    Q_OBJECT
public:
    QuaZipFile(QuaZip *zip = nullptr, QObject *parent = nullptr)
        : QIODevice(parent) { Q_UNUSED(zip); }
    ~QuaZipFile() {}

    bool open(QIODevice::OpenMode mode, const QuaZipNewInfo &info)
    {
        Q_UNUSED(mode); Q_UNUSED(info);
        return false;
    }
    bool open(QIODevice::OpenMode mode) override
    {
        Q_UNUSED(mode);
        return false;
    }
    void close() override {}
    int getZipError() const { return 0; }
    QString getActualFileName() const { return QString(); }

protected:
    qint64 readData(char *, qint64) override { return -1; }
    qint64 writeData(const char *, qint64) override { return -1; }
};

#endif // QUAZIPFILE_H
