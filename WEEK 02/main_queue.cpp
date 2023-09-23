#include<iostream>
#include"queue_array.cpp"
#include"queue_list.cpp"

int main() {
        
	QueueArray<string> qa;
	qa.enqueue("A");
	qa.enqueue("B");
	qa.enqueue("C");

	cout << qa.front() << endl;

	qa.dequeue();
	qa.dequeue();

	cout<<qa.front()<<endl;

	QueueList<int> ql;
        ql.enqueue(1);
        ql.enqueue(0);
        ql.enqueue(1);

        cout << ql.front() << endl;

        ql.dequeue();
        ql.dequeue();

        cout<<ql.front()<<endl;
        return 0;
}
