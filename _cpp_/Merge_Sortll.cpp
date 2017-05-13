#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
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
void printList(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
}
void split(node *head,node **front,node **back)
{
	if(head==NULL||head->next==NULL)
	{
		*front=head;
		*back=NULL;
	}
	else
	{
		*front=head;
		node *slow=head,*fast=head->next;
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast!=NULL)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}
		*back=slow->next;
		slow->next=NULL;
	}
}
void reversek(node **head,int k)
{
	node *p=*head,*nex=NULL,*prev=NULL,*t=*head;
	int i=0;
	while(1)
	{
		nex=p->next;
		p->next=prev;
		prev=p;
		p=nex;
		i++;
		if(i%k==0)
		{
			t->next=p;
			t=p;
			//cout<<t->data;
			if(i<=k)					//This is done to make the head at starting point before we cross k
				*head=prev;	
		}
		if(p==NULL)
		{
			if(i<=k)
				*head=prev;
			break;		
		}	
	}
}	
node * Merge(node *a,node *b)
{
	node *result;
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	if(a->data<=b->data)
	{
		result=a;
		result->next=Merge(a->next,b);
	}
	else
	{
		result=b;
		result->next=Merge(a,b->next);
	}	
	return result;
}			
void MergeSort(node **head)
{
	node *t=*head,*front,*back;
	if(t==NULL||t->next==NULL)
		return;
	split(t,&front,&back);
	//Splitting the linked list into 2 halves
	MergeSort(&front);
	//Recursive Call for sorting 2 halves
	MergeSort(&back);
	*head=Merge(front,back);//Merging 2 halves
}
int main(int args,char *argv[])
{
	/* Start with the empty list */
	struct node* res = NULL;
	struct node* a = NULL;

	/* Let us create a unsorted linked lists to test the functions
	   Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5); 
	push(&a, 20);
	push(&a, 3);
	push(&a, 2); 

	/* Sort the above created Linked List */
	MergeSort(&a);

	cout<<"\n Sorted Linked List is: \n";
	printList(a);           
	reversek(&a,3);
	cout<<"\n";
	printList(a);
	return 0;
}	





