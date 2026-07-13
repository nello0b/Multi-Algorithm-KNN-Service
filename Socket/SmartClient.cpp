#include "SmartClient.h"

SmartClient::SmartClient(int server_port, const char *ip_address) : Client(server_port, ip_address)
{
}

// Destructor
SmartClient::~SmartClient()
{
    // Disconnect from the server
    disconnect();
}

// Send a line of text to the server
void SmartClient::sendline()
{
    // Check if the client is initialized
    checkIfinitialized();

    // Get input from the user
    string input;
    getline(cin, input);
    // Send the input to the server
    sendMessage(MessageData::encode(INPUT, false, input));
}

// Print the received message
void SmartClient::print()
{
    cout << m_message.message() << endl;
}

void SmartClient::uploadFile(string path)
{
    // Check if the client is initialized
    checkIfinitialized();
    // Open the file
    ifstream file;
    if (!file.is_open())
    {
        file.open(path);
        if (file.fail())
        {
            // If the file couldn't be opened, send a message to the server
            cout << "input invalid" << endl;
            sendMessage(MessageData::encode(UNABLE_TO_LOCATE_FILE, true, ""));
            return;
        }
    }
    // Read the file line by line
    string line;
    string nextLine;
    bool toRead;
    getline(file, line);
    line += "\n";
    do
    {
        toRead = getline(file, nextLine) ? true : false;
        nextLine += "\n";
        // Send each line to the server
        sendMessage(MessageData::encode(LINE_FROM_FILE, toRead, line));
        if (toRead)
        {
            line = nextLine;
        }
    } while (toRead);

    // Close the file
    if (file.is_open())
    {
        file.close();
    }
}

void SmartClient::writeToFile(string path)
{
    // Check if the client is initialized
    checkIfinitialized();

    // Concatenate the messages received from the server
    string message = "";
    while (true)
    {
        message += (m_message.message() + "\n");
        if (!m_message.toContinue())
        {
            break;
        }
        receive();
    }

    // Check if the path is valid
    ofstream file;
    if (!file.is_open())
    {
        file.open(path);
        if (file.fail())
        {
            // If the file couldn't be opened, send a message to the server
            cout << "unable to locate file" << endl;
            return;
        }
    }

    // Write the concatenated messages to the file in a separate thread
    thread t1(&SmartClient::writeMessageToFile, this, path, message);
    t1.detach();
}

void SmartClient::writeMessageToFile(string path, string message)
{
    // Open the file
    ofstream file(path);
    if (!file.is_open())
    {
        file.open(path);
    }

    // Write the message to the file line by line
    stringstream ss(message);
    string line;
    while (getline(ss, line))
    {
        file << line << endl;
    }

    // Close the file
    if (file.is_open())
    {
        file.close();
    }
}

bool SmartClient::execute()
{
    // Check if the client is initialized
    checkIfinitialized();

    // Flag to check if the client should continue running
    bool toContinue = true;
    string path;

    // Switch statement to handle different types of messages received from the server
    switch (m_message.code())
    {
    case GETLINE:
        // Send a line of input to the server
        sendline();
        break;

    case PRINT:
        // Print the message received from the server
        print();
        break;

    case UPLOAD_FILE:
        // Upload a file to the server
        getline(cin, path);
        uploadFile(path);
        break;

    case WRITE_LINE_TO_FILE:
        // Write the received message to a file
        getline(cin, path);
        writeToFile(path);
        break;

    case DISCONNECT:
        // Disconnect the client from the server
        toContinue = false;
        break;

    default:
        break;
    }

    return toContinue;
}

void SmartClient::receive()
{
    // Check if the client is initialized
    checkIfinitialized();

    // Receive message from the server
    m_message = MessageData(receiveMessage());
}

void SmartClient::start()
{
    // Initialize the client
    initialize();

    // Connect to the server
    connectToServer();
}
