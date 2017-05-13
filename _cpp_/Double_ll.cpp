#include<iostream>
#include<stdlib.h>
using namespace std;
struct dl{
	int data;
	dl *next;
	dl *prev;
}typedef dnode;
int cap=0;
void inser(dnode **q,int num,int loc)
{
	dnode *r,*s=*q;
	if(*q==NULL)
	{
		*q=new dnode;
		(*q)->data=num;
		(*q)->prev=NULL;
		(*q)->next=NULL;
	}
	else if(loc-1&&loc<cap)
	{
		int i=2;
		while(i<loc)
		{
			s=s->next;
			i++;
		}
		r=new dnode;
		r->data=num;
		r->next=s->next;
		r->prev=s;
		s->next->prev=r;
		s->next=r;
	}
	else if(loc>cap||loc==cap||loc<=0)
	{
		for(int i=1,loc=cap;i<loc;i++)
		{
			s=s->next;
		}
		r=new dnode;
		r->data=num;
		r->next=NULL;
		r->prev=s;
		s->next=r;
	}
	else
	{
		r=new dnode;
		r->data=num;
		r->prev=*q;
		(*q)->prev=r;
		*q=r;
	}
	cap++;
}
void delet(dnode **a,int loc)
{
	dnode *r,*s=*a;
	if(loc==1)
	{
		r=*a;
		(*a)->next->prev=NULL;
		(*a)=(*a)->next;
		delete r;
	}
	else if(loc<cap)
	{
		for(int i=1;i<loc;i++)
			s=s->next;
		r=s;
		s->next->prev=s->prev;
		s->prev->next=s->next;
		delete r;
	}
	else
	{
		loc=cap;
		for(int i=1;i<loc;i++)
		{
			s=s->next;
		}
		r=s;
		s->prev->next=NULL;
		delete r;
	}
}
int main()
{
	dnode *head=NULL;
	inser(&head,5,1);
	inser(&head,2,2);
	inser(&head,89,1);
	delet(&head,1);
	cout<<head->data;
	return 0;
}
