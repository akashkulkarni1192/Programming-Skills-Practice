//  1 2 3 4 5 6
//  1 4 2 3
// 1 2 3 4 5 6
// 


#include<stdio.h>
// int cmpfunc (const void * a, const void * b)
// {
//    return ( *(int*)a - *(int*)b );
// }
//int list[10001];
int main(){
   int t,i,j,n,sum=0,max=1;
  scanf("%d",&t);
   while(t--){
     scanf("%d",&n);
     // sum=0;
     // for(i=1;i<n;i++)
     //  sum+=i;

    i=1;
    j=n;
    if(n==1){
      printf("1\n");
      continue;
    }
    sum=0;
    sum+=(j-i);
    //printf("\nsum=%d",sum);
    while(i<j){
     
      //printf("\nsum=%d",sum);
      i++;
      if(i<j)
         sum+=(j-i);
      j--;
      if(i<j)
         sum+=(j-i);
    }
    //if(n&1)
      //sum++;
    printf("%d\n",sum);
 }
 // printf("%d",max);
  return 0;
}