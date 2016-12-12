#include<iostream>
using namespace std;
int main(){
	int fib[50]={0,1},i,j,n;
	cout<<"Enter number : ";
	cin>>n;
	for(i=2;i<n;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	cout<<"Fib["<<n<<"] : "<<fib[n-1]<<endl;
	return 0;
}