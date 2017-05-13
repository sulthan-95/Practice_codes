#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
signed int findnnode(struct node **head,int n)
{
	struct node *t=(*head);
	if(!t)
		return -9999;
	int i=1,len;
	for(len=0;t->next!=NULL;len++,t=t->next);
	if(n>len)
		return -9999;
	t=*head;
	for(i=1;i<(len-n);i++,t=t->next);
	return t->data;
}
void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

	/* put in the data  */
	new_node->data  = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref)    = new_node;
}

/* Drier program to test above function*/
int main(int argc,char *argv[])
{
	/* Start with the empty list */
	struct node* head = NULL;

	// create linked 35->15->4->20
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);

	printf("%d",findnnode(&head, 3));
	getchar();
	return 0; 
}
