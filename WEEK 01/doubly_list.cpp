#include<iostream>
using namespace std;

static int size_of_dlist;
template<typename T> class Noded {
    public:
        T data;
        Noded *forw;
        Noded *back;

        Noded(T data){
            this->data = data;
            this->forw = NULL;
            this->back = NULL;
            size_of_dlist++;
        }
};

template<typename T> class DoublyList {
    private:
        Noded<T> *head , *tail;
    
    public:
        DoublyList(){
            head = NULL;
            tail = NULL;
        }

	~DoublyList(){
		free_memory();
	}

        void push_back(T data);
        void push_front(T data);
        void push_at_loc(int loc,T data);
        void remove_front();
        void remove_back();
        void remove_at_loc(int loc);
        void display_forward();
        void display_backward();
	bool find(T key);
	void free_memory();
};

template<typename T> void DoublyList<T> :: push_back(T data){
    Noded<T> *node = new Noded<T>(data);

    if(node == NULL){
        cout<<"Yups May Be Heap Full !!!"<<endl;
        return;
    }
    else if(head == NULL){
        head = node;
        tail = node;
    }
    else {
        node->back = tail;
        tail->forw = node;
        node->forw = NULL;
        tail = node;
    }
}

template<typename T> void DoublyList<T> :: push_front(T data){
    if(head == NULL) {
        push_back(data);
        return;
    }

    Noded<T> *node = new Noded<T>(data);
    if(node == NULL){
        cout<<"Yups May Be Heap Full !!!"<<endl;
        return;
    }else {
        head->back = node;
        node->forw = head;
        node->back = NULL;
        head = node;
    }
}

template<typename T> void DoublyList<T> :: push_at_loc(int loc,T data){
    if(head == NULL && loc == 0){
        push_back(data);
        return;
    }
    else if(head != NULL && loc == 0){
        push_front(data);
    }
    else if(head != NULL && loc == size_of_dlist){
        push_back(data);
        return;
    }else if(loc > size_of_dlist-1){
        return;
    }
    else{
        Noded<T> *node = new Noded<T>(data);
        if(node == NULL){
            cout<<"Yups May Be Heap Full !!!"<<endl;
            return;
        } else{
            Noded<T> *temp = head ;
            int count = 0;
            while(count < loc - 1){
                temp = temp->forw;
                count++;
            }
            node->forw = temp->forw;
            temp->forw = node;
            temp->forw->back = node;
            node->back = temp;
        }
    }
}

template<typename T> void DoublyList<T> :: remove_front(){
    if(head == NULL){
        return;
    }
    else{
        Noded<T> *temp = head;
        head = head->forw;
        head->back = NULL;
        delete temp;
        temp = NULL;
        size_of_dlist--;
    }

    if(size_of_dlist == 0){
            head = NULL;
            tail = NULL;
    }
}

template<typename T> void DoublyList<T> :: remove_back(){
    if(head == NULL){
        return;
    }else {
        Noded<T> *temp = tail;
        tail = tail->back;
        tail->forw = NULL;
        delete temp;
        temp = NULL;
        size_of_dlist--;
    }

    if(size_of_dlist == 0){
            head = NULL;
            tail = NULL;
    }
}

template<typename T> void DoublyList<T> :: remove_at_loc(int loc){
    if(head == NULL){
        return;
    }
    else if(head != NULL && loc == 0){
        remove_front();
    }
    else if(head != NULL && loc == size_of_dlist - 1){
        remove_back();
        return;
    }else if(loc > size_of_dlist-1){
        return;
    }
    else{
            Noded<T> *temp = head ;
            int count = 0;
            while(count < loc - 1){
                temp = temp->forw;
                count++;
            }
            Noded<T> *delNode = temp->forw;
            temp->forw = delNode->forw;
            delNode->forw->back = temp;
            delete delNode;
            delNode = NULL;
            size_of_dlist--;
        }

    if(size_of_dlist == 0){
            head = NULL;
            tail = NULL;
    }
}

template<typename T> void DoublyList<T> :: display_forward(){
    if(head == NULL)
        return;

    Noded<T> *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->forw;
    }
    cout<<endl;
}

template<typename T> void DoublyList<T> :: display_backward(){
    if(head == NULL)
        return;

    Noded<T> *temp = tail;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->back;
    }
    cout<<endl;
}

template<typename T> bool DoublyList<T> :: find(T key){
    Noded<T> *temp = head;
    while(temp != NULL){
        if(temp->data == key)
            return true;
        temp = temp->forw;
    }
    return false;
}

template<typename T> void DoublyList<T> :: free_memory(){
        Noded<T> *temp = head;
        while(temp != NULL){
                Noded<T> *free_block = temp;
                temp = temp->forw;
                delete free_block;
                free_block = NULL;
        }
}

