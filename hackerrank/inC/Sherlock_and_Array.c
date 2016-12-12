#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int i,j,arr[10000],n,t,lsum,rsum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<n;i++){
            lsum=rsum=0;
            for(j=0;j<i;j++)
                lsum+=arr[j];
            for(j=i+1;j<n;j++)
                rsum+=arr[j];
            if(rsum==lsum){
                printf("YES\n");
                break;
            }
        }
        if(lsum!=rsum)
            printf("NO\n");
    }
    return 0;
    // int L[1000],R[1000];
    // scanf("%d",&t);
    // while(t--){
    //     scanf("%d",&n);
    //     for(i=0;i<n;i++)
    //         scanf("%d",&arr[i]);
    //     L[0]=0;
    //     R[n-1]=0;
    //     for(i=1;i<n;i++)
    //         L[i]=L[i-1]+arr[i-1];
    //     for(i=n-2;i>=0;i--)
    //         R[i]=R[i+1]+arr[i+1];
    //     for(i=0;i<n && L[i]!=R[i];i++);
    //     if(i<n)
    //         printf("YES\n");
    //     else
    //         printf("NO\n");
    // }
}



