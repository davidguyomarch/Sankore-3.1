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



#include "UBStringUtils.h"

#include <QRegularExpression>
#include <algorithm>

QStringList UBStringUtils::sortByLastDigit(const QStringList& sourceList)
{
    // we look for a set of digit after non digits and before a .
    QRegularExpression rx("\\D(\\d+)\\.");

    QMultiMap<int, QString> elements;

    for (const QString& source : sourceList)
    {
        QRegularExpressionMatch match;
        QRegularExpressionMatchIterator it = rx.globalMatch(source);
        while (it.hasNext()) {
            match = it.next();
        }

        int digit = -1;

        if (match.hasMatch())
        {
            digit = match.captured(1).toInt();
        }

        elements.insert(digit, source);
    }

    QStringList result;

    QList<int> keys = elements.keys();
    std::sort(keys.begin(), keys.end());

    for (int key : keys)
    {
        QList<QString> values = elements.values(key);
        std::sort(values.begin(), values.end());
        for (const QString& val : values)
        {
            if (!result.contains(val))
                result << val;
        }
    }

    return result;
}


QString UBStringUtils::netxDigitizedName(const QString& source)
{

    // we look for a set of digit after non digits and at the end
    QRegularExpression rx("\\D(\\d+)");

    QRegularExpressionMatch match;
    QRegularExpressionMatchIterator it = rx.globalMatch(source);
    while (it.hasNext()) {
        match = it.next();
    }

    int digit = -1;

    if (match.hasMatch())
    {
        digit = match.captured(1).toInt();
    }

    QString ret(source);

    if (digit == -1)
    {
        return ret + " 1";
    }
    else
    {
        QString s("%1");
        s = s.arg(digit + 1);
        return ret.replace(match.captured(1), s);
    }
}

QString UBStringUtils::toCanonicalUuid(const QUuid& uuid)
{
    QString s = uuid.toString();

    if(s.startsWith("{"))
            s = s.right(s.length() - 1);

    if(s.endsWith("}"))
            s = s.left(s.length() - 1);


    return s;
}

QString UBStringUtils::toUtcIsoDateTime(const QDateTime& dateTime)
{
    QString isoStr = dateTime.toUTC().toString(Qt::ISODate);
    // In Qt 6, toString(ISODate) for UTC already appends 'Z'
    if (!isoStr.endsWith('Z'))
        isoStr += "Z";
    return isoStr;
}

QDateTime UBStringUtils::fromUtcIsoDate(const QString& dateString)
{
    return QDateTime::fromString(dateString,Qt::ISODate).toLocalTime();
}




