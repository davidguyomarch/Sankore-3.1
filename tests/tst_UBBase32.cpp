#include "tst_UBBase32.h"
#include "frameworks/UBBase32.h"

void TestUBBase32::testDecodeEmpty()
{
    QByteArray result = UBBase32::decode("");
    QVERIFY(result.isEmpty());
}

void TestUBBase32::testDecodeRFC4648Vectors()
{
    // RFC 4648 test vectors (without padding)
    QCOMPARE(UBBase32::decode("MY"), QByteArray("f"));
    QCOMPARE(UBBase32::decode("MFRA"), QByteArray("fo"));
    QCOMPARE(UBBase32::decode("MFRGG"), QByteArray("foo"));
    QCOMPARE(UBBase32::decode("MFRGGZA"), QByteArray("foob"));
    QCOMPARE(UBBase32::decode("MFRGGZDF"), QByteArray("fooba"));
    QCOMPARE(UBBase32::decode("MFRGGZDFMY"), QByteArray("foobar"));
}

void TestUBBase32::testDecodeCaseInsensitive()
{
    // Lowercase should decode same as uppercase
    QByteArray upper = UBBase32::decode("MFRGGZDFMY");
    QByteArray lower = UBBase32::decode("mfrggzdfmy");
    QCOMPARE(lower, upper);
}

void TestUBBase32::testDecodeInvalidChars()
{
    // Characters outside base32 alphabet should be skipped
    QByteArray result = UBBase32::decode("MY======");  // padding chars (=) are outside lookup
    // Should still decode "f" (MY part) — padding is skipped
    QCOMPARE(result.left(1), QByteArray("f"));
}

void TestUBBase32::testDecodeHelloWorld()
{
    // "Hello" in base32 is JBSWY3DP
    QCOMPARE(UBBase32::decode("JBSWY3DP"), QByteArray("Hello"));
}
