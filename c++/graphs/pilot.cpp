#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;
class graph{
	int v;
	list<int> *adjList;
	public:
		void initGraph(int vertices){
			v = vertices;
			adjList = new list<int>[vertices];
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
int main(){
	int ch,v,e,i,j,s,d;
	graph G;
	while(1){
			cout<<"MENU\n1.Create Graph\n2.Show Graph\n3.Exit";
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
				default: cout<<"Invalid choice, enter again";
			}
	}

}