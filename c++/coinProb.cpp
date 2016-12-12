#include<iostream>
using namespace std;
int main(){
	int sum, i, j, val[] = {1,2,5,10}, minCoins[100];
	cout<<"Enter sum : ";
	cin>>sum;
	for(i=0;i<=sum;i++)
		minCoins[i]=999;
	minCoins[0]=0;
	for(i=1;i<=sum;i++){
		for(j=0;j<4;j++){
			if((val[j]<=i) && (minCoins[i-val[j]]+1)<minCoins[i]){
				minCoins[i]=minCoins[i-val[j]]+1;
				cout<<"minCoins["<<i<<"] : "<<minCoins[i]<<endl;
			}
		}
	}
	cout<<"Results : "<<endl<<"SUM\tCoins"<<endl;
	for(i=0;i<=sum;i++)
		cout<<i<<"\t"<<minCoins[i]<<endl;
	return 0;
}