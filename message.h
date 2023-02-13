#pragma once
#include "user.h"

class Message {
    const std::string _from;
    const std::string _to;
    const std::string _message;
public:
    Message(const std::string& _from, const std::string& _to, const std::string& _message)
        : _from(_from), _to(_to), _message(_message) {}
    const std::string& getFrom() const {
        return _from;
    }
    const std::string& getTo() const {
        return _to;
    }
    const std::string& getMessage() const {
        return _message;
    }
};