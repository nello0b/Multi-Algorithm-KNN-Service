#include "SmartServer.h"

// Send a disconnect message to the client
void SmartServer::disconnectMessage(const SocketData client)
{
	// Send a DISCONNECT message to the client
	sendMessage(MessageData::encode(DISCONNECT, STOP, ""), client);
}

// Constructor for SmartServer, sets the server port
SmartServer::SmartServer(int port) : Server(port)
{
}

// Starts the SmartServer
void SmartServer::start()
{
	initialize();
}

// Receive a message from the client
void SmartServer::receive(const SocketData client)
{
	checkIfinitialized();

	// Receive the message and store it in m_message
	m_message = MessageData(receiveMessage(client));
}

// Send a file to the client
void SmartServer::sendFile(string output, const SocketData client)
{
	checkIfinitialized();
	stringstream ss(output);

	string line;
	string nextLine;
	bool toRead;

	// Get the first line of the file
	getline(ss, line);

	do
	{
		// Get the next line of the file
		toRead = getline(ss, nextLine) ? true : false;

		// Send the current line with a WAIT_FOR_NEXT or STOP status
		sendMessage(MessageData::encode(WRITE_LINE_TO_FILE, toRead ? WAIT_FOR_NEXT : STOP, line), client);

		if (toRead)
		{
			line = nextLine;
		}
	} while (toRead);
}

// Receive a file from the client
string SmartServer::receiveFile(const SocketData client)
{
	checkIfinitialized();
	string result = "";
	string str;
	// Send a message to the client to upload a file
	sendMessage(MessageData::encode(UPLOAD_FILE, STOP, ""), client);

	while (true)
	{
		receive(client);
		// If the client is unable to locate the file, throw an error
		if (m_message.code() == UNABLE_TO_LOCATE_FILE)
		{
			throw std::runtime_error("unable to locate file");
		}
		result += m_message.message();
		if (!m_message.toContinue())
		{
			break;
		}
	}
	return result;
}

// Send a line of text to the client
void SmartServer::sendLine(string output, const SocketData client)
{
	checkIfinitialized();
	string massage = MessageData::encode(PRINT, STOP, output);
	sendMessage(massage, client);
}

// Receive a line of text from the client
string SmartServer::getLine(const SocketData client)
{
	checkIfinitialized();
	string massage = MessageData::encode(GETLINE, STOP, "");
	sendMessage(massage, client);
	receive(client);
	string result = m_message.message();
	return result;
}
