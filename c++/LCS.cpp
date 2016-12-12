/* DONE USING RECURSION */
/* ALSO DONE USING DYNAMIC PROGRAMMING */

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int max(int a,int b){
	return (a>b)?a:b;
}
int lcs(char str1[],char str2[],int m,int n){
	if(m==0 || n==0)
		return 0;
	if(str1[m-1]==str2[n-1])
		return 1+lcs(str1,str2,m-1,n-1);
	return max(lcs(str1,str2,m,n-1),lcs(str1,str2,m-1,n));
}
int main(){
	char string1[50],string2[50];
	cout<<"Enter String 1 :";
	gets(string1);
	cout<<"Enter String 2 :";
	gets(string2);
	cout<<"Longest common sequence : "<<lcs(string1,string2,strlen(string1),strlen(string2));
	return 0;
}