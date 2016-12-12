#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *link;
}NODE;
NODE* getnode(){
	return (NODE *)malloc(sizeof(NODE));
}
void display(NODE *head){
	NODE *first=head->link;
	if(head->link==NULL){
		printf("\nEmpty");	
	}
	printf("\n%d",first->info);
	first=first->link;
	while(first!=NULL){
		printf(" -> %d",first->info);
		first=first->link;
	}
}
NODE* detectLoop(NODE *head){
	NODE *first=head->link,*second=head->link;
	if(head->link==NULL)
		return NULL;
	else if(head->link->link==NULL)
		return NULL;
	while(first!=NULL && second!=NULL){
		first=first->link;
		if(second->link==NULL)
			break;
		second=second->link->link;
		if(second==first){
			printf("\nLoop detected at %d",second->info);
			return first;
		}
	}
	return NULL;
}
void removeLoop(NODE *head){
	NODE *loopNode=detectLoop(head),*first=head->link,*second,*loopStart=NULL,*prev,*cur;
	int end=0;
	if(loopNode==NULL){
		printf("\nNo loop detected ");
		return;
	}
	while(first!=NULL){
		second=loopNode;
		while(second!=NULL && second->link!=loopNode){
			if(second==first){
				loopStart=first;
				end=1;
				break;
			}
			second=second->link;
		}
		if(end)
			break;
		first=first->link;
	}
	cur=loopStart;
	while(cur->link!=loopStart)
		cur=cur->link;
	cur->link=NULL;
	printf("\nLoop Removed ");
}
void insert(NODE *head){
	NODE *first=head->link,*nn=getnode();
	printf("\nEnter info :");
	scanf("%d",&nn->info);
	nn->link=NULL;
	if(head->link==NULL){
		head->link=nn;
		return;
	}
	while(first->link!=NULL)
		first=first->link;
	first->link=nn;
}
int main(){
	NODE *head=getnode(),*first;
	int i,n;
	head->link=NULL;
	printf("\nEnter no of nodes (above 5):");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		insert(head);
	first=head->link;
	while(first->link!=NULL)
		first=first->link;
	first->link=head->link->link;
	printf("\nLoop put (%d -> %d)",first->info,head->link->link->info);
	removeLoop(head);
	if(detectLoop(head)==NULL)
		display(head);
	else
		printf("\nLoop there\n");
	return 0;
}
