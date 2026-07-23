/**
 * @file UBMetadataDcSubsetAdaptor_stub.cpp
 * @brief Stub that compiles UBMetadataDcSubsetAdaptor::load() for testing
 *        without pulling in UBApplication/UBBoardController.
 *
 * We redefine the includes to use our test stubs instead of the real ones.
 */

// Provide stub headers before the real source
#include "stubs/UBSettings_stub.h"

// Fake UBApplication.h and UBBoardController.h content (only needed for persist())
namespace { struct FakeApp {}; }

// We only need load(), not persist(). Provide a no-op persist().
// Trick: include the header then define persist as no-op.

#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QScreen>
#include <QGuiApplication>

#include "stubs/UBDocumentProxy_stub.h"
#include "../src/frameworks/UBStringUtils.h"

// Replicate the class definition and implement load() from the real source
#include "../src/adaptors/UBMetadataDcSubsetAdaptor.h"

const QString UBMetadataDcSubsetAdaptor::nsRdf = "http://www.w3.org/1999/02/22-rdf-syntax-ns#";
const QString UBMetadataDcSubsetAdaptor::nsDc = "http://purl.org/dc/elements/1.1/";
const QString UBMetadataDcSubsetAdaptor::metadataFilename = "metadata.rdf";

UBMetadataDcSubsetAdaptor::UBMetadataDcSubsetAdaptor() {}
UBMetadataDcSubsetAdaptor::~UBMetadataDcSubsetAdaptor() {}

void UBMetadataDcSubsetAdaptor::persist(UBDocumentProxy* /*proxy*/)
{
    // No-op in test stub — persist() requires UBApplication/UBBoardController
}

QMap<QString, QVariant> UBMetadataDcSubsetAdaptor::load(QString pPath)
{
    QMap<QString, QVariant> metadata;

    QString fileName = pPath + "/" + metadataFilename;

    QFile file(fileName);

    bool sizeFound = false;
    bool updatedAtFound = false;
    QString date;

    if (file.exists())
    {
        if (!file.open(QIODevice::ReadOnly))
        {
            qWarning() << "Cannot open file " << fileName << " for reading ...";
            return metadata;
        }

        QString docVersion = "4.1";
        metadata.insert(UBSettings::documentVersion, docVersion);

        QXmlStreamReader xml(&file);

        while (!xml.atEnd())
        {
            xml.readNext();

            if (xml.isStartElement())
            {
                if (xml.name() == QLatin1String("title"))
                {
                    metadata.insert(UBSettings::documentName, xml.readElementText());
                }
                else if (xml.name() == QLatin1String("type"))
                {
                    metadata.insert(UBSettings::documentGroupName, xml.readElementText());
                }
                else if (xml.name() == QLatin1String("date"))
                {
                    date = xml.readElementText();
                }
                else if (xml.name() == QLatin1String("identifier"))
                {
                    metadata.insert(UBSettings::documentIdentifer, xml.readElementText());
                }
                else if (xml.name() == QLatin1String("version")
                        && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    docVersion = xml.readElementText();
                    metadata.insert(UBSettings::documentVersion, docVersion);
                }
                else if (xml.name() == QLatin1String("size")
                        && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    QString size = xml.readElementText();
                    QStringList sizeParts = size.split("x");
                    bool ok = false;
                    if (sizeParts.count() >= 2)
                    {
                        bool widthOK, heightOK;
                        int width = sizeParts.at(0).toInt(&widthOK);
                        int height = sizeParts.at(1).toInt(&heightOK);
                        ok = widthOK && heightOK;

                        QSize docSize(width, height);

                        if (width == 1024 && height == 768)
                        {
                            docSize = UBSettings::settings()->pageSize->get().toSize();
                        }

                        metadata.insert(UBSettings::documentSize, QVariant(docSize));
                    }
                    if (!ok)
                    {
                        qWarning() << "Invalid document size:" << size;
                    }
                    sizeFound = true;
                }
                else if (xml.name() == QLatin1String("updated-at")
                        && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::documentUpdatedAt, xml.readElementText());
                    updatedAtFound = true;
                }
                else if (xml.name() == UBSettings::sessionTitle
                         && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::sessionTitle, xml.readElementText());
                }
                else if (xml.name() == UBSettings::sessionAuthors
                         && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::sessionAuthors, xml.readElementText());
                }
                else if (xml.name() == UBSettings::sessionObjectives
                         && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::sessionObjectives, xml.readElementText());
                }
                else if (xml.name() == UBSettings::sessionKeywords
                         && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::sessionKeywords, xml.readElementText());
                }
                else if (xml.name() == UBSettings::sessionGradeLevel
                         && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::sessionGradeLevel, xml.readElementText());
                }
                else if (xml.name() == UBSettings::sessionSubjects
                         && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::sessionSubjects, xml.readElementText());
                }
                else if (xml.name() == UBSettings::sessionType
                         && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::sessionType, xml.readElementText());
                }
                else if (xml.name() == UBSettings::sessionLicence
                         && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::sessionLicence, xml.readElementText());
                }
                else if (xml.name() == UBSettings::documentDefaultBackgroundImage
                         && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::documentDefaultBackgroundImage, xml.readElementText());
                }
                else if (xml.name() == UBSettings::documentDefaultBackgroundImageDisposition
                         && xml.namespaceUri() == UBSettings::uniboardDocumentNamespaceUri)
                {
                    metadata.insert(UBSettings::documentDefaultBackgroundImageDisposition, xml.readElementText());
                }
            }

            if (xml.hasError())
            {
                qWarning() << "error parsing sankore metadata.rdf file " << xml.errorString();
            }
        }

        file.close();
    }

    if (!sizeFound)
    {
        // In test mode, use a default size instead of querying the screen
        QSize docSize(1280, 960);
        QScreen* primaryScreen = QGuiApplication::primaryScreen();
        if (primaryScreen) {
            docSize = primaryScreen->geometry().size();
            docSize.setHeight(docSize.height() - 70);
        }
        metadata.insert(UBSettings::documentSize, QVariant(docSize));
    }

    // Update old files date
    QString dateString = metadata.value(UBSettings::documentDate).toString();
    if (dateString.length() < 10) {
        metadata.remove(UBSettings::documentDate);
        metadata.insert(UBSettings::documentDate, dateString + "T00:00:00Z");
    }

    if (!updatedAtFound) {
        metadata.insert(UBSettings::documentUpdatedAt, dateString);
    }

    metadata.insert(UBSettings::documentDate, QVariant(date));

    return metadata;
}
