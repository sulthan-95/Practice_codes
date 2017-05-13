#include<iostream>
#include<stdlib.h>
using namespace std;
struct DLL{
	int data;
	DLL *next;
	DLL *prev;
}typedef node;
void Insert(DLL **head,int data,int pos)
{
	if(!(*head))
		return;
	DLL *te=new DLL;
	te->data=data;
	te->next=NULL;
	te->prev=NULL;
	if(pos==1)
	{
		te->next=*head;
		(*head)->prev=te;
		te->prev=NULL;
		*head=te;
		return;
	}
	DLL *temp=*head;
	int k=1;
	while(k<(pos-1) && temp->next!=NULL)
	{
		k++;
		temp=temp->next;
	}
	te->next=temp->next;
	te->prev=temp;	
	if(temp->next!=NULL)
		temp->next->prev=te;
	temp->next=te;
}
void Delete(DLL **head,int pos)
{
	if(!(*head))
		return;
	DLL *temp=*head;
	if(pos==1)
	{
		(*head)=(*head)->next;
		delete temp;
		return;
	}
	int k=1;
	while(k<(pos-1) && temp->next!=NULL)
	{
		k++;
		temp->next;
	}
	if(temp->next==NULL){
		cout<<"\nCan't delete that node..\n";
		return;
	}
	DLL *temp2=temp->next;
	temp2->next->prev=temp;
	temp->next=temp2->next;
	temp2->prev=NULL;
	temp2->next=NULL;
	delete temp2;
}
