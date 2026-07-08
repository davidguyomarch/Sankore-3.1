#ifndef QWEBENGINEPROFILE_STUB_MOC_H
#define QWEBENGINEPROFILE_STUB_MOC_H

#include <QObject>
#include <QString>
#include "QWebEngineSettings"

class QWebEngineProfile : public QObject
{
    Q_OBJECT
public:
    static QWebEngineProfile *defaultProfile() {
        static QWebEngineProfile p;
        return &p;
    }
    QWebEngineProfile(QObject *parent = nullptr) : QObject(parent) {}
    QWebEngineProfile(const QString &, QObject *parent = nullptr) : QObject(parent) {}
    void setHttpCacheType(int) {}
    void setPersistentCookiesPolicy(int) {}
    QString cachePath() const { return QString(); }
    void setCachePath(const QString &) {}
    QString persistentStoragePath() const { return QString(); }
    void setPersistentStoragePath(const QString &) {}
    QWebEngineSettings *settings() const { return QWebEngineSettings::defaultSettings(); }
};

#endif
