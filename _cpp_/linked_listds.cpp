#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cassert>
using namespace std;
struct linkedlist{
	int data;
	linkedlist *link;
}typedef node;
void insert_first(node **a,int i)
{
	node *temp;
	temp=new node;
	assert(temp!=NULL);
	temp->data=i;
	temp->link=*a;
	*a=temp;
    //delete temp;
}
void delet_first(node **a)
{
	node *t=*a;
	*a=(*a)->link;
	delete t;
}
node *reverse(node **head)
{
	node *p=*head,*next,*prev=NULL;
	while(p)
	{
		next=p->link;
		p->link=prev;
		prev=p;
		p=next;
	}
	*head=prev;
	return *head;
}
void insert_loc(node **a,int o,int loc)
{
	node *temp,*t;
	temp=new node;
	t=*a;
	for(int i=1;i<loc-1;i++)
	{
		t=t->link;
	}
	temp->data=o;
	temp->link=t->link;
	t->link=temp;
	//delete temp;
}
void insert_last(node **a,int num)
{
	node *temp,*t;
	temp=new node;
	t=*a;
	while(t->link!=NULL)
	{
		t=t->link;
	}
	//t=t->link;
	temp->data=num;
	temp->link=NULL;
	t->link=temp;
    //delete temp;
}
void delet(node **a,int d)
{
	node *t;
	t=*a;
	while(t->link!=NULL)
	{
		if(t->data==d)
		{
			t->link=t->link->link;
			return;
		}
		else if(t->link->data==d&&t->link->link==NULL)
		{
			node *s=t->link;
			t->link=NULL;
			delete s;
			return;
		}
		else
			t=t->link;
	}
}
void rotate(node **head,int k)
{
	node *t=*head,*prev=NULL;
	if(!t)
		return;
	for(int i=0;i<k;i++)
	{
		while(t->link!=NULL)
		{
			prev=t;
			t=t->link;
		}
		t->link=*head;
		prev->link=NULL;
		*head=t;
	}
}
void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->link;
	}
	cout<<endl;
}
void swap(node **head,int key1,int key2)
{
	node *currX=*head,*prevX=NULL,*prevY=NULL,*currY=*head;
	if(key1==key2)
		return;
	while(currX && currX->data!=key1)
	{
		prevX=currX;
		currX=currX->link;
	}
	while(currY && currY->data!=key1)
        {
                prevY=currY;
                currY=currY->link;
        }
	if(currX==NULL || currY==NULL)
		return;
	if(prevX!=NULL)
		prevX->link=currY;
	else
		*head=currY;
	if(prevY!=NULL)
		prevY->link=currX;
	else
		*head=currX;
	node *temp=currX->link;
	currX->link=currY->link;
	currY->link=temp;
}	
int length(node *head)
{
	if(head==NULL)
		return 0;
	else
		return 1 + length(head->link);
}
int main()
{
	node *head;
	head=new node;
	head->data=12;
	head->link=NULL;
	insert_first(&head,5);
	insert_loc(&head,25,2);
	insert_first(&head,54);
	insert_last(&head,3);
	printf("\nLinked List..\n");
	node *f=head;
	while(f)
	{
		printf("%d\t",(f->data));
		f=f->link;
	}
	node *p=reverse(&head);
	cout<<"\nReversed Linked List...\n";
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->link;
	}
	cout<<"\nLength :"<<length(head)<<endl;
	swap(&head,3,5);
	cout<<"\n............After Swapping.....\n";
	print(head);
	rotate(&head,2);
	cout<<"\n..........After Rotating.........\n";
	print(head);	
	return 0;
}
