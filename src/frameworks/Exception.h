// Stub for pdf-merger Exception.h
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>
#include <stdexcept>

namespace merge_lib {

class Exception : public std::runtime_error
{
public:
    Exception(const std::string &msg) : std::runtime_error(msg) {}
};

} // namespace merge_lib

#endif // EXCEPTION_H
