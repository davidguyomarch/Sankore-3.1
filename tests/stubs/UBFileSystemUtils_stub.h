#ifndef UBFILESYSTEMUTILS_STUB_H
#define UBFILESYSTEMUTILS_STUB_H

/**
 * @file UBFileSystemUtils_stub.h
 * @brief Version allégée de UBFileSystemUtils pour les tests unitaires.
 *
 * Contient uniquement les méthodes qui ne dépendent pas de :
 * - OpenSSL (md5)
 * - QuaZip (compress/expand)
 * - UBApplication
 * - UBDocumentContainer
 */

#include <QtCore>
#include "../src/core/UB.h"

class UBFileSystemUtils : public QObject
{
    Q_OBJECT

public:
    UBFileSystemUtils();
    virtual ~UBFileSystemUtils();

    static QString removeLocalFilePrefix(QString input);

    static QString defaultTempDirPath();
    static QString createTempDir(const QString& templateString = "OpenSankoreTest", bool autoDeleteOnExit = true);
    static void deleteAllTempDirCreatedDuringSession();

    static QFileInfoList allElementsInDirectory(const QString& pDirPath);
    static QStringList allFiles(const QString& pDirPath, const bool isRecursive = true);

    static bool deleteDir(const QString& pDirPath);
    static bool deleteFilesContaining(const QString& pDirPath, const QString& pFileName);
    static bool copyDir(const QString& pSourceDirPath, const QString& pTargetDirPath);
    static bool moveDir(const QString& pSourceDirPath, const QString& pTargetDirPath);
    static bool copyFile(const QString &source, const QString &destination, bool overwrite = false);
    static bool copy(const QString &source, const QString &Destination, bool overwrite = false);
    static bool deletePath(const QString &path);
    static bool deleteFile(const QString &path);

    static void rename(const QString &path, const QString &newName);

    static QString nextAvailableDirName(const QString& filename, const QString& separator = "");
    static QString nextAvailableFileName(const QString& filename, const QString& separator = QString(""));

    static bool isPathMatch(QString path, QString source);

    static QString cleanName(const QString& name);
    static QString normalizeFilePath(const QString& pFilePath);
    static QString extension(const QString& filename);
    static QString lastPathComponent(const QString& path);
    static QString thumbnailPath(const QString& path);

    static QString mimeTypeFromFileName(const QString& filename);
    static QString fileExtensionFromMimeType(const QString& pMimeType);
    static UBMimeType::Enum mimeTypeFromString(const QString& typeString);
    static UBMimeType::Enum mimeTypeFromUrl(const QUrl& url);

    static QString getFirstExistingFileFromList(const QString& path, const QStringList& files);
    static QString readTextFile(QString path);

private:
    static QStringList sTempDirToCleanUp;
};

#endif // UBFILESYSTEMUTILS_STUB_H
