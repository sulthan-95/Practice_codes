#include<stdio.h>
#define size 10
struct linkedlist{
	int data;
	linkedlist *next;
};
void INSERT(struct linkedlist *l,int mem)
{
	l->data=mem;
	l->next=NULL;
}
int ALLOC(struct linkedlist *l,int req)
{
	if(req<=l->data)
	{
		if(
int main(int args,char *argv[])
{
	int a,blocks,i,j,mem,process,flag=0;
	struct linkedlist l[size];
	printf("\nEnter the no.of blocks...");
	scanf("%d",&blocks);
	printf("\nEnter the size of blocks..");
	for(i=0;i<blocks;i++)
	{
		scanf("%d",&mem);
		INSERT(&l[i],mem);
	}
	printf("\nEnter the no. of files..");
	scanf("%d",&process);
	printf("\nEnter the size of individual files..");
	for(i=0;i<n;i++)
	{
		printf("\nFile %d:",i+1);	
		scanf("%d",&a);
		for(j=0;j<blocks;j++)
		{
			if(ALLOC(&l[j],a))
				flag=1;
			if(flag==1)
				break;    //Here it is done seperately to avoid the break from overriding  the previous statements...//
		}
		if(flag==1)
			printf("\nFile allocated successfully..");
		else
			printf("\nFile can not be allocated..");
	}
