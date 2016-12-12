#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long int n;
int partition(long int arr[],long int low,long int high){
    long int p=low,i=low+1,j=high;
    printf("\npartition %ld - %ld\n",low,high);
    while(i<j){
       // printf("\ni=%ld -  j=%ld",i,j );
        while(arr[p]>arr[i] && i<=high)
            i++;
        while(arr[p]<arr[j] && j>=0)
            j--;
        if(i<j)
            arr[i]=arr[i]+arr[j]-(arr[j]=arr[i]);
    }
    arr[p]=arr[p]+arr[j]-(arr[j]=arr[p]);
    return j;
}
void quickSort(long int arr[],long int low,long int high,long int check){
    int s=0,i;
    static int found=0;
    printf("\n%ld - %ld\n",low,high);
    if(low<=high){
        s = partition(arr,low,high);
      
      //  for(i=0;i<n;i++)
      //     printf("%ld ",arr[i]);
      //  printf("\ns = %d  check = %ld",s,check);
        if(s==check){
            found=1;
            //printf("%ld",arr[s]);
        }
        if(found==0){
            quickSort(arr,low,s-1,check);
            quickSort(arr,s+1,high,check);
        }
    }
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long int i,j=0,arr[1000001];
    scanf("%ld",&n);
    for(i=0,j=1;i<n;i++,j++)
        arr[i]=j;
        //scanf("%ld",&arr[i]);
    //if(n&1)
    //printf("\n--\n");
    printf("\n--\n");
        quickSort(arr,0,n-1,n/2);
        //quickSort(arr,0,n-1,arr[n/2+1]);
    //else
      //  quickSort(arr,0,n-1,n/2);
        //quickSort(arr,0,n-1,(arr[n/2+1]+arr[n/2])/2);
     printf("\n\nans = %ld",arr[n/2]);
    return 0;
}
