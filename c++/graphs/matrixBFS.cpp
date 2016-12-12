#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;
class Graph{
	public:
		int v;
		int edge[100][100];
		void showGraph(){
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					cout<<edge[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};
void bfs(Graph G,int src){
	list<int> queue;
	int v = G.v;
	bool *visited = new bool[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	int touched[v];
	touched[0]=src;
	visited[src]=true;
	queue.push_back(src);
	int pick;
	int i,j,k=1;
	while(queue.empty()==false){
		pick = queue.front();
		queue.pop_front();
		for(i=0;i<v;i++){
			if((i!=pick) && visited[i]==false){
				queue.push_back(i);
				visited[i]=true;
				touched[k++]=i;
			}
		}
	}
	cout<<"\nBFS traversal from Source :["<<src<<"] : ";
	for(i=0;i<k;i++)
		cout<<touched[i]<<" ";
}
int main(){
	int ch,v,e,i,j,s,d;
	Graph G;
	while(1){
			cout<<"\nMENU\n1.Create Graph\n2.Show Graph\n3.Exit\n4.BFS";
			cin>>ch;
			switch(ch){
				case 1:	cout<<"No of vertices ? ";
						cin>>G.v;
						cout<<"\nNo of edges ? ";
						cin>>e;
						for(i=0;i<e;i++){
							cout<<"\nEnter source destination : ";
							cin>>s>>d;
							G.edge[s][d]=G.edge[d][s]=1;
						}
						break;
				case 2:	G.showGraph();
						break;
				case 3: return 0;
				case 4: cout<<"\nEnter source";
						cin>>s;
						bfs(G,s);
						break;
				default: cout<<"Invalid choice, enter again";
			}
	}
}