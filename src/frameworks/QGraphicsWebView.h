/**
 * @file QGraphicsWebView.h
 * @brief Stub QGraphicsWebView for Qt6 compilation without WebEngine.
 *
 * Provides the QGraphicsWebView interface as a stub that compiles
 * but does not render web content. Web functionality is disabled
 * until QtWebEngine is properly integrated.
 */
#ifndef QGRAPHICSWEBVIEW_H
#define QGRAPHICSWEBVIEW_H

#include <QGraphicsWidget>
#include <QUrl>
#include <QPainter>
#include <QGraphicsProxyWidget>

// Forward declare WebEngine types as opaque
class QWebEnginePage;
class QWebEngineSettings;
class QWebEngineProfile;
class QWebEngineView;

// Stub for QWebFrame (removed in Qt6)
class QWebFrame : public QObject
{
    Q_OBJECT
public:
    QWebFrame(QObject *parent = nullptr) : QObject(parent) {}
    void setScrollBarPolicy(Qt::Orientation, Qt::ScrollBarPolicy) {}
    QUrl url() const { return QUrl(); }
    void setUrl(const QUrl &) {}
    QString toHtml() const { return QString(); }
    QVariant evaluateJavaScript(const QString &) { return QVariant(); }
    QVariant evaluateJavaScriptSync(const QString &) { return QVariant(); }
    void addToJavaScriptWindowObject(const QString &, QObject *) {}
    QSize contentsSize() const { return QSize(800, 600); }
signals:
    void javaScriptWindowObjectCleared();
};

class QGraphicsWebView : public QGraphicsWidget
{
    Q_OBJECT

public:
    explicit QGraphicsWebView(QGraphicsItem *parent = nullptr)
        : QGraphicsWidget(parent), m_mainFrame(new QWebFrame(this)), m_zoomFactor(1.0) {}
    virtual ~QGraphicsWebView() {}

    // Page management (stub - returns null)
    QWebEnginePage* page() const { return nullptr; }
    void setPage(QWebEnginePage *) {}

    // Frame compatibility
    QWebFrame* mainFrame() const { return m_mainFrame; }

    // Settings (stub)
    QWebEngineSettings* settings() const { return nullptr; }

    // URL/Content loading (stub - no-op)
    QUrl url() const { return m_url; }
    void setUrl(const QUrl &url) { m_url = url; emit urlChanged(url); }
    void load(const QUrl &url) { setUrl(url); emit loadFinished(true); }
    void setHtml(const QString &, const QUrl & = QUrl()) { emit loadFinished(true); }

    // Title
    QString title() const { return m_title; }

    // Zoom
    qreal zoomFactor() const { return m_zoomFactor; }
    void setZoomFactor(qreal factor) { m_zoomFactor = factor; }

    // QGraphicsWidget reimplementations
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget * = nullptr) override {
        painter->fillRect(boundingRect(), Qt::white);
        painter->drawText(boundingRect(), Qt::AlignCenter, "Web view disabled");
    }

    // Size management
    void resize(const QSizeF &size) { QGraphicsWidget::resize(size); }
    void resize(qreal w, qreal h) { QGraphicsWidget::resize(w, h); }

signals:
    void loadStarted();
    void loadFinished(bool ok);
    void loadProgress(int progress);
    void urlChanged(const QUrl &url);
    void titleChanged(const QString &title);
    void iconChanged();
    void linkClicked(const QUrl &url);

private:
    QWebFrame *m_mainFrame;
    QUrl m_url;
    QString m_title;
    qreal m_zoomFactor;
};

#endif // QGRAPHICSWEBVIEW_H
