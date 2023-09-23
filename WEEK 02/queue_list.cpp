#include<iostream>
#include"singly_list.cpp"
using namespace std;


template<typename T> class QueueList {
	
	public:
		SinglyList<T> qu;

		void enqueue(T data);
		void dequeue();
		T front();
};


template<typename T> void QueueList<T> :: enqueue(T data){
	
	qu.push_back(data);
}


template<typename T> void QueueList<T> :: dequeue() {
	qu.delete_front();
}

template<typename T> T QueueList<T> :: front(){

	return (qu.head)->node_data;
}

