#pragma once
#include <string>

class INPC {
public:
    virtual ~INPC() = default;
    virtual std::string getName() const = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual std::string getType() const = 0;
}; 