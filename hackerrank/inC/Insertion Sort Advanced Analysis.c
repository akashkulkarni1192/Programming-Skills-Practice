#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n,arr[100000],i,j,t,count=0,p=arr[i];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(i=1;i<n;i++){
            
            for(j=i-1; j>=0;j--)
                if(arr[j]>arr[i])
                    count++;
        }
        printf("%d\n")
    }
    return 0;
}
