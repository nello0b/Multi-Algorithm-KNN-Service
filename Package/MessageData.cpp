#include "MessageData.h"

// constructor that initializes the code, toContinue, and message variables
MessageData::MessageData(int code, int toContinue, string message) : m_code(code), m_toContinue(toContinue ? true : false), m_message(message)
{
}

// constructor that initializes the code, toContinue, and message variables with a bool value for toContinue
MessageData::MessageData(int code, bool toContinue, string message) : m_code(code), m_toContinue(toContinue), m_message(message)
{
}

// constructor that initializes the code, toContinue, and message variables by parsing the values from a messageProtocol string
MessageData::MessageData(string messageProtocol) : m_code(stoi(messageProtocol.substr(0, 3))),
                                                   m_toContinue(stoi(messageProtocol.substr(3, 1)) ? true : false),
                                                   m_message(messageProtocol.substr(4))
{
}

// default constructor that initializes the code, toContinue, and message variables with default values
MessageData::MessageData() : m_code(DEFAULT_MESSAGE), m_toContinue(false), m_message("If you see it, you messed up (╥﹏╥)")
{
}

// getter method for the code variable
int MessageData::code() const
{
    return m_code;
}

// getter method for the toContinue variable
bool MessageData::toContinue() const
{
    return m_toContinue;
}

// getter method for the message variable
string MessageData::message() const
{
    return m_message;
}

// method that encodes the code, toContinue, and message variables into a string
string MessageData::encode() const
{
    return encode(code(), toContinue(), message());
}

// static method that encodes the given code, toContinue, and message variables into a string
string MessageData::encode(int code, bool toContinue, string message)
{
    return to_string(code) + to_string(toContinue ? WAIT_FOR_NEXT : STOP) + message;
}
