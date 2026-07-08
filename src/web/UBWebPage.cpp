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

#include "UBWebPage.h"

#include <QtCore>

// QWebPluginFactory removed in Qt6 - plugin system not available


UBWebPage::UBWebPage(QObject *parent)
    : QWebEnginePage(parent)
{
    mCachedUserAgentString = QWebEnginePage::userAgentForUrl(QUrl());
}

UBWebPage::~UBWebPage()
{
}


void UBWebPage::javaScriptConsoleMessage(const QString &message, int lineNumber, const QString &sourceID)
{
    qDebug("JavaScript> %s (%s:%d)", qPrintable(message), qPrintable(sourceID), lineNumber);
}


QString UBWebPage::userAgentForUrl(const QUrl& url) const
{
    Q_UNUSED(url);
    return mCachedUserAgentString;
}
