#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cassert>
using namespace std;
struct linkedlist{
	int data;
	linkedlist *link;
}typedef snode;
int size=0;
void push(snode **s,int x)
{
	snode *temp;
	temp=new snode;
	if(*s==NULL)
	{
		*s=new snode;
		(*s)->data=x;
		(*s)->link=NULL;
		return;
	}
	temp->data=x;
	temp->link=*s;
	*s=temp;
	size++;
}
void pop(snode **s)
{
	snode *temp=*s;
	if(temp==NULL)
		return;
	*s=(*s)->link;
	delete temp;

}
void peep(snode **s,int loc)
{
	snode *temp=*s;
	if(loc>size||loc<=0)
		loc=size;
	for(int i=0;i<size-loc;i++)
		temp=temp->link;
	cout<<temp->data;
}
main()
{
	snode *top=NULL;
	push(&top,5);
	push(&top,7);
	push(&top,4);
	pop(&top);
	peep(&top,1);
}
