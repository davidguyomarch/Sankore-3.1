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
#include <QEventLoop>
#include <QTimer>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineSettings>
#include <QWebEngineProfile>
#include <QWebChannel>
#include <QWebEngineScript>
#include <QWebEngineScriptCollection>

// Compatibility shim for QWebFrame (removed in Qt6)
// Provides the same API surface using QWebChannel + QWebEnginePage
class QWebFrame : public QObject
{
    Q_OBJECT
public:
    QWebFrame(QObject *parent = nullptr)
        : QObject(parent), m_page(nullptr), m_channel(nullptr) {}

    void setPage(QWebEnginePage *page) {
        if (m_page) {
            disconnect(m_page, nullptr, this, nullptr);
        }
        m_page = page;
        if (m_page) {
            // Setup QWebChannel for JS↔C++ communication
            if (!m_channel) {
                m_channel = new QWebChannel(this);
            }
            m_page->setWebChannel(m_channel);

            // Inject qwebchannel.js on every page load
            QWebEngineScript channelScript;
            channelScript.setName("qwebchannel");
            channelScript.setSourceCode(
                "new QWebChannel(qt.webChannelTransport, function(channel) {"
                "  window.__qt_webchannel_objects = channel.objects;"
                "  for (var name in channel.objects) {"
                "    window[name] = channel.objects[name];"
                "  }"
                "});"
            );
            channelScript.setInjectionPoint(QWebEngineScript::DocumentReady);
            channelScript.setWorldId(QWebEngineScript::MainWorld);
            channelScript.setRunsOnSubFrames(false);
            m_page->scripts().insert(channelScript);

            // Emit signals on page load
            connect(m_page, &QWebEnginePage::loadFinished, this, [this](bool ok) {
                if (ok) {
                    emit javaScriptWindowObjectCleared();
                    emit initialLayoutCompleted();
                }
            });
        }
    }

    void setScrollBarPolicy(Qt::Orientation, Qt::ScrollBarPolicy) {}
    QUrl url() const { return m_page ? m_page->url() : QUrl(); }
    void setUrl(const QUrl &url) { if (m_page) m_page->setUrl(url); }
    QString toHtml() const { return QString(); }

    QVariant evaluateJavaScript(const QString &script) {
        if (!m_page) return QVariant();
        // Fire-and-forget: execute JS without waiting for result
        m_page->runJavaScript(script);
        return QVariant();
    }

    QVariant evaluateJavaScriptSync(const QString &script) {
        if (!m_page) return QVariant();
        // Synchronous evaluation using a local event loop
        QVariant result;
        bool finished = false;
        m_page->runJavaScript(script, [&result, &finished](const QVariant &v) {
            result = v;
            finished = true;
        });
        // Wait up to 1 second for the result
        if (!finished) {
            QEventLoop loop;
            QTimer timer;
            timer.setSingleShot(true);
            connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
            // Use a polling approach since we can't connect to the lambda completion
            timer.start(1000);
            while (!finished && timer.isActive()) {
                loop.processEvents(QEventLoop::AllEvents, 50);
            }
        }
        return result;
    }

    void addToJavaScriptWindowObject(const QString &name, QObject *object) {
        if (!m_channel) {
            m_channel = new QWebChannel(this);
            if (m_page) m_page->setWebChannel(m_channel);
        }
        m_channel->registerObject(name, object);
    }

    QSize contentsSize() const {
        return m_page ? m_page->contentsSize().toSize() : QSize(800, 600);
    }

signals:
    void javaScriptWindowObjectCleared();
    void initialLayoutCompleted();

private:
    QWebEnginePage *m_page;
    QWebChannel *m_channel;
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
    void setMaximumSize(const QSizeF &size) { QGraphicsWidget::setMaximumSize(size); }
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
