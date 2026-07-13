#ifndef MESSAGE_DATA_H
#define MESSAGE_DATA_H

#include <string>
#include "MessageCodes.h"

using namespace std;

class MessageData
{
private:
    // variable for storing the message code
    int m_code;
    // variable for storing whether the message should continue or stop
    bool m_toContinue;
    // variable for storing the message content
    string m_message;

public:
    // constructor that initializes the code, toContinue, and message variables
    MessageData(int code, int toContinue, string message);
    // constructor that initializes the code, toContinue, and message variables with a bool value for toContinue
    MessageData(int code, bool toContinue, string message);
    // constructor that initializes the code, toContinue, and message variables by parsing the values from a messageProtocol string
    MessageData(string messageProtocol);
    // default constructor that initializes the code, toContinue, and message variables with default values
    MessageData();

    // getter method for the code variable
    int code() const;
    // getter method for the toContinue variable
    bool toContinue() const;
    // getter method for the message variable
    string message() const;

    // method that encodes the code, toContinue, and message variables into a string
    string encode() const;
    // static method that encodes the given code, toContinue, and message variables into a string
    static string encode(int code, bool toContinue, string message);
};

#endif // MESSAGE_DATA_H
