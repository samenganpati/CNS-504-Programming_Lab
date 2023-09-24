all: bfs_fixed_edges
all: bfs_fixed_node
all: dfs_fixed_edges
all: dfs_fixed_node

bfs_fixed_edges: singly_list.o stack_list.o bfs_fixed_edges.o
	g++ singly_list.o stack_list.o bfs_fixed_edges.o -o bfs_edge
singly_list.o: singly_list.cpp
	g++ -c singly_list.cpp
stack_list.o: stack_list.cpp
	g++ -c stack_list.cpp
bfs_fixed_edges.o: bfs_fixed_edges.cpp
	g++ -c bfs_fixed_edges.cpp


bfs_fixed_node: singly_list.o stack_list.o bfs_fixed_node.o
	g++ singly_list.o stack_list.o bfs_fixed_node.o -o bfs_node
singly_list.o: singly_list.cpp
	g++ -c singly_list.cpp
stack_list.o: stack_list.cpp
	g++ -c stack_list.cpp
bfs_fixed_node.o: bfs_fixed_node.cpp
	g++ -c bfs_fixed_node.cpp


dfs_fixed_edges: singly_list.o stack_list.o dfs_fixed_edges.o
	g++ singly_list.o stack_list.o dfs_fixed_edges.o -o dfs_edge
singly_list.o: singly_list.cpp
	g++ -c singly_list.cpp
stack_list.o: stack_list.cpp
	g++ -c stack_list.cpp
dfs_fixed_edges.o: dfs_fixed_edges.cpp
	g++ -c dfs_fixed_edges.cpp


dfs_fixed_node: singly_list.o stack_list.o dfs_fixed_node.o
	g++ singly_list.o stack_list.o dfs_fixed_node.o -o dfs_node
singly_list.o: singly_list.cpp
	g++ -c singly_list.cpp
stack_list.o: stack_list.cpp
	g++ -c stack_list.cpp
dfs_fixed_node.o: dfs_fixed_node.cpp
	g++ -c dfs_fixed_node.cpp


