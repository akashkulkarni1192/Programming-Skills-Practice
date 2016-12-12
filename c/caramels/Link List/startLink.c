#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
typedef struct node NODE;
NODE * getnode(){
	NODE *n;
	n=(NODE*)malloc(sizeof(NODE));
	return n;
}
void display(NODE *root){
	NODE *first=root;
	printf("\n%d ",first->info);
	while(first!=NULL){
		printf("-> %d",first->info);
		first=first->link;
	}
}
NODE* insert(NODE *root){
	int data;
	NODE *first,*nn=getnode();
	printf("\nEnter info :");
	scanf("%d",&data);
	nn->info=data;
	nn->link=NULL;
	if(root==NULL)
		return nn;
	first=root;
	while(first->link!=NULL)
		first=first->link;
	first->link=nn;
	return root;		
}
int main(){
	NODE *root=NULL;
	int ch=1,info;
	while(ch){
		root=insert(root);
		printf("\nEnter again(1 for yes) :");
		scanf("%d",&ch);
	}
	display(root);
	return 0;
}
		
