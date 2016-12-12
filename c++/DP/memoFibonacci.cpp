#include<iostream>
#include<stdio.h>
using namespace std;
int fib[50];
int fibonacci(int n){
	int i;
	if(n<=1)
		return n;
	if(fib[n]!=-1)
		return fib[n];
	fib[n] = fibonacci(n-1)+fibonacci(n-2);
	return fib[n];
}
int main(){
	int i,j,n,sum;
	cout<<"Enter number";
	cin>>n;
	for(i=0;i<n;i++)
		fib[i]=-1;
	cout<<"Fib("<<n<<") : "<<fibonacci(n-1)<<endl;
	return 0;
}