# Knn Classifier Server

Welcome to our amazing Knn Classifier Server

In this assignment we were giving the task of making a server and a client for to classify knn files.

This Assignment has 2 parts, the client and the server, in this README we will explain how to compile, run and use those 2 parts, as well as how they were made.

This assignment was implemented with multithreading, and our server is able to handle multiple clients at the same time.

## How to Comple

To complie this code you need to first clone it:

```bash
  gh repo clone nello0b/Multi-Algorithm-KNN-Service
```

And then use the `make` command:

```bash
  make
```

If you want delete the `.o` and `.out` files, you can use the `clean` command:

```bash
  make clean
```

## How to Run

To use our Knn Classifier, you need to first run the server with the following command after you complied the code:

```bash
  ./server.out [port]
```

replace the `[port]` with the port you will want the server to listen to, for excample, if you want to server to listen to port 5555, the your run command should be:

```bash
  ./server.out 5555
```

The you should run the client with the fullowing command:

```bash
  ./server.out [ip] [port]
```

Replace the `[ip]`, and `[port]` with the ip and port of the server, for excample, if your server is listening to port 5555 and it is running on your local machine, so its ip is the localhost, your run command should be:

```bash
  ./server.out 127.0.0.1 5555
```

If you did everything correctly, you should see the following menu:

```bash
Welcome to the KNN Classifier Server. Please choose an option:
1.  upload an unclassified csv data file
2.  algorithm settings
3.  classify data
4.  display results
5.  download results
8.  exit
```

#### Edge Cases

1. If you entered to the wrong number of run arguments, the server/client will print the following and then terminate:

```bash
Invalid arguments, please insert the right number of arguments when running
```

2. If you didn't incerted an appropriet number that can be used as a port, the client/server will print the following and then terminate:

```bash
Invalid argument, please enter only integer as the port
```

## How to Use

When you see the menu, it means that everything is up and running and that the client successfully connected to the server.
Now you can enter 1 of 6 commands, by entering the number to their left.

```bash
Welcome to the KNN Classifier Server. Please choose an option:
1.  upload an unclassified csv data file
2.  algorithm settings
3.  classify data
4.  display results
5.  download results
8.  exit
```

If inputed a numebr that there isn't a coresponding command for the client will print the following and then will print the menu again for you to try again:

```bash
Command [the number you entered] doesn't exists
```

### Command 1

There you will be asked to input the path of 2 `.csv` files, the a training file, which is classify, and a test file, which is unclassified. The train file will be used to classify the test file.

For example, if you want to uploade `beans_Classified.csv` and `beans_UnClassified.csv` which are at `datasets/beans` you would need to input:

```bash
Please upload your local train CSV file.
datasets/beans/beans_Classified.csv         <<<[what you will need to input]
Please upload your local test CSV file.
datasets/beans/beans_UnClassified.csv       <<<[what you will need to input]
```

#### Edge Cases

1. If one or two of the of the following paths isn't valide the command will fail and the client will print the following and then will print the menu again for you to try again:

```bash
unable to locate file
```

2. If the size of the vectors in the train and test files are not eqaul, the the command will fail and the client will print the following and then will print the menu again for you to try again:

```bash
Invalid argument, please give proper file
```

3. If the sizes of every vector in the train or test file doesn't have the same size, the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
invalid input please send a file where every vector is the same size
```

4. If the vectors in the train and test file doesn't contain only numbers as their elements (except the last element in the train file), the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
invalid input
```

### Command 2

Here you can change the alrgoritem settings of the Knn Classifie. When you enter this command you will see the current `k` and `Distance Algorithm` like this:

```bash
The current KNN parameters are: K = [k], distance metric = [Distance Algorithm]
```

For example, if you `k` is 7 and your `Distance Algorithm` is `Taxicab Geometry Distance Algorithm`:

```bash
The current KNN parameters are: K = 7, distance metric = MAN
```

Then you will get the apportunity to change your `k` and `Distance Algorithm` by inputing the folliwng:

```bash
[k] [Distance Algorithm]
```

- **K** - the number of neighbors we want to check nearness to (the k, in "knn").
- **Distance Algorithm** - 1 the following 5 algoritems, each can be used to find a distance between 2 vectors:

| Distance Algorithm        | Code |
| ------------------------- | ---- |
| Euclidean Distance        | AUC  |
| Taxicab Geometry Distance | MAN  |
| Chebyshev Distance        | CHB  |
| Canberra Distance         | CAN  |
| Minkowski Distance        | MIN  |

For example, if you want to check the 3 nearness neighbors and use the Canberra Distance Algorithm, you need to input:

```bash
7 MAN
```

Note that even if you wouldn't enter this command, the Classifier will be set the the defaults **k = 5** and **Distance Algorithm = AUC (Euclidean Distance)**.

Note that if you enterd `ENTER` without inputting anything, no change will be made.

If you enterd the new settings successfully the client will print the folliwng:

#### Edge Cases

1. If you you didn't inputted an invalid string for k, the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
invalid value for K
```

2. If you you didn't inputted an invalid Distance Algorithm Code (either `AUC`, `MAN`, `CHB`, `CAN` or `MIN`), the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
invalid value for metric
```

### Command 3

This command will classify the vectors in the test file using the vectors in the train files, this may take some time depending on the size of the `.csv` file you entered. After the classification will end the client will print the following:

```bash
classifying data complete
```

#### Edge Cases

1. If you didn't uploaded an train and test files yet via `command 1`, the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
please upload data
```

2. If the `k` you inputted in `command 2` or the default k is bigger then the size of the train file, the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
invalid argument, please enter k between 1 to [the size of the vectors in the train file]
```

### Command 4

This command will print a list of the newly classifie vectors.
For example, if you uploaded `iris_classified.csv` and `iris_Unclassified.csv` via `command 1` and then classified them via `command 3`, and you used the defult `k` and `Distance Algorithm`, the client will print the following:

```bash
1 Iris-setosa
2 Iris-versicolor
3 Iris-virginica
4 Iris-versicolor
5 Iris-versicolor
6 Iris-setosa
7 Iris-virginica
8 Iris-setosa
9 Iris-virginica
10 Iris-setosa
11 Iris-versicolor
12 Iris-virginica
13 Iris-virginica
14 Iris-versicolor
15 Iris-setosa
Done.
```

#### Edge Cases

1. If you didn't uploaded train and test files with `command 1`, the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
‫‪data‬‬‫‪upload‬‬ ‫‪please‬‬
```

2. If you didn't classified the test with `command 3`, the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
‫‪data‬‬‫‪the‬‬ ‫‪classify‬‬ ‫‪please‬‬
```

### Command 5

This command get a path as in input and will write the classification of the test file.
For example, if you inputed the following path:

```bash
iris.txt
```

And you you also uploaded `iris_classified.csv` and `iris_Unclassified.csv` via `command 1` and then classified them via `command 3`, and you used the defult `k` and `Distance Algorithm`, the client write the following into the file `iris.txt`:

```bash
1 Iris-setosa
2 Iris-versicolor
3 Iris-virginica
4 Iris-versicolor
5 Iris-versicolor
6 Iris-setosa
7 Iris-virginica
8 Iris-setosa
9 Iris-virginica
10 Iris-setosa
11 Iris-versicolor
12 Iris-virginica
13 Iris-virginica
14 Iris-versicolor
15 Iris-setosa
```

#### Edge Cases

1. If you didn't uploaded train and test files with `command 1`, the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
‫‪data‬‬‫‪upload‬‬ ‫‪please‬‬
```

2. If you didn't classified the test with `command 3`, the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
‫‪data‬‬‫‪the‬‬ ‫‪classify‬‬ ‫‪please‬‬
```

3. If the path you inputted isn't a valide path, the command will fail the client will print the following and then will print the menu again for you to try again:

```bash
unable to locate file
```

### Command 8

This command will exit the Knn Classifier Server, after that command the client will terminate.

## Structure

### server_main and client_main

These are the main entry points for the server and client programs respectively. They handle the overall flow of the program by instantiating necessary classes and calling methods on them.

### KnnClassifier

This class serves as a wrapper for the KNN algorithm. It contains methods for setting the training and test data, setting the value of k, and classifying the test data. It also contains methods for getting the results of the classification.

#### Knn

This class contains the implementation of the KNN algorithm. It has a method for finding the k nearest neighbors of a given input vector, and a method for classifying the input vector based on the majority class of its nearest neighbors.

### Socket, Client and Server

These classes provide a basic implementation of the socket programming model. The Socket class contains the basic functionality for initializing and managing a socket, and the Client and Server classes inherit from Socket and provide additional functionality specific to clients and servers respectively.

#### SmartClient and SmartServer

These classes inherit from the Client and Server classes and provide additional functionality for sending and receiving messages using the MessageProtocol encoding and decoding. They also provide methods for handling specific types of messages, such as file transfer and input/output commands.

##### SocketData

This class contains information about a connected client such as their IP address and port number. It is used by the SmartServer class to keep track of connected clients.

### CLI

This class responsible for communication between the server and the client, it contains the server socket as a member and has the ability to create a command set that will speak with a specific client. This class's start method is the one with runs in a detached thread.

#### Command

This class provides an interface for defining a command and its behavior. It contains a method for executing the command and a method for checking if a given string matches the command.

### DefaultIO

This class provides default implementations for handling input and output through the command line. It contains methods for printing messages to the console and reading input from the user.

#### SocketIO

This class provides an implementation for handling input and output through a socket. It contains methods for sending and receiving messages through a socket and a method for handling incoming messages.

## General Edge Cases

1. If the socket wasn't able to be initialized the relevent side will print and then the program will terminate:

```bash
Error creating socket
```

2. On the server side, if there was an error in the binding procces the program will print:

```bash
Error binding socket
```

3. On the server side, if there was an error while listening to connections the program will print:

```bash
Error listening to a socket
```

4. If there was an error sending a messege the relevent side will print:

```bash
Error sending
```

5. On the client side if the connection got close the server, the program will print:

```bash
Connection closed
```

6. On the server side, if there was an error while trying to accept a client, the program will print:

```bash
Error accepting client
```

7. On the client side, if there was an error while trying to connecting to server, the program will print:

```bash
Error connecting to server
```

# THANK YOU FOR READING (̿▀̿‿ ̿▀̿ ̿)
