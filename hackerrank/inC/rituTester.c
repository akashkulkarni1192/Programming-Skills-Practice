#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void compute(char s[]){
    long i,j,count=0;
    for(i=0,j=1;s[i]!='\0' && s[j]!='\0';i++,j++){
        if(s[i]==s[j]){
            count++;
        }
    }
    printf("%ld\n",count);
}
int main() {
    int t,i;
    char str[10][100000];
    
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",str[i]);
    }
    
    for(i=0;i<t;i++){
        compute(str[i]);
    }
   
    return 0;
}