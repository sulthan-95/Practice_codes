#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node * insert(node *head,int data)
{
	node *newnode=new node;
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL)
		head=newnode;
	else
	{
		node *p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=newnode;
		//*head=p;
	}
	return head;
}
node * firsttlast(node *head)
{
	node *p=head;
	head=head->next;
	node *t=head;
	while(t->next!=NULL)
		t=t->next;
	p->next=NULL;
	t->next=p;
	//t->next->next=NULL;
	return head;
}
void display(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
}
int main(int args,char *argv[])
{
	node *head;
	head=insert(head,5);
	head=insert(head,6);
	head=insert(head,8);
	head=insert(head,10);
	display(head);
	head=firsttlast(head);
	cout<<"\n";
	display(head);
	return 0;
}		
