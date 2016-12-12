#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,i,j,c,arr[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++){
        c=0;
        j=arr[i];
        while(j>0){
            if(j%10!=0)
                if((arr[i]%(j%10))==0)
                    c++;
            j=(int)j/10;
        }
        printf("%d\n",c);
    }
    return 0;
}