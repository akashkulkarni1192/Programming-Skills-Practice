#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
#define MAX_VAL 1000000001

int candies[MAX];

/** The code to read from STDIN and output to STDOUT has been provided by us, for convenience. You may or may not use this. **/
int compare(int *a,int *b){
    return (*a - *b);
}
int computeUnfairness(int n,int k){
    int i,min=0;
    qsort(candies,n,sizeof(int),compare);
    min=candies[k-1]-candies[0];
    for(i=1;i<=n-k;i++){
       // printf(" min = %d c[%d]-c[%d]=%d",min,i+k-1,i,candies[i+k-1]-candies[i]);
        if(min>candies[i+k-1]-candies[i])
            min=candies[i+k-1]-candies[i];
        
    }
    return min;
}
int main() {
    
    int N,K;
    int i;
    
    scanf("%d %d",&N,&K);
    for(i = 0;i < N;i++)
        scanf("%d",candies + i);
  
    int unfairness = computeUnfairness(N,K);// Compute the min unfairness over here, using N,K,candies
        
    printf("%d",unfairness);
    return 0;
}
