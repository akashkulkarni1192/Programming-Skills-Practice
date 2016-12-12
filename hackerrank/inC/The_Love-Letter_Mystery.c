#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,i,j,k,c,l;
    char str[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        c=0;
        scanf("%s",str);
        l=strlen(str)-1;
        for(j=0;str[j] && j<l;j++,l--)
            c+=abs(str[j]-str[l]);
        printf("%d\n",c);
        
    }
    return 0;
}
