/*
	0 1 2 3 4 5 6

  	0 1 0
  	0 1 1 0
	0 1 2 1 0
	0 1 3 3 1 0
	0 1 4 6 4 1 0
*/
#include<iostream>
using namespace std;
int main(){
	static int table[10][10]={0,1,0},i,j,n,r;
	cin>>n>>r;
	for(i=1;i<n;i++){
		for(j=1;j<=n;j++){
			table[i][j] = table [i-1][j-1] + table[i-1][j];
		}
	}
	for(j=1;j<=n;j++)
		cout<<table[n-1][j]<<"\t";
	cout<<endl;
	return 0;
}