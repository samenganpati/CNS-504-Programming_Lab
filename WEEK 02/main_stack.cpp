#include<iostream>
#include"stack_array.cpp"
#include"stack_list.cpp"

int main() {
        StackArray<int> sa;
        sa.push(100);
        sa.push(200);
        sa.push(300);

        cout<<sa.top()<<endl;

        sa.pop();
        sa.pop();

        cout<<sa.top()<<endl;
        return 0;
}
