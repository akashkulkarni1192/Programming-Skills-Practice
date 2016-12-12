#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n,count=0,count2=0;
int partition(int arr[],int low,int high){
    int i=0,j=0,p=arr[high];
    //printf("\nParttion %d - %d \n",low,high);
    while(j<high){
        for(;i<high && arr[i]<=p;i++);
        for(j=i+1;j<high && arr[j]>=p;j++);
        if(j<high){
            arr[i]=arr[i]+arr[j]-(arr[j]=arr[i]);
            count++;
        }
    }
    arr[i]=arr[i]+arr[high]-(arr[high]=arr[i]);
    count++;
    //printf("Count = %d\n");
    return i;
}
void quickSort(int arr[],int low,int high){
    int s;
    //printf("\nPhase %d - %d \n",low,high);
    if(low<=high){
        s= partition(arr,low,high);
        quickSort(arr,low,s-1);
        quickSort(arr,s+1,high);
    }
}
void insertionSort(int arr[],int n){
    int i,j,p,k;
    for(i=1;i<n;i++){
        p=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>p){
            arr[j+1]=arr[j];
            count2++;
            j--;
        }
        arr[j+1]=p;
        for(k=0;k<n;k++)
            printf("%d ",arr[k]);
        printf("\n");
        printf("Count2 = %d\n",count2);
    }
    
   
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int arr[10000],brr[10000],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        brr[i]=arr[i];
    }
    quickSort(arr,0,n-1);
    printf("\nCOunt = %d\n",count);
    insertionSort(brr,n);
    printf("%d",count2-count);
    return 0;
}
