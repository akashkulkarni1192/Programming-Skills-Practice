#include <iostream>
using namespace std;
long int i,j,sum,curSum,s,t,n,x,arr[100001];
int main()
{
    cin>>t;
    bool flag;
    while(t--){
    	cin>>n>>x;
    	for(i=0;i<n;i++)
    		cin>>arr[i];
    	curSum=arr[0];
    	s=0;
        flag=false;
    	for(i=1;i<=n;i++){
    		while(curSum>x && s<i){
    			curSum-=arr[s++];
    		}
    		if(curSum==x){
    			cout<<"YES\n";
    			flag=true;
    			break;
    		}
    		if(i<n)
    			curSum+=arr[i];
    	}
    	if(!flag)
    		cout<<"NO\n";
    }
    return 0;
}
