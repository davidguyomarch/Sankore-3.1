/**
 * @file main.cpp
 * @brief Point d'entrée des tests unitaires Open-Sankoré.
 *
 * Exécute tous les tests enregistrés via QTest.
 */

#include <QtTest>
#include <QCoreApplication>

#include "tst_UBStringUtils.h"
#include "tst_UBFileSystemUtils.h"
#include "tst_UBGeometryUtils.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
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

    return status;
}
