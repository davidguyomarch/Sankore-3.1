#ifndef TST_UBOEMBEDPARSER_H
#define TST_UBOEMBEDPARSER_H

#include <QObject>
#include <QtTest>

class TestUBOEmbedParser : public QObject
{
    Q_OBJECT

private slots:
    void testGetJSONInfos_video();
    void testGetJSONInfos_photo();
    void testGetJSONInfos_emptyJson();
    void testGetXMLInfos_video();
    void testGetXMLInfos_photo();
    void testGetXMLInfos_emptyXml();
    void testGetJSONInfos_partialData();
    void testGetXMLInfos_allFields();
};

#endif // TST_UBOEMBEDPARSER_H
