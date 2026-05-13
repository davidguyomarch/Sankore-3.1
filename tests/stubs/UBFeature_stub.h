/*
 * Stub for UBFeature - minimal class to satisfy UBDocumentProxy compilation.
 */
#ifndef UBFEATURE_STUB_H
#define UBFEATURE_STUB_H

#include <QtCore>
#include <QtGui>

enum UBFeatureElementType {
    FEATURE_CATEGORY,
    FEATURE_VIRTUALFOLDER,
    FEATURE_FOLDER,
    FEATURE_INTERACTIVE,
    FEATURE_INTERNAL,
    FEATURE_ITEM,
    FEATURE_AUDIO,
    FEATURE_VIDEO,
    FEATURE_IMAGE,
    FEATURE_FLASH,
    FEATURE_TRASH,
    FEATURE_FAVORITE,
    FEATURE_SEARCH
};

class UBFeature
{
public:
    enum Permission {
        NO_P      = 0x0,
        DELETE_P   = 0x1,
        WRITE_P   = 0x2,
        ALL_P     = 0xF
    };

    UBFeature() : elementType(FEATURE_CATEGORY) {}
    UBFeature(const QString &url, const QImage &icon, const QString &name,
              const QUrl &realPath, UBFeatureElementType type = FEATURE_CATEGORY,
              Permission pOwnPermissions = ALL_P, QString pSortKey = QString())
        : virtualDir(url), mThumbnail(icon), mName(name), mPath(realPath),
          elementType(type), mSortKey(pSortKey)
    {
        Q_UNUSED(pOwnPermissions);
    }

    virtual ~UBFeature() {}

    QString getName() const { return mName; }
    QImage getThumbnail() const { return mThumbnail; }
    QString getVirtualPath() const { return virtualDir; }
    QUrl getFullPath() const { return mPath; }
    UBFeatureElementType getType() const { return elementType; }

private:
    QString virtualDir;
    QImage mThumbnail;
    QString mName;
    QUrl mPath;
    UBFeatureElementType elementType;
    QString mSortKey;
};

#endif // UBFEATURE_STUB_H
