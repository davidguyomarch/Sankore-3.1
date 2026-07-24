#ifndef UBOEMBEDPARSER_TESTABLE_H
#define UBOEMBEDPARSER_TESTABLE_H

// Expose private methods for testing
#define private public
#include "web/UBOEmbedParser.h"
#undef private

#endif // UBOEMBEDPARSER_TESTABLE_H
