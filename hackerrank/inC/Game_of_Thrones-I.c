/* Attempt 1 */


/*#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void swap(char *a,char *b){
    *a= *a + *b - (*b = *a);
}
int permPalindrome(char arr[],int n,int i){
    int k,j,tag;
    if(i==n-1){
        printf("\nChecking %s ",arr);
        for(k=0,j=strlen(arr)-1;arr[k]==arr[j] && k<j;k++,j--);
        if(k>=j){
            printf("\n %s is palindrome",arr);
            return 1;
        }
        else 
            return 0;
    }
        for(j=i;j<n && tag==0;j++){
            swap(&arr[j],&arr[i]);
            tag=permPalindrome(arr,n,i+1);
            swap(&arr[j],&arr[i]);
        }
        printf("\ntag = %d at i=%d",tag,i);
    return tag;
}
void findPalind(char *arr)
{
     
    int flag = 0;
    // Find the required answer here. Print Yes or No at the end of this function depending on your inspection of the string
    flag=permPalindrome(arr,strlen(arr),0);
    if (flag==1)
        printf("YES\n");
    else
        printf("NO\n");
    
    return;
}
int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}
*/

/* Attempt 2 , a better one */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void swap(char *a,char *b){
    *a= *a + *b - (*b = *a);
}
int permPalindrome(char arr[],int n){
    int* freq = (int*)calloc(sizeof(int),26);
    int i,odds=0;
    for(i=0;i<n;i++){
        freq[arr[i]-'a']++;
    }
    for(i=0;i<n && odds<=1;i++)
        if(freq[i]&1)
            odds++;
    free(freq);
    if(odds>1)
        return 0;
    return 1;

}
void findPalind(char *arr)
{
     
    int flag = 0;
    // Find the required answer here. Print Yes or No at the end of this function depending on your inspection of the string
    flag=permPalindrome(arr,strlen(arr));
    if (flag==1)
        printf("YES\n");
    else
        printf("NO\n");
    
    return;
}
int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}
