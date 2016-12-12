#include<stdio.h>

int main()
{
    int a[26],i,odd=0;
    char c;
    for (i=0;i<26;i++)
    a[i]=0;
    while ((c=getchar())!=EOF&&c!='\n')
    {
        a[c-'a']++;
    }
    for (i=0;i<26 odd<=1;i++){
        if(a[i]&1)
            odd++;
    // {
    //     if (a[i]%2!=0&&tp==1)
    //     tp=0;
    //     else if (a[i]%2!=0&&tp==0)
    //     {
    //         printf("NO");
    //         break;
    //     }
    }
    if (odd>1)
    printf("No");
    else
        printf("Yes");
    return 0;
}