#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n;
int partition(int arr[],int low,int high){
    int i=0,j=0,p=arr[high];
    while(j<high){
        for(;i<high && arr[i]<=p;i++);
        for(j=i+1;j<high && arr[j]>=p;j++);
        if(j<high)
            arr[i]=arr[i]+arr[j]-(arr[j]=arr[i]);
    }
    arr[i]=arr[i]+arr[high]-(arr[high]=arr[i]);
    for(j=0;j<n;j++)
        printf("%d ",arr[j]);
    printf("\n");
    return i;
}
void quickSort(int arr[],int low,int high){
    int s;
    //printf("\nPhase %d to %d\n", low,high);
    //sleep(1);
    if(low<high){
        s= partition(arr,low,high);
        quickSort(arr,low,s-1);
        quickSort(arr,s+1,high);
    }
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int arr[10000],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quickSort(arr,0,n-1);
    return 0;
}
