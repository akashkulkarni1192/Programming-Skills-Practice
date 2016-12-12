#include <iostream>
#include<string.h>
using namespace std;
char str[10001],ch;
long long int res,i,j,a,b,sum=0;
int main()
{
    cin>>a>>b;
    cin>>str;
    res=a;
//    if(strlen(str)==1 ){
//    	if(str[0]=='1'){
//  			cout<<"Sum : "<<sum<<" str[i]="<<str[0]<<endl;
//    		cout<<res;
//    		return 0;
//    	}
//    }
//    if(str[0]=='0'){
//    	sum=0;
//    }
    for(i=0;str[i];i++){
    	if(str[i]=='1'){
    		sum+=res;
    		cout<<res<<" added"<<endl;
    	}
    	if(i==0)
    		continue;	
    	res = res*res;
    	cout<<"Sum : "<<sum<<" str[i]="<<str[i]<<endl;
    }
    if(b!=0)
    	cout<<sum%b;

    return 0;
}
