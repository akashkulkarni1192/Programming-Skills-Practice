1 2 3 4 5 6 7

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *link;
}NODE;
NODE* getnode(int data){
	NODE *n=(NODE*)malloc(sizeof(NODE));
	n->left=n->right=NULL;
	n->info=data;
	return n;
}
void insert(NODE *root,int data){
	NODE *first=root;
	if(root==NULL)
		return getnode(data);
	while(first->link!=NULL)
		first=first->link;
	first->link=getnode(data);
}
void display(NODE *root){
	NODE *first=root;
	if(root==NULL)
		return;
	printf("\n%d",root->info);
	first=first->link;
	while(first!=NULL){
		printf(" -> %d",first->info);	
		first=first->link;
	}
}
int main(){
	NODE *root=NULL;
	char ch;
	while((ch=getchar())!='\n')
		insert(root,ch-'0');
	display(root);
	return 0;
}
