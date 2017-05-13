#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void rmduplic(struct node **head)
{
	struct node *t=*head;
	if(!t)
		return;
	while(t->next!=NULL)
	{
		if(t->data==t->next->data)
			t->next=t->next->next;
		else
			t=t->next;
	}
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
	*(head_ref)=new_node;
}
void printList(struct node *node)
{
	while(node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
} 

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;

	/* Let us create a sorted linked list to test the functions
	   Created linked list will be 11->11->11->13->13->20 */
	push(&head, 20);
	push(&head, 13);
	push(&head, 13);  
	push(&head, 11);
	push(&head, 11);
	push(&head, 11);                                    

	printf("\n Linked list before duplicate removal  ");
	printList(head); 

	/* Remove duplicates from linked list */
	rmduplic(&head); 

	printf("\n Linked list after duplicate removal ");         
	printList(head);            

	getchar();
}





