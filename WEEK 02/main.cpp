#include<iostream>
#include"stack_array.cpp"
#include"stack_list.cpp"
#include"queue_array.cpp"
#include"queue_list.cpp"

int main() {
        StackArray<int> sa;
        sa.push(100);
        sa.push(200);
        sa.push(300);

        cout<<sa.top()<<endl;

        sa.pop();
        sa.pop();

        cout<<sa.top()<<endl;

	/*StackList<float> sl;
        sl.push(10.50);
        sl.push(20.20);
        sl.push(30.40);

        cout<<sl.top()<<endl;

        sl.pop();
        sl.pop();

        cout<<sl.top()<<endl;

	QueueArray<string> qa;
	qa.enqueue("A");
	qa.enqueue("B");
	qa.enqueue("C");

	cout << qa.front << endl;

	qa.dequeue();
	qa.dequeue();

	cout<<qa.front()<<endl;

	QueueList<bool> ql;
        qa.enqueue(true);
        qa.enqueue(false);
        qa.enqueue(true);

        cout << ql.front << endl;

        ql.dequeue();
        ql.dequeue();

        cout<<ql.front()<<endl;*/
        return 0;
}
