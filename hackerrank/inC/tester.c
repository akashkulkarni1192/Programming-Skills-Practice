#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() { 
    char *str = (char*)malloc(3000*sizeof(char)),ch;
    int i,c,j,n,k=0;
    scanf("%[^\n]d",&n);
    for(i=0;i<3;i++){
        k=0;
        while((ch=getchar())!='\n')
            str[k++]=ch;
        //scanf("%s",str);
        str[k]='\0';
        printf("\nstring entered is %s\n",str);
    }
    return 0;
}