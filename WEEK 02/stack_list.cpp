#include<iostream>
#include"singly_list.cpp"
using namespace std;


template<typename T> class StackList {
	
	public:
	SinglyList<T> st;

	void push(T data);
	void pop();
	T top();
};


template<typename T> void StackList<T> :: push(T data){
	
	st.push_back(data);
}

template<typename T> void StackList<T> :: pop(){
	
	st.delete_end();
}

template<typename T> T StackList<T> :: top(){
	
	return (st.tail)->node_data;
}



