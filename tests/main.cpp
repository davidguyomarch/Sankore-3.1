/**
 * @file main.cpp
 * @brief Point d'entrée des tests unitaires Open-Sankoré.
 *
 * Exécute tous les tests enregistrés via QTest.
 */

#include <QtTest>
#include <QGuiApplication>

#include "tst_UBStringUtils.h"
#include "tst_UBFileSystemUtils.h"
#include "tst_UBGeometryUtils.h"
#ifndef SKIP_CRYPTO_TESTS
#include "tst_UBCryptoUtils.h"
#endif
#include "tst_UBDocumentProxy.h"
#include "tst_UBSettings.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("OpenSankoreTests");

    int status = 0;

    {
        TestUBStringUtils test;
        status |= QTest::qExec(&test, argc, argv);
    }

    {
        TestUBFileSystemUtils test;
        status |= QTest::qExec(&test, argc, argv);
    }

    {
        TestUBGeometryUtils test;
        status |= QTest::qExec(&test, argc, argv);
    }

#ifndef SKIP_CRYPTO_TESTS
    {
        TestUBCryptoUtils test;
        status |= QTest::qExec(&test, argc, argv);
    }
#endif

    {
        TestUBDocumentProxy test;
        status |= QTest::qExec(&test, argc, argv);
    }

    {
        TestUBSettings test;
        status |= QTest::qExec(&test, argc, argv);
    }

    return status;
}
