#pragma once

#include <exception>
#include <string>

class MapException : public std::exception {
public:
    MapException(const std::string& message, const std::string& location);

    const char* what() const noexcept override;
    const char* where() const noexcept;

private:
    std::string m_message;
    std::string m_location;
};