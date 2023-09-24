#include<iostream>
#include<cstdlib>
#include<stack>
#include<cmath>
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
	t1[repeat] += (double(end - start));
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
	int node = 100;
	int mat[1000][1000] = {0};
	long int t1[11] = {0},t2[11] = {0};
	int repeat = 0;
	cout << "# nodes"  <<"\t\t"<<"user_bfs"<<"\t"<<"inbuild_bfs"<<endl;
	while(node <= 1000){
		int countEdge = 0;
		int sp[4] ; 
		sp[0] = 2*node;sp[1] = ceil(node*log(node)); sp[2] = ceil(node/sqrt(node)); sp[3] = node*(node - 1)/2; 
		for(int m = 0; m < 3;m++) {
			while(true && m != 3){
				countEdge = 0;
					for(int i = 0;i < node;i++){
						for(int j = i+1;j < node;j++){
							int x = rand() % node;
							int y = rand() % node;
							if(mat[x][y] != 1 && mat[y][x] != 1)
								countEdge++;
							mat[x][y] = 1;
							mat[y][x] = 1;
							if(countEdge == sp[m]) break;
						}
						if(countEdge == sp[m])
							break;
					}
					if(countEdge == sp[m])
						break;
					else 
						continue;
			}
			
			countEdge = 0;
			if(m == 3){
				for(int i = 0;i < node;i++){
					for(int j = i + 1;j < node;j++){
						mat[i][j] = 1;
						countEdge ++;
					}
				}
			}

			user_dfs(mat,node,t1,repeat);
			inbuild_dfs(mat,node,t2,repeat);
		}

		cout << node <<"\t\t"<<t1[repeat]/4<<"\t\t"<<t2[repeat]/4<<endl;
		repeat++;
		node += 100;
	}
	return 0;
}
