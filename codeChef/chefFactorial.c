#include<stdio.h>
int fact[100];	//to make sure it is intialized to zero
int main(){
	int n,i,j,sum,carry=0,length;
	scanf("%d",&n);
	fact[0]=1;
	length=1;
	for(i=2;i<=n;i++){
		sum=0;
		for(j=0;j<length;j++){
			sum=fact[j]*i+carry;
			fact[j]=sum%10;
			carry=sum/10;
		}
		while(carry>0){
			fact[length++]=carry%10;
			carry/=10;
		}
	}
	printf("\n");
	for(i=length-1;i>=0;i--)
		printf("%d",fact[i] );
	return 0;
}