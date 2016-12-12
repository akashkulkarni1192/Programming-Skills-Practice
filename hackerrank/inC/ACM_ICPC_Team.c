#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int N,M,i,j,k=0,temp,max=0,prevMax=0,count=0,m,n;
    char list[500][500];
    char ch='0';
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++){
        k=0;
        scanf("%s",list[i]);
    }
    printf("\nList entered is :");
    for(i=0;i<N;i++){
        printf("\nitem %d :\n",i);
        for(j=0;j<M;j++)
            printf("%c",list[i][j]);
    }
    for(i=0;i<N;i++){
      for(j=i+1;j<N;j++){
            max=0;
            printf("\n At i=%d j=%d ",i,j);
            for(m=0;m<M;m++){
                printf("\nOrring %c and %c ",list[i][m],list[j][m]);
                if(list[i][m]!=list[j][m] || list[i][m]=='1')
                    max++;
            }
            
            if(max==prevMax)
                count++;
            else if(max>prevMax){
                prevMax=max;
                count=1;
            }
            printf("\nmax=%d prevMax=%d count=%d",max,prevMax,count);
        }
    }
    printf("%d\n%d\n",prevMax,count);
    return 0;
}
