#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t,ch,prev='*';
    cin>>t;
    ch=getchar();
    while(t--){
    	
    	while((ch=getchar())!='\n'){
	    		if(prev!=ch){
	    			prev=ch;
	    			putchar(ch);
	    		}
    	}
        if(t==0 && prev!=ch)
            putchar(ch);
    	putchar('\n');
    }

    return 0;
}
