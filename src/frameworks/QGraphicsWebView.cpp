/**
 * @file QGraphicsWebView.cpp
 * @brief Implementation of QGraphicsWebView using QWebEngineView + QGraphicsProxyWidget.
 */
#include "QGraphicsWebView.h"

QGraphicsWebView::QGraphicsWebView(QGraphicsItem *parent)
    : QGraphicsWidget(parent)
    , m_webView(new QWebEngineView())
    , m_proxy(nullptr)
    , m_mainFrame(new QWebFrame(this))
{
    // Embed the QWebEngineView as a proxy widget in the graphics scene
    m_proxy = new QGraphicsProxyWidget(this);
    m_proxy->setWidget(m_webView);

    // Wire up the QWebFrame shim
    m_mainFrame->setPage(m_webView->page());

    // Forward signals
    connect(m_webView, &QWebEngineView::loadStarted, this, &QGraphicsWebView::loadStarted);
    connect(m_webView, &QWebEngineView::loadFinished, this, &QGraphicsWebView::loadFinished);
    connect(m_webView, &QWebEngineView::loadProgress, this, &QGraphicsWebView::loadProgress);
    connect(m_webView, &QWebEngineView::urlChanged, this, &QGraphicsWebView::urlChanged);
    connect(m_webView, &QWebEngineView::titleChanged, this, &QGraphicsWebView::titleChanged);
    connect(m_webView, &QWebEngineView::iconChanged, this, &QGraphicsWebView::iconChanged);
}

QGraphicsWebView::~QGraphicsWebView()
{
    // m_proxy owns m_webView (via setWidget), both are children of this
}

QWebEnginePage* QGraphicsWebView::page() const
{
    return m_webView->page();
}

void QGraphicsWebView::setPage(QWebEnginePage *page)
{
    m_webView->setPage(page);
    m_mainFrame->setPage(page);
}

QWebEngineSettings* QGraphicsWebView::settings() const
{
    return m_webView->page()->settings();
}

QUrl QGraphicsWebView::url() const
{
    return m_webView->url();
}

void QGraphicsWebView::setUrl(const QUrl &url)
{
    m_webView->setUrl(url);
}

void QGraphicsWebView::load(const QUrl &url)
{
    m_webView->load(url);
}

void QGraphicsWebView::setHtml(const QString &html, const QUrl &baseUrl)
{
    m_webView->setHtml(html, baseUrl);
}

QString QGraphicsWebView::title() const
{
    return m_webView->title();
}

qreal QGraphicsWebView::zoomFactor() const
{
    return m_webView->zoomFactor();
}

void QGraphicsWebView::setZoomFactor(qreal factor)
{
    m_webView->setZoomFactor(factor);
}

void QGraphicsWebView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // The proxy widget handles the actual painting
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void QGraphicsWebView::resize(const QSizeF &size)
{
    QGraphicsWidget::resize(size);
    if (m_proxy)
        m_proxy->resize(size);
}

void QGraphicsWebView::resize(qreal w, qreal h)
{
    resize(QSizeF(w, h));
}
