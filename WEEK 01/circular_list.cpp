#include<iostream>
using namespace std;

static int size_of_clist;
template<typename T> class Nodec {
    public:
        T node_data;
        Nodec *link;
        Nodec(T data){
            this->node_data = data;
            this->link = NULL;
            size_of_clist++;
        }
};

template<typename T> class CircularList {
    private:
        Nodec<T> *head,*tail;
    public:
        CircularList(){
            head = NULL;
            tail = NULL;
        }

	~CircularList(){
		free_memory();
	}

        void push_back(T data);
        void push_front(T data);
        void push_at_loc(int loc,T data);
        void remove_front();
        void remove_back();
        void remove_at_loc(int loc);
        void display_all();
	bool find(T key);
	void free_memory();
};

template<typename T> void CircularList<T> :: push_back(T data){
    Nodec<T> *node = new Nodec<T>(data);
    if(node == NULL){
        cout<<"Heap is full !!!"<<endl;
        return;
    }
    if(head == NULL){
        head = node;
        tail = node;
        node->link = node;
    }
    else{
        tail->link = node;
        node->link = head;
        tail = node;
    }
}

template<typename T> void CircularList<T> :: push_front(T data){
    if(head == NULL){
        push_back(data);
        return;
    }else {
        Nodec<T> *node = new Nodec<T>(data);
        tail->link = node;
        node->link = head;
        head = node;
    }
}

template<typename T> void CircularList<T> :: push_at_loc(int loc,T data){
    if(size_of_clist < loc)
        return;
    else if(head == NULL && loc == 0){
        push_back(data);
        return;
    }
    else if(head != NULL && loc == 0){
        push_front(data);
        return;
    }
    else if(size_of_clist == loc){
        push_back(data);
        return;
    }
    else{
        Nodec<T> *node = new Nodec<T>(data);
        Nodec<T> *temp = head;

        if(node == NULL){
            cout<<"Heap is full !!!"<<endl;
            return;
        }
        else{
            int count = 0;
            while(count < loc - 1){
                temp = temp->link;
                count++;
            }
            node->link = temp->link;
            temp->link = node;
        }
    }
}

template<typename T> void CircularList<T> :: remove_front(){
    if(head == NULL)
        return;

    Nodec<T> *temp = head;
    head = temp->link;
    tail->link = head;
    delete temp;
    temp = NULL;
    size_of_clist--;

    if(size_of_clist == 0){
        head = NULL;
        tail = NULL;
    }
} 

template<typename T> void CircularList<T> :: remove_back(){
    if(head == NULL)
        return;

    Nodec<T> *temp = head;
    while(temp->link != tail){
        temp = temp -> link;
    }
    Nodec<T> *lastNode = temp->link;
    temp->link = head;
    tail = temp;
    delete lastNode;
    lastNode = NULL;
    size_of_clist--;

    if(size_of_clist == 0){
        head = NULL;
        tail = NULL;
    }
}

template<typename T> void CircularList<T> :: remove_at_loc(int loc){
    if(loc >= size_of_clist)
        return;

    else if (head != NULL && loc == 0)
        remove_front();

    else if(size_of_clist == loc + 1)
        remove_back();

    else if(head == NULL){
        cout<<" No data for delete"<<endl;
        return;
    }else{
            Nodec<T> *temp = head;
            int count = 0;
            while(count < loc - 1){
                temp = temp->link;
                count++;
            }
            
            Nodec<T> *deleting_node = temp->link;
            temp->link = deleting_node->link;
            size_of_clist--;
            delete deleting_node;
            deleting_node = NULL;

            if(size_of_clist == 0){
                head = NULL;
                tail = NULL;
            }
        }
} 

template<typename T> void CircularList<T> :: display_all(){
    Nodec<T>  *temp_head = head;
    while(temp_head != tail){
        cout<<temp_head->node_data<<" ";
        temp_head = temp_head->link;
    }
    cout<<tail->node_data;
    cout<<endl;
}

template<typename T> bool CircularList<T> :: find(T key){
    Nodec<T> *temp = head;
    while(temp != tail){
        if(temp->node_data == key)
            return true;
        temp = temp->link;
    }
    if(tail->node_data == key)
	    return true;
    return false;
}

template<typename T> void CircularList<T> :: free_memory(){
        Nodec<T> *temp = head;
        while(temp != tail){
                Nodec<T> *free_block = temp;
                temp = temp->link;
                delete free_block;
                free_block = NULL;
        }
	delete tail;
	tail = NULL;
}

