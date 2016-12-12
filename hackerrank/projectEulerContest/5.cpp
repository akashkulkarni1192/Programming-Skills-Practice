#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t,n,i,j,k,m;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=1;;i++){
            m=n*i;
            //cout<<"m="<<m<<endl;
            for(j=n-1;j>0 && (m%j)==0;j--);
            if(j==0){
                cout<<m<<endl;
                break;
            }
        }
    }
    return 0;
}