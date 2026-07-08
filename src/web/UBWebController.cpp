/*
 * Copyright (C) 2010-2013 Groupement d'Intérêt Public pour l'Education Numérique en Afrique (GIP ENA)
 *
 * This file is part of Open-Sankoré.
 *
 * Open-Sankoré is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License,
 * with a specific linking exception for the OpenSSL project's
 * "OpenSSL" library (or with modified versions of it that use the
 * same license as the "OpenSSL" library).
 *
 * Open-Sankoré is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Open-Sankoré.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file UBWebController.cpp
 * @brief Stub implementation - web browser functionality disabled in Qt6 build.
 *
 * The full UBWebController requires QtWebEngine with a functional browser.
 * This stub provides the necessary symbols to link while the web module
 * is non-functional (QGraphicsWebView is stubbed).
 */

#include <QWidget>
#include <QApplication>
#include <QGuiApplication>
#include <QScreen>
#include <QDesktopServices>

#include "UBWebController.h"
#include "UBOEmbedParser.h"

#include "gui/UBMainWindow.h"
#include "core/UBApplication.h"
#include "core/UBApplicationController.h"


UBWebController::UBWebController(UBMainWindow* mainWindow)
    : QObject(mainWindow->centralWidget())
    , mMainWindow(mainWindow)
    , mCurrentWebBrowser(0)
    , mBrowserWidget(0)
    , mTrapContentController(0)
    , mToolsCurrentPalette(0)
    , mToolsPalettePositionned(false)
    , mDownloadViewIsVisible(false)
{
    mStackedWidget = nullptr;
    for (int i = 0; i < TotalNumberOfWebInstances; i++) {
        mWebBrowserList[i] = 0;
        mToolsPaletteList[i] = 0;
        mToolsPalettePositionnedList[i] = false;
    }
}

UBWebController::~UBWebController()
{
}

void UBWebController::closing()
{
    // NOOP - web browser not functional
}

void UBWebController::adaptToolBar()
{
    // NOOP - web browser not functional
}

QPixmap UBWebController::captureCurrentPage()
{
    return QPixmap();
}

void UBWebController::showTabAtTop(bool attop)
{
    Q_UNUSED(attop);
}

void UBWebController::loadUrl(const QUrl& url)
{
    // Open in system browser since embedded browser is not functional
    QDesktopServices::openUrl(url);
}

QWebEngineView* UBWebController::createNewTab()
{
    return nullptr;
}

QUrl UBWebController::currentPageUrl() const
{
    return QUrl();
}

void UBWebController::show(WebInstance type)
{
    Q_UNUSED(type);
    // Web browser not functional in this build
}

void UBWebController::setupPalettes()
{
}

QPixmap UBWebController::getScreenPixmap()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen)
        return QPixmap();
    return screen->grabWindow(0);
}

void UBWebController::screenLayoutChanged()
{
}

void UBWebController::setSourceWidget(QWidget* pWidget)
{
    Q_UNUSED(pWidget);
}

void UBWebController::toggleWebToolsPalette(bool checked)
{
    Q_UNUSED(checked);
}

void UBWebController::captureWindow()
{
}

void UBWebController::customCapture()
{
}

void UBWebController::toogleMirroring(bool checked)
{
    Q_UNUSED(checked);
}

void UBWebController::captureoEmbed(QUrl currentUrl)
{
    Q_UNUSED(currentUrl);
}

void UBWebController::captureoEmbed()
{
}

void UBWebController::captureEduMedia()
{
}

bool UBWebController::isOEmbedable(const QUrl& pUrl)
{
    Q_UNUSED(pUrl);
    return false;
}

bool UBWebController::hasEmbeddedContent()
{
    return false;
}

void UBWebController::getEmbeddableContent()
{
}

bool UBWebController::isEduMedia(const QUrl& pUrl)
{
    Q_UNUSED(pUrl);
    return false;
}

void UBWebController::copy()
{
}

void UBWebController::paste()
{
}

void UBWebController::cut()
{
}

void UBWebController::activePageChanged()
{
}

void UBWebController::toggleWebTrap(bool checked)
{
    Q_UNUSED(checked);
}

void UBWebController::webTrapContent()
{
}

void UBWebController::onOEmbedParsed(QVector<sOEmbedContent> contents)
{
    Q_UNUSED(contents);
}

void UBWebController::onActionBookmark()
{
}

void UBWebController::initialiazemOEmbedProviders()
{
}

void UBWebController::tutorialWebInstance()
{
}

void UBWebController::webBrowserInstance()
{
}

void UBWebController::paraschoolWebInstance()
{
}

void UBWebController::lookForEmbedContent(QString* pHtml, QString tag, QString attribute, QList<QUrl>* pList)
{
    Q_UNUSED(pHtml); Q_UNUSED(tag); Q_UNUSED(attribute); Q_UNUSED(pList);
}

void UBWebController::checkForOEmbed(QString* pHtml)
{
    Q_UNUSED(pHtml);
}
