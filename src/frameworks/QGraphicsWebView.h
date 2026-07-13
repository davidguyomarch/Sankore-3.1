/**
 * @file QGraphicsWebView.h
 * @brief QGraphicsWebView replacement for Qt6 using QWebEngineView + QGraphicsProxyWidget.
 *
 * In Qt5, QGraphicsWebView was part of QtWebKit. In Qt6, there is no direct equivalent.
 * This class wraps a QWebEngineView inside a QGraphicsProxyWidget to provide the same
 * interface for embedding web content in a QGraphicsScene.
 */
#ifndef QGRAPHICSWEBVIEW_H
#define QGRAPHICSWEBVIEW_H

#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QUrl>
#include <QPainter>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineSettings>
#include <QWebEngineProfile>

// Stub for QWebFrame (removed in Qt6 — compatibility shim)
class QWebFrame : public QObject
{
    Q_OBJECT
public:
    QWebFrame(QObject *parent = nullptr) : QObject(parent), m_page(nullptr) {}
    void setPage(QWebEnginePage *page) { m_page = page; }
    void setScrollBarPolicy(Qt::Orientation, Qt::ScrollBarPolicy) {}
    QUrl url() const { return m_page ? m_page->url() : QUrl(); }
    void setUrl(const QUrl &url) { if (m_page) m_page->setUrl(url); }
    QString toHtml() const { return QString(); }
    QVariant evaluateJavaScript(const QString &script) {
        // Async in Qt6 — this stub returns empty for compatibility
        if (m_page) m_page->runJavaScript(script);
        return QVariant();
    }
    QVariant evaluateJavaScriptSync(const QString &script) {
        return evaluateJavaScript(script);
    }
    void addToJavaScriptWindowObject(const QString &, QObject *) {
        // Qt6 uses QWebChannel instead — no direct equivalent
    }
    QSize contentsSize() const {
        return m_page ? m_page->contentsSize().toSize() : QSize(800, 600);
    }
signals:
    void javaScriptWindowObjectCleared();
private:
    QWebEnginePage *m_page;
};

class QGraphicsWebView : public QGraphicsWidget
{
    Q_OBJECT

public:
    explicit QGraphicsWebView(QGraphicsItem *parent = nullptr);
    virtual ~QGraphicsWebView();

    // Page management
    QWebEnginePage* page() const;
    void setPage(QWebEnginePage *page);

    // Frame compatibility (Qt5 shim)
    QWebFrame* mainFrame() const { return m_mainFrame; }

    // Settings
    QWebEngineSettings* settings() const;

    // URL/Content loading
    QUrl url() const;
    void setUrl(const QUrl &url);
    void load(const QUrl &url);
    void setHtml(const QString &html, const QUrl &baseUrl = QUrl());

    // Title
    QString title() const;

    // Zoom
    qreal zoomFactor() const;
    void setZoomFactor(qreal factor);

    // QGraphicsWidget reimplementations
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    // Size management
    void resize(const QSizeF &size);
    void resize(qreal w, qreal h);
    QSizeF size() const { return QGraphicsWidget::size(); }
    void setMaximumSize(qreal w, qreal h) { QGraphicsWidget::setMaximumSize(w, h); }

    // Type for qgraphicsitem_cast
    enum { Type = UserType + 100 };
    int type() const override { return Type; }

signals:
    void loadStarted();
    void loadFinished(bool ok);
    void loadProgress(int progress);
    void urlChanged(const QUrl &url);
    void titleChanged(const QString &title);
    void iconChanged();
    void linkClicked(const QUrl &url);

private:
    QWebEngineView *m_webView;
    QGraphicsProxyWidget *m_proxy;
    QWebFrame *m_mainFrame;
};

#endif // QGRAPHICSWEBVIEW_H
