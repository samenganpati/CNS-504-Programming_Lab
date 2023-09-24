#include<iostream>
#include<cstdlib>
#include<queue>
#include<cmath>
#include"queue_list.cpp"
using namespace std;

void user_bfs(int mat[][1000],int node,long int t1[],int repeat){
	clock_t start,end;
	start = clock();
	int visited[node] = {0};
	QueueList<int> queue;
	int i = 0;
	visited[i] = 1;
	queue.enqueue(0);
	while(!queue.isEmpty()){
		int frontQueue = queue.front();
		queue.dequeue();
		for(int j = 0;j < node;j++){
			if(mat[frontQueue][j] == 1 && visited[j] == 0){
				visited[j] = 1;
				queue.enqueue(j);
			}
		}
	}
	end = clock();
	t1[repeat] += (double(end - start));
}

void inbuild_bfs(int mat[][1000],int node,long int t2[],int repeat){
	clock_t start,end;
	start = clock();
	int visited[node] = {0};
	queue<int> q;
	int i = 0;
	visited[i] = 1;
	q.push(i);
	while(!q.empty()){
		int frontQueue = q.front();
		q.pop();
		for(int j = 0;j < node;j++){
			if(mat[frontQueue][j] == 1 && visited[j] == 0){
				visited[j] = 1;
				q.push(j);
			}
		}
	}
	end = clock();
	t2[repeat] += (double(end - start));
}


int main(){
	int node = 100;
	int mat[1000][1000] = {0};
	long int t1[11] = {0},t2[11] = {0};
	int repeat = 0;
	cout << "# nodes" <<"\t\t"<<"user_bfs"<<"\t"<<"inbuild_bfs"<<endl;
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

			user_bfs(mat,node,t1,repeat);
			inbuild_bfs(mat,node,t2,repeat);
		}

		cout << node <<"\t\t"<<t1[repeat]/4<<"\t\t"<<t2[repeat]/4<<endl;
		repeat++;
		node += 100;
	}
	return 0;
}
