#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char str[101];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    static long int t,i,j,k=0,len,flag=1;;
    cin>>t;
    while(t--){
    	k=0;
        cin>>str;
        //cout<<str;
        len=strlen(str);
        flag=1;
        for(i=len-1;i>=0 && flag;i--){
            for(j=i-1;j>=0 && flag;j--){
                //cout<<"str[i] = "<<str[i]<<" str[j] = "<<str[j]<<endl;
                //cout<<"str[i] = "<<i<<" str[j] = "<<j<<" str[k] = "<<k<<endl;
                
                if(str[i]==str[j])
                {
                    
                  //  cout<<"breaked";
                    break;
                }
                if(str[i]>str[j]){
           		//	   cout<<"Entered at i ="<<str[i]<<endl;
                    	for(k=len-1;k>j-1 ;k--){
            	    //      cout<<"str[k] = "<<str[k]<<" str[k-1] = "<<str[k-1]<<endl;

                        if(str[k]>str[k-1]){
                            str[k] = str[k] + str[k-1] - (str[k-1]=str[k]);
                      //     cout<<str<<endl;
                   		//     cout<<" k= "<<str[k]<<endl; 
                            break;
                        }
                    }
                    //cout<<" printing    	k = "<<k<<" j "<<j<<endl;
                    if(k==j+1 && k!=i)
                        str[i]=str[i]+str[j]-(str[j]=str[i]);
                    flag=0;
                }
            }
        }
        //cout<<"i = "<<str[i+1]<<" j= "<<str[j+1]<<" k= "<<str[k]<<endl; 
        //cout<<str<<endl;

        if(k==j+2){
        //	  cout<<"swapped from ("<<str[j+2]<<endl;
            sort(str+j+2,str+len);
        }
         else {
          //  cout<<"swapped from ("<<str[k]<<endl;
            sort(str+k,str+len);

         }
            
       
         //cout<<"Plz piriut"<<endl;  
        if(i==-1 && j==-1)
            cout<<"no answer"<<endl;
        else
            cout<<str<<endl;

        //str[0]='\0';
    }
    return 0;
}
