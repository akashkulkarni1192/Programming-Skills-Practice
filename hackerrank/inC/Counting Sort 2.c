#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long f[101],ff[101];
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long i,j,arr[100001],n,op[100001];
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    for(i=1;i<=n;i++)
        f[arr[i]]++;
    ff[1]=f[1];
    for(i=2;i<101;i++){
        ff[i]=ff[i-1] + f[i];   
    }
    for(i=1;i<=n;i++)
        op[ff[arr[i]]--]=arr[i];
    for(i=1;i<=n;i++)
        printf("%lld ",op[i]);
    return 0;
}
