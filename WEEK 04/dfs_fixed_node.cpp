#include<iostream>
#include<cstdlib>
#include<stack>
#include"stack_list.cpp"
using namespace std;

void user_dfs(int mat[][1000],int node,long int t1[],int repeat){
	clock_t start,end;
	start = clock();
	int visited[node] = {0};
	StackList<int> s;
	int source = 0;
	s.push(source);
	while(!s.isEmpty()){
		source = s.top();
		s.pop();
		if(!visited[source])
			visited[source] = 1;
		for(int j = 0;j < node;j++){
			if(mat[source][j] == 1 && visited[j] == 0){
				visited[j] = 1;
				s.push(j);
			}
		}
	}
	end = clock();
	t1[repeat] = (double(end - start));
}


void inbuild_dfs(int mat[][1000],int node,long int t2[],int repeat){
	clock_t start,end;
	start = clock();
	int visited[node] = {0};
	stack<int> s;
	int source = 0;
	s.push(source);
	while(!s.empty()){
	        source = s.top();
		s.pop();
		if(!visited[source])
			visited[source] = 1;

		for(int j = 0;j < node;j++){
			if(mat[source][j] == 1 && visited[j] == 0){
				visited[j] = 1;
				s.push(j);
			}
		}
	}
	end = clock();
	t2[repeat] = (double(end - start));
}


int main(){
	int node = 0;
	int mat[1000][1000] = {0};
	long int t1[11] = {0},t2[11] = {0};
	int repeat = 0;
	cout << "# nodes" <<"\t\t"<<"# edges" <<"\t\t"<<"user_bfs"<<"\t"<<"inbuild_bfs"<<endl;
	while(node <= 1000){
		int countEdge = 0;
		while(true && node != 0){
				countEdge = 0;
				for(int i = 0;i < node;i++){
					for(int j = i+1;j < node;j++){
						int isEdge = rand() % 2;
						if(isEdge)
							countEdge++;
						mat[i][j] = isEdge;
						mat[j][i] = isEdge;
					}
				}
				
				if((countEdge < 2*node) || (node*(node-1)/2 < countEdge))
					continue;			
				if((countEdge >= 2*node) && (node*(node-1)/2 >= countEdge))	
					break;
			}


		if(node != 0){
			user_dfs(mat,node,t1,repeat);
			inbuild_dfs(mat,node,t2,repeat);
		}
		cout << node <<"\t\t" << countEdge <<"\t\t"<<t1[repeat]<<"\t\t"<<t2[repeat]<<endl;
		repeat++;
		node += 100;
	}
	return 0;
}
