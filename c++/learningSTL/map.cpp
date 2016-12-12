#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long int arr[100001];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long int n,n1,temp,max=0,maxElem;
    map<int,int> corpus;
    cin>>n;
    n1=n;
   // while(n1--){
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int left=0;left<n;left++)
            for(int right=left;right<n;right++){
                temp=0;
                for(int i=left;i<=right;i++){
                    temp^=arr[i];
                   // cout<<arr[i]<<" ";
                }
               // cout<<"\t\t temp="<<temp<<endl;
                 if(corpus.find(temp)!=corpus.end())
                    corpus[temp]++;
                else
                     corpus[temp]=1;
            }
       
   // }
  //  cout<<"Map :"<<endl;
    for(map<int,int>::iterator it = corpus.begin();it!=corpus.end();it++){
       // cout<<it->first<<" : "<<it->second<<endl;
        if(max<it->second){
            max=it->second;
            maxElem = it->first;
        }
    }
    cout<<maxElem<<" "<<max;
    return 0;
}
