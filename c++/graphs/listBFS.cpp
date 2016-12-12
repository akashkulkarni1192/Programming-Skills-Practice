#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;
class graph{
	public:
		int v;
		list<int> *adjList;
	
		void initGraph(int vertices){
			v = vertices;
			adjList = new list<int>[vertices];
		}
		int getVertices(){
			return v;
		}
		void addEdge(int src,int dest);
		void showGraph();
};
void graph::addEdge(int s,int d){
	adjList[s].push_back(d);
	adjList[d].push_back(s);
}
void graph::showGraph(){
	for(int i=0;i<v;i++){
		cout<<"\nNode ["<<i<<"] : ";
		for(list<int>::iterator it=adjList[i].begin();it!=adjList[i].end();it++){
			cout<<*it<<" ";
		}
	}
}
void bfs(graph G,int src){
	list<int> queue;
	int v = G.getVertices();
	bool *visited = new bool[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	int touched[v];
	touched[0]=src;
	visited[src]=true;
	queue.push_back(src); // change this push_front()
	int pick;
	int i,j,k=1;
	while(queue.empty()==false){
		pick = queue.front();
		queue.pop_front();
		for(list<int>::iterator it=G.adjList[pick].begin();it!=G.adjList[pick].end();it++){
			if(visited[*it]==false){
				queue.push_back(*it);
				visited[*it]=true;
				touched[k++]=*it;
				//add a break here so that inner for loop breaks as soon it receives one not visited vertex
			}
		}
	}
	cout<<"\nBFS traversal from Source :["<<src<<"] : ";
	for(i=0;i<k;i++)
		cout<<touched[i]<<" ";
	
}
int main(){
	int ch,v,e,i,j,s,d;
	graph G;
	while(1){
			cout<<"\nMENU\n1.Create Graph\n2.Show Graph\n3.Exit\n4.BFS";
			cin>>ch;
			switch(ch){
				case 1:	cout<<"No of vertices ? ";
						cin>>v;
						G.initGraph(v);
						cout<<"\nNo of edges ? ";
						cin>>e;
						for(i=0;i<e;i++){
							cout<<"\nEnter source destination : ";
							cin>>s>>d;
							G.addEdge(s,d);
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