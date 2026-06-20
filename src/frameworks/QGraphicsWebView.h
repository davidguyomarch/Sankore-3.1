/*
 * QGraphicsWebView compatibility adapter for Qt6
 * 
 * Provides the QGraphicsWebView interface using QWebEngineView embedded
 * via QGraphicsProxyWidget internally. This enables the Open-Sankore
 * widget system to work with Qt6 WebEngine.
 */

#ifndef QGRAPHICSWEBVIEW_H
#define QGRAPHICSWEBVIEW_H

#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineSettings>
#include <QWebEngineProfile>
#include <QUrl>
#include <QPainter>

class QWebFrame;

class QGraphicsWebView : public QGraphicsWidget
{
    Q_OBJECT

public:
    explicit QGraphicsWebView(QGraphicsItem *parent = nullptr);
    virtual ~QGraphicsWebView();

    // Page management
    QWebEnginePage* page() const;
    void setPage(QWebEnginePage *page);

    // Frame compatibility (WebKit -> WebEngine bridge)
    QWebFrame* mainFrame() const;

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
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    virtual QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    // Size management
    void resize(const QSizeF &size);
    void resize(qreal w, qreal h);
    QSizeF size() const;

    // Access the internal web view (for advanced usage)
    QWebEngineView* webEngineView() const { return m_webView; }

signals:
    void loadStarted();
    void loadFinished(bool ok);
    void loadProgress(int progress);
    void urlChanged(const QUrl &url);
    void titleChanged(const QString &title);
    void iconChanged();
    void linkClicked(const QUrl &url);

protected:
    virtual bool event(QEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void wheelEvent(QGraphicsSceneWheelEvent *event) override;
    virtual void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private slots:
    void onPageLoadFinished(bool ok);
    void onPageLoadStarted();
    void onPageLoadProgress(int progress);
    void onUrlChanged(const QUrl &url);
    void onTitleChanged(const QString &title);

private:
    void setupProxy();

    QWebEngineView *m_webView;
    QGraphicsProxyWidget *m_proxy;
    QWebEnginePage *m_page;
    QWebFrame *m_mainFrame;
    bool m_ownPage;
};

/**
 * QWebFrame compatibility shim for Qt6 WebEngine.
 * 
 * In Qt WebKit, QWebPage had mainFrame() returning QWebFrame*.
 * In Qt WebEngine, there is no frame concept - the page itself
 * provides JavaScript evaluation. This class wraps a QWebEnginePage
 * to provide the old QWebFrame interface.
 */
class QWebFrame : public QObject
{
    Q_OBJECT

public:
    explicit QWebFrame(QWebEnginePage *page, QObject *parent = nullptr);

    void evaluateJavaScript(const QString &scriptSource);
    QVariant evaluateJavaScriptSync(const QString &scriptSource);
    void addToJavaScriptWindowObject(const QString &name, QObject *object);

    QUrl url() const;
    QString title() const;
    QSize contentsSize() const;
    QRect geometry() const;
    qreal zoomFactor() const;

    void setUrl(const QUrl &url);
    void setHtml(const QString &html, const QUrl &baseUrl = QUrl());

    // Render (compatibility - renders via the page's view)
    void render(QPainter *painter);

    QWebEnginePage* page() const { return m_page; }

signals:
    void javaScriptWindowObjectCleared();
    void initialLayoutCompleted();
    void loadFinished(bool ok);
    void urlChanged(const QUrl &url);
    void titleChanged(const QString &title);

private:
    QWebEnginePage *m_page;
};

#endif // QGRAPHICSWEBVIEW_H
