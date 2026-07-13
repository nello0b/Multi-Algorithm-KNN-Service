all: client server

client:
	g++ -pthread -std=c++11 client_main.cpp ./Distance/*.cpp ./Package/*.cpp ./Socket/*.cpp -o client.out

server:
	g++ -pthread -std=c++11 server_main.cpp ./Distance/*.cpp ./Package/*.cpp ./Socket/*.cpp ./Knn/*.cpp ./CLI/*.cpp ./CLI/Commands/*.cpp ./CLI/Commands/IOs/*.cpp -o server.out


clean:
	rm -f *.o client.out server.out