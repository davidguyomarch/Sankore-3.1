/**
 * @file Merger.h
 * @brief Stub for pdf-merger Merger class.
 * TODO: Replace with real pdf-merger when available.
 */
#ifndef MERGER_H
#define MERGER_H

#include <QString>
#include <QList>

namespace merge_lib {

class Page {};

class Document {
public:
    Document() {}
    ~Document() {}
    QList<Page*> getPages() { return QList<Page*>(); }
};

class Merger {
public:
    Merger() {}
    ~Merger() {}
    void addDocument(Document *) {}
    Document* merge() { return nullptr; }
};

} // namespace merge_lib

#endif // MERGER_H
