#include <iostream>
#include <stdio.h>
#include <algorithm>
#include<string.h>
using namespace std;
char str[20001];
int num[20001];
bool isX(char c){
    if(c=='X')
        return true;
    return false;
}
int main()
{
    int t,i,j,mx=0,sm=0,ans=0,k=0;
    char ch;
    cin>>t;
    while(t--){
    	cin>>str;
        k=count_if(str,str+strlen(str),isX);
        //getchar();
        for(i=0;i<k;i++)
            cin>>num[i];
    	// while((ch=getchar())!='\n'){
     //        if(ch==' ')
     //            continue;
    	// 	num[k++]=ch-'0';
    	// }
    	// cout<<"k="<<k<<endl;
    	// for(i=0;i<k;i++){
    	// 	cout<<num[i]<<" ";
    	// }
    	k--;
    	ans=0;
    	sm=0;
    	mx=0;
    	//cout<<ans<<"\t"<<sm<<"\t"<<mx<<endl;
    	for(i=strlen(str)-1;i>=0;i--){
    		if(str[i]=='X'){
                //cout<<"found X , k at "<<k<<endl;
    			sm+=num[k];
    			mx=(mx<(num[k]))?num[k]:mx;
    			//cout<<"X : "<<ans<<"\t"<<sm<<"\t"<<mx<<endl;
                k--;
    		}
    		else if(str[i]=='B'){
    			ans=(ans<mx)?mx:ans;
    			mx=sm=0;
    			//cout<<"B : "<<ans<<"\t"<<sm<<"\t"<<mx<<endl;
    		}
    		else{
    			ans+=sm;
    			mx=sm=0;
    			//cout<<"A : "<<ans<<"\t"<<sm<<"\t"<<mx<<endl;
    		}
    	}
    	cout<<ans<<endl;
    }
    return 0;
}
