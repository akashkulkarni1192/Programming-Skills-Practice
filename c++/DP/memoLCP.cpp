#include<iostream>
#include<string.h>
using namespace std;
int L[20][20];
int lcs(char str1[],char str2[],int m,int n,char seq[]){
	if(m==0 || n==0)
		return 0;
	if(str1[m-1]==str2[n-1]){
		if(L[m-1][n-1]==-1)
			L[m-1][n-1]=lcs(str1,str2,m-1,n-1,seq);
		L[m][n]=1+L[m-1][n-1];
		return L[m][n];
	}
	if(L[m][n-1]==-1)
		L[m][n-1] = lcs(str1,str2,m,n-1,seq);
	if(L[m-1][n]==-1)
		L[m-1][n] = lcs(str1,str2,m-1,n,seq);
	L[m][n] = max(L[m][n-1],L[m-1][n]);
	return L[m][n];
}
int main(){
	char string1[50],string2[50],seq[20];
	cin>>string1;
	cin>>string2;
	for(int i=0;i<=strlen(string1);i++)
		for(int j=0;j<=strlen(string2);j++)
			L[i][j]=-1;
	cout<<"Longest common subsequence : "<<lcs(string1,string2,strlen(string1),strlen(string2),seq)<<endl;
}


