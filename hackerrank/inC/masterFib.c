#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int fib(long long int a)
{
    long long int sum = 1,prev_sum=1,new_sum=0;
    if(a==1)
        return 1;
    while(new_sum < a)
    {
        new_sum = prev_sum + sum;
        prev_sum = sum;
        sum = new_sum;
    }
    if(new_sum ==a)
        return 1;
    return 0;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long int i;
        scanf("%lld",&i);
        (fib(i)?puts("IsFibo"):puts("IsNotFibo"));
    
    }
    return 0;
}
