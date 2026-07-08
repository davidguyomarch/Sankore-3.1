/**
 * @file quazip.h
 * @brief Minimal QuaZip stub for compilation without the real library.
 * TODO: Replace with real QuaZip when available.
 */
#ifndef QUAZIP_H
#define QUAZIP_H

#include <QString>
#include <QIODevice>

class QuaZip
{
public:
    enum Mode { mdNotOpen, mdUnzip, mdCreate, mdAppend, mdAdd };

    QuaZip(const QString &zipName = QString()) : mZipName(zipName), mMode(mdNotOpen) {}
    ~QuaZip() {}

    bool open(Mode mode) { mMode = mode; return false; /* stub: always fails */ }
    void close() { mMode = mdNotOpen; }
    bool isOpen() const { return mMode != mdNotOpen; }
    int getZipError() const { return 0; }
    void setFileNameCodec(const char *) {}
    bool goToFirstFile() { return false; }
    bool goToNextFile() { return false; }
    bool getCurrentFileInfo(void *) { return false; }

private:
    QString mZipName;
    Mode mMode;
};

#endif // QUAZIP_H
