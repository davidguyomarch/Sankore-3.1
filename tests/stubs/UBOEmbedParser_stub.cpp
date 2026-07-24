/**
 * @file UBOEmbedParser_stub.cpp
 * @brief Stub that compiles only the parsing methods of UBOEmbedParser
 *        without the full Q_OBJECT moc/signals infrastructure.
 */

#include <QJsonDocument>
#include <QJsonObject>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QStringList>
#include <QDebug>

#include "web/UBOEmbedParser.h"

// Provide minimal constructor/destructor (no signals connected)
UBOEmbedParser::UBOEmbedParser(QObject *parent, const char* name)
{
    Q_UNUSED(parent);
    setObjectName(name);
    mpNam = nullptr;
    mPending = 0;
}

UBOEmbedParser::~UBOEmbedParser()
{
}

void UBOEmbedParser::setNetworkAccessManager(QNetworkAccessManager* nam)
{
    mpNam = nam;
}

void UBOEmbedParser::parse(const QString& /*html*/)
{
    // No-op in stub
}

void UBOEmbedParser::onParseContent(QString /*url*/)
{
    // No-op in stub
}

void UBOEmbedParser::onFinished(QNetworkReply* /*reply*/)
{
    // No-op in stub
}

sOEmbedContent UBOEmbedParser::getJSONInfos(const QString &json)
{
    sOEmbedContent content;

    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    QJsonObject obj = doc.object();

    content.providerUrl = obj.value("provider_url").toString();
    content.title = obj.value("title").toString();
    content.html = obj.value("html").toString();
    content.author = obj.value("author_name").toString();
    content.height = obj.value("height").toInt();
    content.thumbWidth = obj.value("thumbnail_width").toInt();
    content.width = obj.value("width").toInt();
    content.version = obj.value("version").toString().toFloat();
    content.authorUrl = obj.value("author_url").toString();
    content.providerName = obj.value("provider_name").toString();
    content.thumbUrl = obj.value("thumbnail_url").toString();
    content.type = obj.value("type").toString();
    int thumbnailHeight = obj.value("thumbnail_height").toInt();
    content.thumbHeight = QString::number(thumbnailHeight);

    if ("photo" == content.type) {
        content.url = obj.value("url").toString();
    } else if ("video" == content.type) {
        QStringList strl = content.html.split('\"');
        for (int i = 0; i < strl.size(); i++) {
            if (strl.at(i).endsWith("src=") && strl.size() > (i + 1)) {
                content.url = strl.at(i + 1);
            }
        }
    }

    return content;
}

sOEmbedContent UBOEmbedParser::getXMLInfos(const QString &xml)
{
    sOEmbedContent content;

    QDomDocument domDoc;
    domDoc.setContent(xml);
    QDomNode oembed = domDoc.documentElement();

    QDomNodeList children = oembed.toElement().childNodes();

    for (int i = 0; i < children.size(); i++) {
        QDomNode node = children.at(i);
        QString tag = node.nodeName();
        QString value = node.toElement().text();
        if ("provider_url" == tag) {
            content.providerUrl = value;
        } else if ("title" == tag) {
            content.title = value;
        } else if ("html" == tag) {
            content.html = value;
        } else if ("author_name" == tag) {
            content.author = value;
        } else if ("height" == tag) {
            content.height = value.toInt();
        } else if ("thumbnail_width" == tag) {
            content.thumbWidth = value.toInt();
        } else if ("width" == tag) {
            content.width = value.toInt();
        } else if ("version" == tag) {
            content.version = value.toFloat();
        } else if ("author_url" == tag) {
            content.authorUrl = value;
        } else if ("provider_name" == tag) {
            content.providerName = value;
        } else if ("thumbnail_url" == tag) {
            content.thumbUrl = value;
        } else if ("type" == tag) {
            content.type = value;
        } else if ("thumbnail_height" == tag) {
            content.thumbHeight = value;
        } else if ("url" == tag) {
            content.url = value;
        }
    }

    if ("video" == content.type) {
        QStringList strl = content.html.split('\"');
        for (int i = 0; i < strl.size(); i++) {
            if (strl.at(i).endsWith("src=") && strl.size() > (i + 1)) {
                content.url = strl.at(i + 1);
            }
        }
    }

    return content;
}
