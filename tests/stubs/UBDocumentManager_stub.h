/*
 * Stub for UBDocumentManager - provides a no-op documentManager() returning null.
 */
#ifndef UBDOCUMENTMANAGER_STUB_H
#define UBDOCUMENTMANAGER_STUB_H

#include <QtCore>

class UBDocumentProxy;

class UBDocumentManager : public QObject
{
    Q_OBJECT

public:
    static UBDocumentManager* documentManager();

    void emitDocumentUpdated(UBDocumentProxy* proxy);

signals:
    void documentUpdated(UBDocumentProxy* proxy);

private:
    UBDocumentManager(QObject *parent = 0);
    static UBDocumentManager* sInstance;
};

#endif // UBDOCUMENTMANAGER_STUB_H
