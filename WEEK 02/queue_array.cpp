#include<iostream>
#include"dynamic_array.cpp"
using namespace std;

template<typename T> class Queue {
	
	public:
		DynamicArray<T> qu;

		void enqueue(T data);
		void dequeue();
		T front();
};

template<typename T> void Queue<T> ::  enqueue(T data) {
	
	qu.push_back(data);
}

template<typename T> void Queue<T> :: dequeue(){
	
	qu.delete_at_loc(0);
}


template<typename T> T Queue<T> :: front(){

	return qu.arr[0];
}



int main() {

	Queue<int> qu;
	qu.enqueue(100);
	qu.enqueue(200);
	qu.enqueue(300);

	cout<<qu.front()<<endl;

	qu.dequeue();
	qu.dequeue();

	cout<<qu.front()<<endl;
	return 0;
}
