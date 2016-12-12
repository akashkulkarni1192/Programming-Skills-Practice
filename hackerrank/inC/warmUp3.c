#include<stdio.h>
#include<string.h>
char temp[20];
char* max(char a[],char b[]){
	int n1=strlen(a);
	int n2=strlen(b);
	int i,j;
	if(n1>n2)
		return a;
	else if(n1<n2)
		return b;
	else{
		for(i=0,j=0; i<n1 && j<n2;i++,j++){
			if(a[i]!=b[j])
				return (a[i]>b[i])?a:b;
		}
	}
	return NULL;
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void add(char a[],char b[]){
	int n1=strlen(a);
	int n2=strlen(b);
	char c[20],d[20];
	int i,j,k=0,carry=0,sum=0;
	for(i=n1-1,j=n2-1;i>=0 && j>=0;i--,j--){
		sum = (a[i]-'0')+(b[j]-'0')+carry;
		c[k++]=sum%10 + '0';
		carry=sum/10;
	}
	if(i>=0){
		for(;i>=0;i--){
			sum = (a[i]-'0')+carry;
			c[k++]=sum%10 + '0';
			carry=sum/10;
		}
	}
	else if(j>=0){
		for(;j>=0;j--){
			sum = (b[j]-'0')+carry;
			c[k++]=sum%10 +'0';
			carry=sum/10;
		}
	}
	if(carry){
		while(carry){
			c[k++]=carry%10 + '0';
			carry/=10;
		}
	}
	c[k]='\0';
	strcpy(temp,strrev(c));

}
int main(){
	char num[3000][20],n1[20],n2[20],sum;
	int i,j,n,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",num[i]);
	for(i=0;i<n;i++){
		if(strcmp(num[i],"0")==0 || strcmp(num[i],"0")==0){
			printf("IsFibo\n");
			continue;
		}
		strcpy(n1,"0");
		strcpy(n2,"1");
		flag=0;
		while(strcmp(max(n2,num[i]),num[i])==0){
			add(n1,n2);
			strcpy(n1,n2);
			strcpy(n2,temp);
			if(strcmp(num[i],temp)==0){
				printf("IsFibo\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("IsNotFibo\n");
	}
}