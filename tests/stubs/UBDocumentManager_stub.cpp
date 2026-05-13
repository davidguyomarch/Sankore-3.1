/*
 * Stub implementation for UBDocumentManager.
 */
#include "UBDocumentManager_stub.h"

UBDocumentManager* UBDocumentManager::sInstance = 0;

UBDocumentManager::UBDocumentManager(QObject *parent)
    : QObject(parent)
{
}

UBDocumentManager* UBDocumentManager::documentManager()
{
    if (!sInstance)
        sInstance = new UBDocumentManager(0);
    return sInstance;
}

void UBDocumentManager::emitDocumentUpdated(UBDocumentProxy* proxy)
{
    emit documentUpdated(proxy);
}
