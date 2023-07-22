#include<iostream>
#include"dynamic_array.cpp"
#include"singly_list.cpp"
#include"doubly_list.cpp"
#include"circular_list.cpp"
using namespace std;

int main() {
	DynamicArray<string> fri;
	fri.push_back("naveen");
	fri.push_back("ganesh");
	fri.push_back("karam");
	fri.push_back("samen");
	fri.insert_at_loc(0,"ravi");
	fri.insert_at_loc(5,"raj");
	cout<<fri.find("sam")<<endl;
	cout<<fri.find("karam")<<endl;
	fri.delete_at_loc(0);
	fri.arr[0] = "saam";
	fri.display_all();

	SinglyList<string> slist;
	slist.push_back("raj");
	slist.push_back("rahul");
	slist.push_back("dilip");
	slist.display_all();
	cout<<slist.find("dilip")<<endl;

	CircularList<string> name;
	name.push_back("samen");
	name.push_front("jeevu");
	name.push_back("jeet");
	name.display_all();
	cout<<name.find("jeet")<<endl;
	return 0;
}
