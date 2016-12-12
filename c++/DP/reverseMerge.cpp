#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char str[100001],rev[100001],perm[100001],ans[100001];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,j,k=0;
    cin>>str;
    strcpy(rev,str);
    reverse(rev,rev+strlen(rev));
    strcpy(perm,str);
    sort(perm,perm+strlen(perm));
    for(i=0,j=0;i<strlen(str) && j<strlen(str);){
        if(rev[i]<=perm[j]){
            ans[k++]=rev[i++];
        }
        else{
            ans[k++]=perm[j++];
        }
    }
    if(i<strlen(str)){
        for(;i<strlen(str);i++)
            ans[k++]=rev[i++];
    }
    else if(j<strlen(str)){
        for(;j<strlen(str);j++)
            ans[k++]=perm[j++];
    }
    ans[k]='\0';
    cout<<ans;
    return 0;
}
