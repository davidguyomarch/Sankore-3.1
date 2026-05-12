#include "UBFileSystemUtils_stub.h"

#include <QtGui>
#include <QDesktopServices>
#include <limits>

QStringList UBFileSystemUtils::sTempDirToCleanUp;

UBFileSystemUtils::UBFileSystemUtils() {}
UBFileSystemUtils::~UBFileSystemUtils() {}

QString UBFileSystemUtils::removeLocalFilePrefix(QString input)
{
#ifdef Q_OS_WIN
    if (input.startsWith("file:///"))
        return input.mid(8);
#else
    if (input.startsWith("file://"))
        return input.mid(7);
#endif
    return input;
}

QString UBFileSystemUtils::defaultTempDirPath()
{
    return QDir::tempPath() + "/OpenSankoreTest";
}

QString UBFileSystemUtils::createTempDir(const QString& templateString, bool autoDeleteOnExit)
{
    QString appTempDir = QDir::tempPath() + "/" + templateString;

    int index = 0;
    QDir dir;

    do {
        index++;
        QString dirName = appTempDir + QString("%1").arg(index);
        dir = QDir(dirName);
    } while (dir.exists() && index < 10000);

    dir.mkpath(dir.path());

    if (autoDeleteOnExit)
        sTempDirToCleanUp << dir.path();

    return dir.path();
}

void UBFileSystemUtils::deleteAllTempDirCreatedDuringSession()
{
    foreach (QString dirPath, sTempDirToCleanUp)
        deleteDir(dirPath);
}

bool UBFileSystemUtils::copyFile(const QString &source, const QString &destination, bool overwrite)
{
    if (!QFile::exists(source))
        return false;

    QString normalizedDestination = destination;
    if (QFile::exists(normalizedDestination)) {
        if (QFileInfo(normalizedDestination).isFile() && overwrite)
            QFile::remove(normalizedDestination);
    } else {
        normalizedDestination = normalizedDestination.replace("\\", "/");
        int pos = normalizedDestination.lastIndexOf("/");
        if (pos != -1) {
            QString newpath = normalizedDestination.left(pos);
            QDir().mkpath(newpath);
        }
    }
    return QFile::copy(source, normalizedDestination);
}

bool UBFileSystemUtils::copy(const QString &source, const QString &destination, bool overwrite)
{
    if (QFileInfo(source).isDir())
        return copyDir(source, destination);
    else
        return copyFile(source, destination, overwrite);
}

bool UBFileSystemUtils::deleteFile(const QString &path)
{
    QFile f(path);
    f.setPermissions(QFile::ReadOwner | QFile::WriteOwner);
    return f.remove();
}

bool UBFileSystemUtils::deletePath(const QString &path)
{
    if (QFileInfo(path).isFile())
        return QFile::remove(path);
    else if (QFileInfo(path).isDir())
        return deleteDir(path);
    return false;
}

QStringList UBFileSystemUtils::allFiles(const QString& pDirPath, bool isRecursive)
{
    QStringList result;
    if (pDirPath.isEmpty() || pDirPath == "." || pDirPath == "..")
        return result;

    QDir dir(pDirPath);
    foreach (QFileInfo dirContent, dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name)) {
        if (isRecursive && dirContent.isDir())
            result << allFiles(dirContent.absoluteFilePath());
        else
            result << dirContent.absoluteFilePath();
    }
    return result;
}

QFileInfoList UBFileSystemUtils::allElementsInDirectory(const QString& pDirPath)
{
    QDir dir(pDirPath);
    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    dir.setSorting(QDir::DirsFirst);
    return dir.entryInfoList();
}

bool UBFileSystemUtils::deleteFilesContaining(const QString& pDirPath, const QString& pFileName)
{
    if (pDirPath.isEmpty() || pDirPath == "." || pDirPath == "..")
        return false;

    QDir dir(pDirPath);
    if (dir.exists())
        foreach (QString dirContent, dir.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
            if (dirContent.contains(pFileName))
                QFile::remove(pDirPath + "/" + dirContent);
    return true;
}

bool UBFileSystemUtils::deleteDir(const QString& pDirPath)
{
    if (pDirPath.isEmpty() || pDirPath == "." || pDirPath == "..")
        return false;

    QDir dir(pDirPath);
    if (dir.exists()) {
        foreach (QFileInfo dirContent, dir.entryInfoList(QDir::Files | QDir::Dirs
                | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System, QDir::Name)) {
            if (dirContent.isDir())
                deleteDir(dirContent.absoluteFilePath());
            else if (!dirContent.dir().remove(dirContent.fileName()))
                return false;
        }
    }
    return dir.rmdir(pDirPath);
}

bool UBFileSystemUtils::copyDir(const QString& pSourceDirPath, const QString& pTargetDirPath)
{
    if (pSourceDirPath.isEmpty() || pSourceDirPath == "." || pSourceDirPath == "..")
        return false;

    QDir dirSource(pSourceDirPath);
    QDir dirTarget(pTargetDirPath);

    if (!dirTarget.mkpath(pTargetDirPath))
        return false;

    bool success = true;
    foreach (QFileInfo dirContent, dirSource.entryInfoList(QDir::Files | QDir::Dirs
            | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name)) {
        if (!success) break;
        if (dirContent.isDir())
            success = copyDir(pSourceDirPath + "/" + dirContent.fileName(), pTargetDirPath + "/" + dirContent.fileName());
        else {
            QFile f(pSourceDirPath + "/" + dirContent.fileName());
            success = f.copy(pTargetDirPath + "/" + dirContent.fileName());
        }
    }
    return success;
}

bool UBFileSystemUtils::moveDir(const QString& pSourceDirPath, const QString& pTargetDirPath)
{
    if (copyDir(pSourceDirPath, pTargetDirPath))
        return deleteDir(pSourceDirPath);
    return false;
}

QString UBFileSystemUtils::nextAvailableFileName(const QString& filename, const QString& separator)
{
    QFile f(filename);
    if (!f.exists())
        return filename;

    unsigned int index = 0;
    QString uniqueFilename;
    QFileInfo fi(filename);
    QString base = fi.dir().path() + "/" + fi.baseName();
    QString suffix = fi.suffix();

    do {
        index++;
        uniqueFilename = base + QString("%1%2").arg(separator).arg(index) + "." + suffix;
        f.setFileName(uniqueFilename);
    } while (f.exists() && index < std::numeric_limits<unsigned int>::max());

    return uniqueFilename;
}

QString UBFileSystemUtils::nextAvailableDirName(const QString& filename, const QString& separator)
{
    QDir dir(filename);
    if (!dir.exists()) return filename;

    unsigned int index = 0;
    QString uniqueFilename;
    QFileInfo fi(filename);
    QString base = fi.dir().path() + "/" + fi.baseName();

    do {
        index++;
        uniqueFilename = base + QString("%1%2").arg(separator).arg(index);
        dir.setPath(uniqueFilename);
    } while (dir.exists() && index < std::numeric_limits<unsigned int>::max());

    return uniqueFilename;
}

bool UBFileSystemUtils::isPathMatch(QString path, QString source)
{
    QStringList pathToken = path.split("/");
    QStringList pathSourceToken = source.split("/");

    bool match = true;
    if (pathSourceToken.size() <= pathToken.size()) {
        for (int i = 0; i < pathSourceToken.size(); i++) {
            match = (pathSourceToken[i] == pathToken[i]);
            if (!match) break;
        }
    } else {
        match = false;
    }
    return match;
}

QString UBFileSystemUtils::cleanName(const QString& name)
{
    QString result = name;
    result.remove("/");
    result.remove(":");
    result.remove("?");
    result.remove("*");
    result.remove("\\");
    result.remove("<");
    result.remove(">");
    result.remove("|");
    return result;
}

QString UBFileSystemUtils::normalizeFilePath(const QString& pFilePath)
{
    QString result = pFilePath;
    return result.replace("\\", "/");
}

QString UBFileSystemUtils::extension(const QString& fileName)
{
    QString ext;
    int lastDotIndex = fileName.lastIndexOf(".");
    if (lastDotIndex > 0) {
        ext = fileName.right(fileName.length() - lastDotIndex - 1).toLower();
        if (ext.endsWith("/") || ext.endsWith("\\"))
            ext = ext.left(ext.length() - 1);
    }
    return ext;
}

QString UBFileSystemUtils::lastPathComponent(const QString& path)
{
    QString lpc = normalizeFilePath(path);
    int lastSeparatorIndex = lpc.lastIndexOf("/");

    if (lastSeparatorIndex + 1 == path.length()) {
        lpc = lpc.left(lpc.length() - 1);
        lastSeparatorIndex = lpc.lastIndexOf("/");
    }

    if (lastSeparatorIndex > 0)
        lpc = lpc.right(lpc.length() - lastSeparatorIndex - 1);
    else
        return QString();

    return lpc;
}

QString UBFileSystemUtils::thumbnailPath(const QString& path)
{
    QFileInfo pathInfo(path);
    return pathInfo.dir().absolutePath() + "/" + pathInfo.completeBaseName() + ".thumbnail.png";
}

QString UBFileSystemUtils::mimeTypeFromFileName(const QString& fileName)
{
    QString ext = extension(fileName);

    if (ext == "png") return "image/png";
    if (ext == "jpeg" || ext == "jpg" || ext == "jpe") return "image/jpeg";
    if (ext == "bmp") return "image/bmp";
    if (ext == "gif") return "image/gif";
    if (ext == "tiff" || ext == "tif") return "image/tiff";
    if (ext == "svg" || ext == "svgz") return "image/svg+xml";
    if (ext == "pdf") return "application/pdf";
    if (ext == "mp4") return "video/mp4";
    if (ext == "mov" || ext == "qt") return "video/quicktime";
    if (ext == "avi") return "video/x-msvideo";
    if (ext == "wmv") return "video/x-ms-wmv";
    if (ext == "mpg" || ext == "mpeg") return "video/mpeg";
    if (ext == "ogv") return "video/ogg";
    if (ext == "flv") return "video/x-flv";
    if (ext == "m4v") return "video/x-m4v";
    if (ext == "mp3") return "audio/mpeg";
    if (ext == "wav") return "audio/x-wav";
    if (ext == "wgt") return "application/widget";
    if (ext == "wdgt") return "application/vnd.apple-widget";
    if (ext == "swf") return "application/x-shockwave-flash";
    if (ext == "html") return "text/html";
    if (ext == "txt") return "text/plain";
    if (ext == "doc" || ext == "docx") return "application/msword";
    if (ext == "xls" || ext == "xlsx") return "application/msexcel";
    if (ext == "ppt" || ext == "pptx") return "application/mspowerpoint";
    if (ext == "zip") return "application/zip";
    if (ext == "xml") return "application/xml";

    return "";
}

QString UBFileSystemUtils::fileExtensionFromMimeType(const QString& pMimeType)
{
    if (pMimeType == "image/png") return "png";
    if (pMimeType == "image/jpeg") return "jpeg";
    if (pMimeType == "image/bmp") return "bmp";
    if (pMimeType == "image/gif") return "gif";
    if (pMimeType == "image/tiff") return "tiff";
    if (pMimeType == "image/svg+xml") return "svg";
    if (pMimeType == "application/pdf") return "pdf";
    if (pMimeType == "video/mp4") return "mp4";
    if (pMimeType == "video/quicktime") return "mov";
    if (pMimeType == "video/x-msvideo") return "avi";
    if (pMimeType == "video/mpeg") return "mpg";
    if (pMimeType == "audio/mpeg") return "mp3";
    if (pMimeType == "audio/x-wav") return "wav";
    if (pMimeType == "text/html") return "html";
    if (pMimeType == "text/plain") return "txt";
    if (pMimeType == "application/zip") return "zip";
    if (pMimeType == "application/widget") return "wgt";
    if (pMimeType == "application/x-shockwave-flash") return "swf";

    return "";
}

UBMimeType::Enum UBFileSystemUtils::mimeTypeFromString(const QString& typeString)
{
    if (typeString == "image/jpeg" || typeString == "image/png" ||
        typeString == "image/gif" || typeString == "image/tiff" ||
        typeString == "image/bmp")
        return UBMimeType::RasterImage;
    if (typeString == "image/svg+xml")
        return UBMimeType::VectorImage;
    if (typeString == "application/vnd.apple-widget")
        return UBMimeType::AppleWidget;
    if (typeString == "application/widget")
        return UBMimeType::W3CWidget;
    if (typeString.startsWith("video/"))
        return UBMimeType::Video;
    if (typeString.startsWith("audio/"))
        return UBMimeType::Audio;
    if (typeString.startsWith("application/x-shockwave-flash"))
        return UBMimeType::Flash;
    if (typeString.startsWith("application/pdf"))
        return UBMimeType::PDF;
    if (typeString.startsWith("text/html"))
        return UBMimeType::Web;

    return UBMimeType::UNKNOWN;
}

UBMimeType::Enum UBFileSystemUtils::mimeTypeFromUrl(const QUrl& url)
{
    return mimeTypeFromString(mimeTypeFromFileName(url.toString()));
}

QString UBFileSystemUtils::getFirstExistingFileFromList(const QString& path, const QStringList& files)
{
    QString fullpath = path;
    if (!path.endsWith("/"))
        fullpath += "/";

    foreach (QString filename, files) {
        QFile file(fullpath + filename);
        if (file.exists())
            return fullpath + filename;
    }
    return "";
}

QString UBFileSystemUtils::readTextFile(QString path)
{
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        return in.readAll();
    }
    return "";
}

void UBFileSystemUtils::rename(const QString &path, const QString &newName)
{
    QFileInfo info(path);
    int slashPos = path.lastIndexOf("/");
    QString newPath = path.mid(0, slashPos + 1) + newName;

    if (info.isDir()) {
        QDir folder(path);
        folder.rename(path, newPath);
    } else {
        QString ext = extension(path.mid(slashPos + 2));
        QFile::rename(path, newPath + "." + ext);
    }
}
