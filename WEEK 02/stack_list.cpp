#include<iostream>
#include"singly_list.cpp"
using namespace std;


template<typename T> class Stack {
	
	public:
	SinglyList<T> st;

	void push(T data);
	void pop();
	T top();
};


template<typename T> void Stack<T> :: push(T data){
	
	st.push_back(data);
}

template<typename T> void Stack<T> :: pop(){
	
	st.delete_end();
}

template<typename T> T Stack<T> :: top(){
	
	return (st.tail)->node_data;
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

