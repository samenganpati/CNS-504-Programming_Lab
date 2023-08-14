#include<iostream>
#include"singly_list.cpp"
using namespace std;


template<typename T> class Queue {
	
	public:
		SinglyList<T> qu;

		void enqueue(T data);
		void dequeue();
		T front();
};


template<typename T> void Queue<T> :: enqueue(T data){
	
	qu.push_back(data);
}


template<typename T> void Queue<T> :: dequeue() {
	qu.delete_front();
}

template<typename T> T Queue<T> :: front(){

	return (qu.head)->node_data;
}

int main() {

        Queue<string> qu;
        qu.enqueue("samen");
        qu.enqueue("raj");
        qu.enqueue("dilip");

        cout<<qu.front()<<endl;

        qu.dequeue();
        qu.dequeue();

        cout<<qu.front()<<endl;
        return 0;
}

