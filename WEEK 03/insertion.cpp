#include"singly_list.cpp"
#include"dynamic_array.cpp"
#include<iostream>

int main()
{
	long int n;
	//cout << "Enter Test Cases"<<endl;
	cin >> n;
	int it = 0;
	float prob = 0.1;

	// Arrays to store time duration
	// of sorting algorithms
	double tim1[10], tim2[10], tim3[10];

	printf("A_size, Dynamic_Array, Singly_List\n");

	// Performs 10 iterations
	while (it++ < 10) {
		long int a[n], b[n];
		DynamicArray<int> vec;
		SinglyList<int> list;
		// generating n random numbers
		// storing them in arrays a, b, c
		int i,j;
		int size = n;
		for (i = 0; i < size; i++) {
			long int no = rand() % n + 1;
			a[i] = no;
			b[i] = no;
		}
		
		for(j = 0;j < size;j++){
			vec.push_back(a[j]);	
			list.push_back(b[j]); 
		}
			
		
		size += prob * n;
		
		// using clock_t to store time
		clock_t start, end;

		// Dynamic Array
		start = clock();
		
		for(int i = j;i < size;i++)
			vec.push_back(a[i]);
		
		end = clock();
		tim1[it] = ((double)(end - start));

		// Singly List
		start = clock();
		
		for(int i = j;i < size;i++)
                        list.push_back(a[i]);
                        
		end = clock();
		tim2[it] = ((double)(end - start));

		// type conversion to long int
		// for plotting graph with integer values
		cout << prob*100 <<"%\t"<<(long int)tim1[it]<<"\t\t"<<(long int)tim2[it]<<endl;

		// increases the size of array by 10000
		prob += 0.1;
	}

	return 0;
}

