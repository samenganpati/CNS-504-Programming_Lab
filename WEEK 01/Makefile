all:compile_main
compile_main: dynamic_array.o singly_list.o doubly_list.o circular_list.o main.o 
	g++ dynamic_array.o singly_list.o doubly_list.o circular_list.o main.o -o main
dynamic_array.o: dynamic_array.cpp
	g++ -c dynamic_array.cpp
singly_list.o: singly_list.cpp
	g++ -c singly_list.cpp
doubly_list.o: doubly_list.cpp
	g++ -c doubly_list.cpp
circular_list.o: circular_list.cpp
	g++ -c circular_list.cpp
main.o: main.cpp
	g++ -c main.cpp
