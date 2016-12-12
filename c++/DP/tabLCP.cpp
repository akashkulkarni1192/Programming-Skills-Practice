#include<iostream>
#include<string.h>
using namespace std;
int L[20][20];
int max(int a,int b){
	return (a>b)?a:b;
}
int lcs(char str1[],char str2[],int m,int n){
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				L[i][j] = 0;
			else if(str1[i-1]==str2[j-1])
				L[i][j] = 1 + L[i-1][j-1];
			else
				L[i][j] = max(L[i][j-1],L[i-1][j]);
		}
	}
	return L[m][n];
}
int main(){
	char string1[20],string2[20];
	int i,j;
	cin>>string1;
	cin>>string2;
	cout<<"Longest Common sequence : "<<lcs(string1,string2,strlen(string1),strlen(string2));
}