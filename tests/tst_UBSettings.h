#ifndef TST_UBSETTINGS_H
#define TST_UBSETTINGS_H

#include <QtTest>
#include <QObject>

class TestUBSettings : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testDirectoryPathsNonEmpty();
    void testSettingsReadWriteRoundtrip();
    void testDefaultValueBehavior();
    void testBoardColorSettings();
    void testToolWidthSettings();
    void testStaticConstantsDefined();
    void testPageSizeSetting();

private:
    QString mTempIniPath;
};

#endif // TST_UBSETTINGS_H
