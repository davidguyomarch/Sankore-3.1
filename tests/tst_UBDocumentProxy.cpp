#include "tst_UBDocumentProxy.h"
#include "stubs/UBDocumentProxy_stub.h"

#include <QDir>
#include <QUuid>

void TestUBDocumentProxy::initTestCase()
{
    // Ensure UBSettings stub singleton is initialized
    UBSettings::settings();
}

void TestUBDocumentProxy::cleanupTestCase()
{
    UBSettings::destroy();
}

void TestUBDocumentProxy::testMetadataGetSet()
{
    UBDocumentProxy proxy;

    // Test setting and retrieving metadata (typical teacher use case)
    proxy.setMetaData(UBSettings::documentName, QString::fromUtf8("Math\xc3\xa9matiques CE2"));
    QCOMPARE(proxy.metaData(UBSettings::documentName).toString(), QString::fromUtf8("Math\xc3\xa9matiques CE2"));

    proxy.setMetaData(UBSettings::sessionAuthors, "M. Dupont");
    QCOMPARE(proxy.metaData(UBSettings::sessionAuthors).toString(), QString("M. Dupont"));

    proxy.setMetaData(UBSettings::documentVersion, "4.7.0");
    QCOMPARE(proxy.metaData(UBSettings::documentVersion).toString(), QString("4.7.0"));

    // Test UUID stored in metadata
    QUuid testUuid = QUuid::createUuid();
    proxy.setUuid(testUuid);
    QCOMPARE(proxy.uuid(), testUuid);

    // Test creation date
    QString dateStr = "2024-01-15T10:30:00Z";
    proxy.setMetaData(UBSettings::documentDate, dateStr);
    QCOMPARE(proxy.metaData(UBSettings::documentDate).toString(), dateStr);
}

void TestUBDocumentProxy::testPageCountOperations()
{
    UBDocumentProxy proxy;

    // Initial page count is 0
    QCOMPARE(proxy.pageCount(), 0);

    // incPageCount from 0 should go to 1
    int result = proxy.incPageCount();
    QCOMPARE(result, 1);
    QCOMPARE(proxy.pageCount(), 1);

    // incPageCount from 1 should go to 2
    result = proxy.incPageCount();
    QCOMPARE(result, 2);
    QCOMPARE(proxy.pageCount(), 2);

    // incPageCount from 2 should go to 3
    result = proxy.incPageCount();
    QCOMPARE(result, 3);

    // decPageCount from 3 should go to 2
    result = proxy.decPageCount();
    QCOMPARE(result, 2);
    QCOMPARE(proxy.pageCount(), 2);

    // setPageCount explicitly
    proxy.setPageCount(10);
    QCOMPARE(proxy.pageCount(), 10);

    // decPageCount should not go below 0
    proxy.setPageCount(0);
    result = proxy.decPageCount();
    QCOMPARE(result, 0);
    QCOMPARE(proxy.pageCount(), 0);
}

void TestUBDocumentProxy::testPersistencePathConstruction()
{
    QString testPath = QDir::tempPath() + "/test_doc_" + QUuid::createUuid().toString();
    UBDocumentProxy proxy(testPath);

    // Path should be non-empty
    QVERIFY(!proxy.persistencePath().isEmpty());

    // Path should match what was set
    QCOMPARE(proxy.persistencePath(), testPath);

    // Changing path should update
    QString newPath = QDir::tempPath() + "/new_path_" + QUuid::createUuid().toString();
    proxy.setPersistencePath(newPath);
    QCOMPARE(proxy.persistencePath(), newPath);

    // Document should be marked as modified after path change
    QVERIFY(proxy.isModified());
}

void TestUBDocumentProxy::testUuidGenerationUniqueness()
{
    UBDocumentProxy proxy1;
    UBDocumentProxy proxy2;
    UBDocumentProxy proxy3;

    // Each proxy should have a unique UUID
    QVERIFY(proxy1.uuid() != proxy2.uuid());
    QVERIFY(proxy2.uuid() != proxy3.uuid());
    QVERIFY(proxy1.uuid() != proxy3.uuid());

    // UUIDs should be valid (non-null)
    QVERIFY(!proxy1.uuid().isNull());
    QVERIFY(!proxy2.uuid().isNull());
    QVERIFY(!proxy3.uuid().isNull());
}

void TestUBDocumentProxy::testCopyConstructor()
{
    UBDocumentProxy original;
    original.setPersistencePath("/tmp/test_original");
    original.setMetaData(UBSettings::documentName, "Test Document");
    original.setPageCount(5);

    UBDocumentProxy copy(original);

    // Copy should have same persistence path
    QCOMPARE(copy.persistencePath(), original.persistencePath());

    // Copy should have same metadata
    QCOMPARE(copy.metaData(UBSettings::documentName).toString(), QString("Test Document"));

    // Copy should have same page count
    QCOMPARE(copy.pageCount(), 5);
}

void TestUBDocumentProxy::testDefaultDocumentSize()
{
    UBDocumentProxy proxy;

    // Default size should come from UBSettings stub (1380x1080)
    QSize defaultSize = proxy.defaultDocumentSize();
    QVERIFY(defaultSize.width() > 0);
    QVERIFY(defaultSize.height() > 0);

    // Setting a new size should emit signal
    QSignalSpy spy(&proxy, SIGNAL(defaultDocumentSizeChanged()));
    proxy.setDefaultDocumentSize(QSize(1920, 1080));
    QCOMPARE(proxy.defaultDocumentSize(), QSize(1920, 1080));
    QCOMPARE(spy.count(), 1);

    // Setting same size should not emit signal again
    proxy.setDefaultDocumentSize(QSize(1920, 1080));
    QCOMPARE(spy.count(), 1);
}

void TestUBDocumentProxy::testDocumentName()
{
    UBDocumentProxy proxy;

    // Name should be initialized (default is current date/time string)
    QVERIFY(!proxy.name().isEmpty());

    // Set a custom name
    proxy.setMetaData(UBSettings::documentName, QString::fromUtf8("Le\xc3\xa7on de g\xc3\xa9ographie"));
    QCOMPARE(proxy.name(), QString::fromUtf8("Le\xc3\xa7on de g\xc3\xa9ographie"));

    // Group name should be initially empty
    QCOMPARE(proxy.groupName(), QString(""));
}
