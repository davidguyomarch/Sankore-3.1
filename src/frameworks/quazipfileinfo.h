#ifndef QUAZIPFILEINFO_H
#define QUAZIPFILEINFO_H

#include <QString>
#include <QDateTime>

struct QuaZipFileInfo {
    QString name;
    uint compressedSize;
    uint uncompressedSize;
    QDateTime dateTime;
};

struct QuaZipFileInfo64 {
    QString name;
    quint64 compressedSize;
    quint64 uncompressedSize;
    QDateTime dateTime;
};

#endif // QUAZIPFILEINFO_H
