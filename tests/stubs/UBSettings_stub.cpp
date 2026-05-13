/*
 * Stub implementation for UBSettings - provides static constants and
 * a minimal settings() accessor for testing.
 */
#include "UBSettings_stub.h"
#include <QDir>

UBSettings* UBSettings::sInstance = 0;

// Static string constants
QString UBSettings::documentGroupName = "GroupName";
QString UBSettings::documentName = "Title";
QString UBSettings::documentSize = "Size";
QString UBSettings::documentIdentifer = "Identifer";
QString UBSettings::documentVersion = "Version";
QString UBSettings::documentUpdatedAt = "UpdatedAt";
QString UBSettings::documentDate = "CreationDate";

QString UBSettings::sessionTitle = "SessionTitle";
QString UBSettings::sessionAuthors = "SessionAuthors";
QString UBSettings::sessionObjectives = "SessionObjectives";
QString UBSettings::sessionKeywords = "SessionKeywords";
QString UBSettings::sessionGradeLevel = "SessionGradeLevel";
QString UBSettings::sessionSubjects = "SessionSubjects";
QString UBSettings::sessionType = "SessionType";
QString UBSettings::sessionLicence = "SessionLicence";

QString UBSettings::documentDefaultBackgroundImage = "DocumentDefaultBackgroundImage";
QString UBSettings::documentDefaultBackgroundImageDisposition = "DocumentDefaultBackgroundImageDisposition";

QString UBSettings::uniboardDocumentNamespaceUri = "http://uniboard.mnemis.com/document";

QString UBSettings::trashedDocumentGroupNamePrefix = "Trash:";
QString UBSettings::currentFileVersion = "4.7.0";
QString UBSettings::documentTagVersion = "DocumentTagVersion";

int UBSettings::pointerDiameter = 40;
int UBSettings::boardMargin = 10;

UBSettings* UBSettings::settings()
{
    if (!sInstance)
        sInstance = new UBSettings(0);
    return sInstance;
}

void UBSettings::destroy()
{
    if (sInstance) {
        delete sInstance;
        sInstance = 0;
    }
}

UBSettings::UBSettings(QObject *parent)
    : QObject(parent)
{
    pageSize = new UBSetting(this, "Board", "PageSize", QVariant(QSize(1380, 1080)));
}

UBSettings::~UBSettings()
{
    delete pageSize;
}

QString UBSettings::userDataDirectory()
{
    return QDir::tempPath() + "/OpenSankoreTests/data";
}

QString UBSettings::userDocumentDirectory()
{
    return QDir::tempPath() + "/OpenSankoreTests/documents";
}

QString UBSettings::userImageDirectory()
{
    return QDir::tempPath() + "/OpenSankoreTests/images";
}
