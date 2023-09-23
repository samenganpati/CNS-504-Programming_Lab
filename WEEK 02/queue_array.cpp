#include<iostream>
#include"dynamic_array.cpp"
using namespace std;

template<typename T> class QueueArray {
	
	public:
		DynamicArray<T> qu;

		void enqueue(T data);
		void dequeue();
		T front();
};

template<typename T> void QueueArray<T> ::  enqueue(T data) {
	
	qu.push_back(data);
}

template<typename T> void QueueArray<T> :: dequeue(){
	
	qu.delete_at_loc(0);
}


template<typename T> T QueueArray<T> :: front(){

	return qu.arr[0];
}




