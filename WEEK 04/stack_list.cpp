#include<iostream>
#include<climits>
#include"singly_list.cpp"
using namespace std;


template<typename T> class StackList {
	
	public:
	SinglyList<T> st;

	void push(T data);
	void pop();
	bool isEmpty();
	T top();
};


template<typename T> void StackList<T> :: push(T data){	
	st.push_back(data);
}

template<typename T> void StackList<T> :: pop(){
	if(st.tail == NULL)
		return;
	st.delete_end();
}

template<typename T> T StackList<T> :: top(){
	if(st.tail == NULL)
		return INT_MIN;
	return (st.tail)->node_data;
}

template<typename T> bool StackList<T> :: isEmpty(){	
	if(st.tail == NULL)
		return 1;
	return 0;
}

/*int main(){	
	StackList<int> st;
		st.push(100);
		cout << st.top()<<endl;;
		st.pop();
		st.pop();
}*/

