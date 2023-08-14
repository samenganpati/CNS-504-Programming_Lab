#include<iostream>
#include"dynamic_array.cpp"
using namespace std;

template<typename T> class Stack {
	
	DynamicArray<T> st;
	
	public:
	void push(T data);
	void pop();
	T top();

};	

template<typename T> void Stack<T> :: push(T data){
	
	st.push_back(data);
}


template<typename T> void Stack<T> :: pop(){

	int idx = st.size - 1;
	st.delete_at_loc(idx);
}

template<typename T> T Stack<T> :: top(){
	
	int idx = st.size - 1;
	return st.arr[idx];
}

int main() {
	Stack<int> s;
	s.push(100);
	s.push(200);
	s.push(300);

	cout<<s.top()<<endl;

	s.pop();
	s.pop();

	cout<<s.top()<<endl;
	return 0;
}
