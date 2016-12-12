#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int cmp (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
int hcf(int a,int b){
    int i,j,rem=1;
    while(rem){
        
        rem = b%a;
        b = a;
        if(rem)
            a=rem;
       // printf("\n a=%d b=%d rem=%d",a,b,rem);
    }
    return a;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t,n,arr[100000],i,j,flag,oddCount=0,one=0;
    //printf(" hcf = %d",hcf(5602,14660));
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        qsort(arr,n,sizeof(int),cmp);
        flag=0;
        one=0;
        if(arr[n-1]==1){
            //printf("YES\n");
            one=1;
        }
            
        for(i=0;i<n && flag==0 && one==0;i++){
            if(arr[i]==1){
               one=1;
            }
            for(j=i+1;j<n && flag==0 && one==0;j++){
               // printf("\nhcf of %d and %d is %d",arr[i],arr[j],hcf(arr[i],arr[j]));
                if(hcf(arr[i],arr[j])==1){
                   // printf("\nFlag set at arr[i]=%d and arr[j]=%d ",arr[i],arr[j]);
                    flag=1;
                }
            }
        }
        if(flag || one==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
