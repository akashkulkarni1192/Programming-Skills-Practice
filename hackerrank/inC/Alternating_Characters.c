#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char str[100000];
    char ch;
    int i,c,j,n,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",str);
        c=0;
        for(j=1;str[j];j++)
            if(str[j]==str[j-1])
                c++;
        printf("%d\n",c);
    }
    return 0;
}
