#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
int n;
int partition(int arr[],int low,int high){
    int temp[10000],left[10000],right[10000],i=low+1,j=high,p=arr[low],k=0,l=0;
    //printf("\npartitioning %d - %d",low,high);
    for(i=low+1;i<=high;i++){
        if(p>arr[i])
            left[k++]=arr[i];
        else
            right[l++]=arr[i];
    }
    for(i=0,j=low;i<k;i++,j++)
        arr[j]=left[i];
    arr[j++]=p;
    for(i=0;i<l;i++)
        arr[j++]=right[i];
    //printf("\n");
    // for(i=0;i<n;i++)
    //         printf("%d-",arr[i]);
    // printf("\nreturned %d", low+k);
    return low+k;
}
void quick(int arr[],int low,int high){
    int s,i;
    //printf("\nPhase %d - %d ",low,high);
    //sleep(1);
    if(low<high){
        s = partition(arr,low,high);
        quick(arr,low,s-1);
        quick(arr,s+1,high);
        printf("\n");
        for(i=low;i<=high;i++)
            printf("%d ",arr[i]);
    }
}
void quickSort(int ar_size, int *  ar) {
    n=ar_size;
    quick(ar,0,ar_size-1);

}
int main(void) {
   
   int _ar_size;
scanf("%d", &_ar_size);
int _ar[_ar_size], _ar_i;
for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   scanf("%d", &_ar[_ar_i]); 
}

quickSort(_ar_size, _ar);
   
   return 0;
}
