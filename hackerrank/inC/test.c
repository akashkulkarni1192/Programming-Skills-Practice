#include<stdio.h>
#include<string.h>
char answer[20];
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
char* add(char a[],char b[]){
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
	printf("\nResult under function = %s",strrev(c));  //upon removing this printf statement the Result variable in main() receives a blank string
	strcpy(answer,strrev(c));
	return strrev(c);
}
int main(){
	//char answer[20];
	printf("\nAnswer = %s\n",add("0","1"));
	strcpy(answer,add("0","1"));
	printf("\nNow Answer is %s \n",answer); // Here is the bug
	return 0;
}