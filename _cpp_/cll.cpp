#include<bits/stdc++.h>
using namespace std;
struct cll{
	int data;
	cll *next;
}typedef node;
void insert(node **head,int data)
{
	node *t=*head;
	node *fresh=new node;
	fresh->data=data;
	fresh->next=(*head);
	if((*head)!=NULL)
	{
		while(t->next!=(*head))
			t=t->next;
		t->next=fresh;
	}
	else
	{
		fresh->next=fresh;
		*head=fresh;
	}
}
void print(node *head)
{
	node *t=head;
	if(!t)
		return;
	while(t->next!=head)
	{
		cout<<t->data<<"->";
		t=t->next;
	}
	cout<<t->data<<endl;
}
void split_half(node *head,node **head1,node **head2)
{
	node *fast=head,*slow=head;
	if(head==NULL)
		return;
	while(fast->next!=head && fast->next->next!=head)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	if(fast->next->next==head)		//Even no. of nodes....//
		fast=fast->next;
	*head1=head;
	if(head->next!=head)		//if not there is only one node
		*head2=slow->next;
	fast->next=slow->next;		//Bring rotation to the splitted linked list
	slow->next=head;
}
void sort_insert(node **head,int data)
{
	node *fresh=new node,*temp=*head;
	fresh->data=data;
	fresh->next=(*head);
	if((*head)==NULL)
	{
		fresh->next=fresh;
		*head=fresh;	
	}
	else
	{
		while(temp->next!=(*head) && temp->next->data<data)
			temp=temp->next;
		fresh->next=temp->next;
		temp->next=fresh;
		if(temp->next==(*head))
			*head=fresh;
	}
}	
int main(int args,char *argv[])
{
	node *head,*head1,*head2;
	insert(&head,5);
	insert(&head,6);
	insert(&head,1);
	insert(&head,3);
	print(head);
	//split_half(head,&head1,&head2);
	//print(head1);
	//print(head2);
	sort_insert(&head1,95);
	sort_insert(&head1,2);
	sort_insert(&head1,60);
	print(head1);
	return 0;
}
