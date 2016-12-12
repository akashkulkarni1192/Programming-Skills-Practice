#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int seed=1,i,j,n,num;
    scanf("%d",&n);
    for(j=0;j<n;j++){
        seed=1;
        scanf("%d",&num);
        for(i=1;i<=num;i++){
            if(i&1)
                seed*=2;
            else
                seed++;
        }
        printf("%d\n",seed);
    }
    return 0;
}
