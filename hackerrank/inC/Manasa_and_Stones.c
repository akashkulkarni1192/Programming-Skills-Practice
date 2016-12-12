
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// int res[1000],k=0;
// void display(int n,int a,int b,int num,int stone){
//     printf("\n num = %d",num);
//     if(num==n){
//         if(k==0)
//             res[k++]=stone;
//         else if(res[k-1]<stone)
//             res[k++]=stone;
//         return;
//     }
//     display(n,a,b,num+1,stone+a);
//     display(n,a,b,num+1,stone+b);
// }
// int main() {

//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
//     int n,i,j,a,b,t;
//     scanf("%d",&t);
//     while(t--){
//         scanf("%d%d%d",&n,&a,&b);
//         display(n,a,b,1,0);
//         for(i=0;i<k;i++)
//             printf("%d ",res[i]);
//         printf("\n");
//         k=0;
//     }
//     return 0;
// }
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,a,b,t,base;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&a,&b);
        if(a>b)
            a=a+b-(b=a);
        n--;
        base=n*a;
        if(a!=b){
            while(n){
                printf("%d ",base);
                base+=b-a;
                n--;
            }
        }
        printf("%d \n",base);
    }
    return 0;
}
