
# makefile for compiling indivisualy
all: compile_front
all: compile_end
all: compile_loc
compile_front: dynamic_array.o singly_list.o ins_del_at_front.o 
	g++ dynamic_array.o singly_list.o ins_del_at_front.o  -o front
dynamic_array.o: dynamic_array.cpp
	g++ -c dynamic_array.cpp
singly_list.o: singly_list.cpp
	g++ -c singly_list.cpp
ins_del_at_front.o: ins_del_at_front.cpp
	g++ -c ins_del_at_front.cpp

compile_end: dynamic_array.o singly_list.o ins_del_at_end.o 
	g++ dynamic_array.o singly_list.o ins_del_at_end.o -o end
dynamic_array.o: dynamic_array.cpp
	g++ -c dynamic_array.cpp
singly_list.o: singly_list.cpp
	g++ -c singly_list.cpp
ins_del_at_end.o: ins_del_at_end.cpp
	g++ -c ins_del_at_end.cpp

compile_loc: dynamic_array.o singly_list.o ins_del_at_loc.o
	g++ dynamic_array.o singly_list.o ins_del_at_loc.o -o loc
dynamic_array.o: dynamic_array.cpp
	g++ -c dynamic_array.cpp
singly_list.o: singly_list.cpp
	g++ -c singly_list.cpp
ins_del_at_end.o: ins_del_at_end.cpp
	g++ -c ins_del_at_loc.cpp


