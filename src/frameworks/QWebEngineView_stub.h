#ifndef QWEBENGINEVIEW_STUB_MOC_H
#define QWEBENGINEVIEW_STUB_MOC_H

#include <QWidget>
#include <QUrl>

class QWebEnginePage;

class QWebEngineView : public QWidget
{
    Q_OBJECT
public:
    explicit QWebEngineView(QWidget *parent = nullptr) : QWidget(parent) {}
    virtual ~QWebEngineView() {}
    void load(const QUrl &) {}
    void setUrl(const QUrl &) {}
    QUrl url() const { return QUrl(); }
    void setHtml(const QString &, const QUrl & = QUrl()) {}
    QString title() const { return QString(); }
    QWebEnginePage *page() const { return nullptr; }
    void setPage(QWebEnginePage *) {}
    void setZoomFactor(qreal) {}
    qreal zoomFactor() const { return 1.0; }
    void stop() {}
    void reload() {}
    void back() {}
    void forward() {}
    QAction *pageAction(int) const { return nullptr; }
signals:
    void loadStarted();
    void loadFinished(bool ok);
    void loadProgress(int progress);
    void urlChanged(const QUrl &url);
    void titleChanged(const QString &title);
};

#endif
