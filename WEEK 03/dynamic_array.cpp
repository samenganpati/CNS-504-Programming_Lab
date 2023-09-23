#include<iostream>
using namespace std;

template<typename T>
class DynamicArray{
	private:
        	int size;
            int capacity;

    public:
            T *arr;
        	DynamicArray(){
               this->size = 0;
               this->capacity = 0; 
            }

            DynamicArray(int num){
                this->size = 0;
                this->capacity = num;
                arr = new T[num];
            }

            ~DynamicArray(){
                 free_memory();
            }

        int len();
        void push_back(T ele);
        void display();
        void display_all();
        void insert_at_loc(int loc,T ele);
        void delete_at_loc(int loc);
        bool find(T key);
        void free_memory();
        int capacities(){
            return this->capacity;
        }
};

template<typename T> int DynamicArray<T> :: len(){
    return this->size;
}

template<typename T> void DynamicArray<T> ::  push_back(T ele){
    if(this->size == 0 && this-> capacity == 0){
            this->size = 1;
            this->capacity = 1;
            this->arr = new T[1];
            arr[0] = ele;
    } else {
        if (this->size == this->capacity && this->size != 0){
            this->capacity = this->size * 2;
            T *copyArray = new T[this->size];
            for(int i = 0;i < this->size;i++)
                copyArray[i] = arr[i];
            delete[] this->arr;
            this->arr = new T[capacity];
            for(int j = 0;j < this->size;j++)
                this->arr[j] = copyArray[j];
            this->arr[this->size] = ele;
            this->size++;
        }else{
                this->arr[this->size] = ele;
                this->size++;
            }
        }
    }

template<typename T> void DynamicArray<T> :: display(){
        for(int i=0;i<this->size;i++)
            cout<<this->arr[i]<<" ";
        cout<<endl;
    }

template<typename T> void DynamicArray<T> :: display_all(){
        for(int i=0;i<this->capacity;i++)
            cout<<this->arr[i]<<" ";
        cout<<endl;
    }

template<typename T> void DynamicArray<T> :: insert_at_loc(int loc,T ele){
            if (this->size == this->capacity && this->size != 0){
                this->capacity = this->size * 2;
                T *copyArray = new T[this->size];
                for(int i = 0;i < this->size;i++)
                    copyArray[i] = arr[i];
                delete[] this->arr;
                this->arr = new T[capacity];
                for(int j = 0;j < this->size;j++)
                    this->arr[j] = copyArray[j];
                for(int i = this->capacity - 1;i > loc;i--)
                    this->arr[i] = this->arr[i - 1];
                this->arr[loc] = ele;
                this->size++;

        }else{
                for(int i = this->capacity - 1;i > loc;i--)
                    this->arr[i] = this->arr[i - 1];
                this->arr[loc] = ele;
                this->size++;
            }
        }

template<typename T> void DynamicArray<T> :: delete_at_loc(int loc){
        if(loc > (this->size - 1))
            return ;
        if(this->size == 0)
            return ;

        if(2 * (this->size - 1) == this->capacity){
            for(int i = loc; i < (this->size - 1);i++)
                this->arr[i] = this->arr[i+1];
            this->size--;

            T *temp = new T[this->size];
            for(int i = 0;i < this->size;i++)
                temp[i] = this->arr[i];
            delete[] this->arr;
            this->arr = new T[this->size];
            for(int i = 0;i < this->size;i++)
                this->arr[i] = temp[i];
            delete[] temp;
            this->capacity = this->size;
        }else{
            for(int i = loc; i < (this->size - 1);i++)
                this->arr[i] = this->arr[i+1];
            this->size--;
        }
 }

template<typename T> bool DynamicArray<T> :: find(T key){
    for(int i=0;i<size;i++){
        if(arr[i] == key)
            return true;
    }
    return false;
}

template<typename T> void DynamicArray<T> :: free_memory(){
        delete [] this->arr;
        this->arr = NULL;
}
