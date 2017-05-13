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
node * interchange(node *head)
{
	node *p=head,*prev=NULL;
	//while(p!=NULL && p->next!=NULL)
	//{
		node *t=p;
		cout<<"\nt->data  "<<p->data;
		p=p->next;
		cout<<"\np->data  "<<p->data;
		t->next=p->next;
		cout<<"\nt->next->data    "<<t->next->data;
		p->next=t;
		cout<<"\np->next->data   "<<p->next->data<<"\n";
		//t=p;
		//p=p->next;
		head=p;
		cout<<"\n head  "<<head->data<<"\n";
	//}
	return head;
}
void display(node *head)
{
	
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"\n";
}
int main(int args,char *argv[])
{
	node *head;
	head=insert(head,5);
	head=insert(head,6);
	head=insert(head,8);
	head=insert(head,10);
	head=insert(head,11);
	display(head);
	//head=firsttlast(head);
	node **p=&head;
	while((*p)!=NULL && (*p)->next!=NULL)
	{
		(*p)=interchange(*p);
		(*p)=(*p)->next->next;
	}
	display(head);
	return 0;
}		
