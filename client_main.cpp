#include <iostream>

#include <stdexcept>
#include <string>
#include "Socket/SmartClient.h"
using namespace std;


// function to separate the arguments passed in to the program
// argc is the number of arguments passed in
// argv is the array of arguments passed in
tuple<string, int> seperator(int argc, char *argv[])
{
    // Check if the number of arguments is correct
    if (argc != 3)
    {
        throw invalid_argument("Invalid arguments,please insert the right number of arguments when running");
    }
    // Convert the first argument to a string
    string str(argv[1]);
    int num;
    try
    {
        // Convert the second argument to an integer
        num = stoi(argv[2]);
    }
    catch (const exception &e)
    {
        throw invalid_argument("Invalid argument, please enter only integer as the port");
    }
    // return the arguments as a tuple
    tuple<string, int> tup(str, num);
    return tup;
}


int main(int argc, char *argv[])
{
    tuple<string, int> tup;
    try
    {
        tup = seperator(argc, argv);
    }
    catch (const exception &e)
    {
        cout << "invalid input" << endl;
        return 0;
    }
    // Extract the port and IP address from the tuple
    const int server_port = get<1>(tup);
    const string ip_address =  get<0>(tup);

    // Create a smart client object
    SmartClient client(server_port, ip_address.c_str());

    // Try to initialize the client and connect to the server
    try
    {
        client.start();
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
        cout << "Either the server is closed, or some other error occurred, please check if the server is running and try again." << endl;
        return 0;
    }

    // Run the client
    bool running = true;
    while (running)
    {
        try
        {
            // Receive data from the server
            client.receive();

            // Execute actions based on the received data
            running = client.execute();
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
            running = false;
        }
    }

    // Disconnect the client from the server
    client.disconnect();
    return 0;
}

