/*
 * QGraphicsWebView compatibility adapter implementation for Qt6
 */

#include "QGraphicsWebView.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneHoverEvent>
#include <QStyleOptionGraphicsItem>
#include <QWebEngineScript>
#include <QWebEngineScriptCollection>
#include <QWebChannel>
#include <QApplication>
#include <QVBoxLayout>

// ============================================================
// QGraphicsWebView implementation
// ============================================================

QGraphicsWebView::QGraphicsWebView(QGraphicsItem *parent)
    : QGraphicsWidget(parent)
    , m_webView(nullptr)
    , m_proxy(nullptr)
    , m_page(nullptr)
    , m_mainFrame(nullptr)
    , m_ownPage(false)
{
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFocusPolicy(Qt::StrongFocus);
    setupProxy();
}

QGraphicsWebView::~QGraphicsWebView()
{
    if (m_ownPage && m_page) {
        delete m_page;
        m_page = nullptr;
    }
    // m_webView is owned by m_proxy which is a child of this
}

void QGraphicsWebView::setupProxy()
{
    m_webView = new QWebEngineView();
    m_webView->setAttribute(Qt::WA_TranslucentBackground);

    m_proxy = new QGraphicsProxyWidget(this);
    m_proxy->setWidget(m_webView);
    m_proxy->setPos(0, 0);

    m_page = m_webView->page();
    m_ownPage = false;
    m_mainFrame = new QWebFrame(m_page, this);

    // Forward signals
    connect(m_webView, &QWebEngineView::loadStarted, this, &QGraphicsWebView::onPageLoadStarted);
    connect(m_webView, &QWebEngineView::loadFinished, this, &QGraphicsWebView::onPageLoadFinished);
    connect(m_webView, &QWebEngineView::loadProgress, this, &QGraphicsWebView::onPageLoadProgress);
    connect(m_webView, &QWebEngineView::urlChanged, this, &QGraphicsWebView::onUrlChanged);
    connect(m_webView, &QWebEngineView::titleChanged, this, &QGraphicsWebView::onTitleChanged);
}

QWebFrame* QGraphicsWebView::mainFrame() const
{
    return m_mainFrame;
}

QWebEnginePage* QGraphicsWebView::page() const
{
    return m_page;
}

void QGraphicsWebView::setPage(QWebEnginePage *page)
{
    if (m_ownPage && m_page) {
        delete m_page;
    }
    m_page = page;
    m_ownPage = false;
    if (m_webView) {
        m_webView->setPage(page);
    }
    // Recreate the frame wrapper for the new page
    if (m_mainFrame) {
        delete m_mainFrame;
    }
    m_mainFrame = new QWebFrame(m_page, this);
}

QWebEngineSettings* QGraphicsWebView::settings() const
{
    if (m_page)
        return m_page->settings();
    return QWebEngineProfile::defaultProfile()->settings();
}

QUrl QGraphicsWebView::url() const
{
    return m_webView ? m_webView->url() : QUrl();
}

void QGraphicsWebView::setUrl(const QUrl &url)
{
    if (m_webView)
        m_webView->setUrl(url);
}

void QGraphicsWebView::load(const QUrl &url)
{
    if (m_webView)
        m_webView->load(url);
}

void QGraphicsWebView::setHtml(const QString &html, const QUrl &baseUrl)
{
    if (m_webView)
        m_webView->setHtml(html, baseUrl);
}

QString QGraphicsWebView::title() const
{
    return m_webView ? m_webView->title() : QString();
}

qreal QGraphicsWebView::zoomFactor() const
{
    return m_page ? m_page->zoomFactor() : 1.0;
}

void QGraphicsWebView::setZoomFactor(qreal factor)
{
    if (m_page)
        m_page->setZoomFactor(factor);
}

void QGraphicsWebView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
    // The proxy widget handles painting
}

QRectF QGraphicsWebView::boundingRect() const
{
    return QRectF(QPointF(0, 0), geometry().size());
}

QPainterPath QGraphicsWebView::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

QSizeF QGraphicsWebView::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    Q_UNUSED(constraint);
    switch (which) {
    case Qt::MinimumSize:
        return QSizeF(100, 100);
    case Qt::PreferredSize:
        return geometry().size();
    case Qt::MaximumSize:
        return QSizeF(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    default:
        return QSizeF();
    }
}

void QGraphicsWebView::resize(const QSizeF &size)
{
    QGraphicsWidget::resize(size);
    if (m_proxy) {
        m_proxy->resize(size);
    }
    if (m_webView) {
        m_webView->resize(size.toSize());
    }
}

void QGraphicsWebView::resize(qreal w, qreal h)
{
    resize(QSizeF(w, h));
}

QSizeF QGraphicsWebView::size() const
{
    return geometry().size();
}

bool QGraphicsWebView::event(QEvent *event)
{
    return QGraphicsWidget::event(event);
}

void QGraphicsWebView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsWidget::mousePressEvent(event);
}

void QGraphicsWebView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsWidget::mouseReleaseEvent(event);
}

void QGraphicsWebView::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    QGraphicsWidget::wheelEvent(event);
}

void QGraphicsWebView::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QGraphicsWidget::dropEvent(event);
}

void QGraphicsWebView::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsWidget::hoverEnterEvent(event);
}

void QGraphicsWebView::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsWidget::hoverLeaveEvent(event);
}

QVariant QGraphicsWebView::itemChange(GraphicsItemChange change, const QVariant &value)
{
    return QGraphicsWidget::itemChange(change, value);
}

void QGraphicsWebView::onPageLoadFinished(bool ok)
{
    emit loadFinished(ok);
}

void QGraphicsWebView::onPageLoadStarted()
{
    emit loadStarted();
}

void QGraphicsWebView::onPageLoadProgress(int progress)
{
    emit loadProgress(progress);
}

void QGraphicsWebView::onUrlChanged(const QUrl &url)
{
    emit urlChanged(url);
}

void QGraphicsWebView::onTitleChanged(const QString &title)
{
    emit titleChanged(title);
}

// ============================================================
// QWebFrame compatibility implementation
// ============================================================

QWebFrame::QWebFrame(QWebEnginePage *page, QObject *parent)
    : QObject(parent)
    , m_page(page)
{
    if (m_page) {
        connect(m_page, &QWebEnginePage::loadFinished, this, &QWebFrame::loadFinished);
        connect(m_page, &QWebEnginePage::urlChanged, this, &QWebFrame::urlChanged);
        connect(m_page, &QWebEnginePage::titleChanged, this, &QWebFrame::titleChanged);

        // Emit javaScriptWindowObjectCleared when a new page load starts
        // In WebEngine, this is approximated by injecting at DocumentCreation
        connect(m_page, &QWebEnginePage::loadStarted, this, [this]() {
            emit javaScriptWindowObjectCleared();
        });

        // Approximate initialLayoutCompleted with loadFinished
        connect(m_page, &QWebEnginePage::loadFinished, this, [this](bool ok) {
            Q_UNUSED(ok);
            emit initialLayoutCompleted();
        });
    }
}

void QWebFrame::evaluateJavaScript(const QString &scriptSource)
{
    if (m_page) {
        m_page->runJavaScript(scriptSource);
    }
}

QVariant QWebFrame::evaluateJavaScriptSync(const QString &scriptSource)
{
    // Note: QWebEngine doesn't support synchronous JS evaluation.
    // This is a best-effort implementation that runs async.
    QVariant result;
    if (m_page) {
        bool done = false;
        m_page->runJavaScript(scriptSource, [&result, &done](const QVariant &v) {
            result = v;
            done = true;
        });
        // Spin event loop briefly to get result (not ideal but compatible)
        QApplication::processEvents();
    }
    return result;
}

void QWebFrame::addToJavaScriptWindowObject(const QString &name, QObject *object)
{
    Q_UNUSED(name);
    Q_UNUSED(object);
    // In Qt WebEngine, this is done via QWebChannel.
    // The page must have a QWebChannel set up, and the JS side must
    // include qwebchannel.js. For now, set up the channel if not already done.
    if (m_page) {
        QWebChannel *channel = m_page->webChannel();
        if (!channel) {
            channel = new QWebChannel(m_page);
            m_page->setWebChannel(channel);
        }
        channel->registerObject(name, object);
    }
}

QUrl QWebFrame::url() const
{
    return m_page ? m_page->url() : QUrl();
}

QString QWebFrame::title() const
{
    return m_page ? m_page->title() : QString();
}

QSize QWebFrame::contentsSize() const
{
    return m_page ? m_page->contentsSize().toSize() : QSize();
}

QRect QWebFrame::geometry() const
{
    // Approximate with the view's geometry
    return QRect(QPoint(0, 0), contentsSize());
}

qreal QWebFrame::zoomFactor() const
{
    return m_page ? m_page->zoomFactor() : 1.0;
}

void QWebFrame::setUrl(const QUrl &url)
{
    if (m_page)
        m_page->setUrl(url);
}

void QWebFrame::setHtml(const QString &html, const QUrl &baseUrl)
{
    if (m_page)
        m_page->setHtml(html, baseUrl);
}

void QWebFrame::render(QPainter *painter)
{
    Q_UNUSED(painter);
    // In WebEngine, rendering is handled by the compositing layer.
    // Direct QPainter rendering is not supported.
    // For screenshot purposes, use QWebEngineView::grab() instead.
}
