#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t, n, c, m,r=0,a;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d%d%d",&n,&c,&m);
        int answer = 0; 
        answer = a = n/c;
        r=0;
        do{
            answer+=(a/m);
            r = a%m + a/m;
            a=r;
        }while(r>=m);
        printf("%d\n",answer);
    }
    return 0;
}