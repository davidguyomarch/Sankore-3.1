/*
 * Stub implementation for UBPlatformUtils.
 */
#include "UBPlatformUtils_stub.h"
#include <QDir>

QString UBPlatformUtils::applicationResourcesDirectory()
{
    return QDir::tempPath() + "/OpenSankoreTests/resources";
}

void UBPlatformUtils::init()
{
    // No-op for tests
}

void UBPlatformUtils::destroy()
{
    // No-op for tests
}
