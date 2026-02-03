#ifndef MARKETDATA_XMLPARSER_H
#define MARKETDATA_XMLPARSER_H

#include <string>
#include <stdexcept>

template<class T>
class XmlParser {
public:
    virtual ~XmlParser() = default;

    T read(const std::string& /*xml*/) {
        throw std::runtime_error("Native XML deserialization forbidden");
    }

    std::string write(const T& /*exec*/) {
        throw std::runtime_error("Native XML serialization forbidden");
    }
};

#endif // MARKETDATA_XMLPARSER_H
