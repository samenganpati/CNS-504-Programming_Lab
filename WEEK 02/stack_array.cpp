#include<iostream>
#include"dynamic_array.cpp"
using namespace std;

template<typename T> class StackArray {
	
	DynamicArray<T> st;
	
	public:
	void push(T data);
	void pop();
	T top();

};	

template<typename T> void StackArray<T> :: push(T data){
	st.push_back(data);
}


template<typename T> void StackArray<T> :: pop(){
	int idx = st.len() - 1;
	st.delete_at_loc(idx);
}

template<typename T> T StackArray<T> :: top(){	
	int idx = st.len() - 1;
	return st.arr[idx];
}

