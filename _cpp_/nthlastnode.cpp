#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
void insert(node **head,int data)
{
	node *temp,*t=*head;
	temp=new node;
	temp->data=data;
	temp->next=NULL;
	if(t==NULL)
	{
		*head=temp;
		return;
	}
	while(t->next!=NULL)
		t=t->next;
	t->next=temp;
}
void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}
void nthlast(node *head,int k,int n,int index)
{
	if(head==NULL)
		return;
	nthlast(head->next,k,n,index+1);
	if(index==k)
		cout<<head->data<<"\n";
}
int main()
{
	int data,n,k;
	node *head;
	cin>>n;
	for(int i=1;i<=n;i++)
		insert(&head,i);
	print(head);
	cin>>k;
	nthlast(head,k,n,1);
}		
