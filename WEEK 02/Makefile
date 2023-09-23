all:compile_main_stack
all:compile_main_queue

compile_main_stack: dynamic_array.o singly_list.o stack_array.o stack_list.o main_stack.o 
	g++ dynamic_array.o singly_list.o stack_array.o stack_list.o main_stack.o -o stack
dynamic_array.o: dynamic_array.cpp
	g++ -c dynamic_array.cpp
singly_list.o: singly_list.cpp
	g++ -c singly_list.cpp
stack_array.o: stack_array.cpp
	g++ -c stack_array.cpp
stack_list.o: stack_list.cpp
	g++ -c stack_list.cpp
main_stack.o: main_stack.cpp
	g++ -c main_stack.cpp
	
	
compile_main_queue: dynamic_array.o singly_list.o queue_array.o queue_list.o main_queue.o 
	g++ dynamic_array.o singly_list.o queue_array.o queue_list.o main_queue.o -o queue
dynamic_array.o: dynamic_array.cpp
	g++ -c dynamic_array.cpp
singly_list.o: singly_list.cpp
	g++ -c singly_list.cpp	
queue_array.o: queue_array.cpp
	g++ -c queue_array.cpp
queue_list.o: queue_list.cpp
	g++ -c queue_list.cpp
main_queue.o: main_queue.cpp
	g++ -c main_queue.cpp
