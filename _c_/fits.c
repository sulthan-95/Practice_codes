#include<stdio.h>
#include<stdbool.h>
#define size 100
void ALLOC(int *memory,int blocks,bool *alloc);
void BESTSORT(int *memory,int blocks);
void WORSTSORT(int *memory,int blocks);
void print(int *memory,int blocks);
int main(int args,char *argv[])
{
	int ch,i,memory[size],blocks;
	bool alloc[size];
	printf("Enter the no. of memory blocks..");
	scanf("%d",&blocks);
	printf("\nEnter the size of individual blocks...");
	for(i=0;i<blocks;i++)
	{
		scanf("%d",&memory[i]);
		alloc[i]=0;
	}
	printf("\n1.FIRST FIT \n2.BEST FIT \n3.WORST FIT");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			ALLOC(memory,blocks,alloc);
			print(memory,blocks);
			break;
		case 2:
			BESTSORT(memory,blocks);
			ALLOC(memory,blocks,alloc);
			print(memory,blocks);
			break;
		case 3:
			WORSTSORT(memory,blocks);
			ALLOC(memory,blocks,alloc);
			print(memory,blocks);
			break;
		default:
			printf("\nLOL:p");
	}
	return 0;
}
void ALLOC(int *memory,int blocks,bool *alloc)
{
	int process,a,i,j=0,flag=0;
	printf("\nEnter no. of files..");
	scanf("%d",&process);
	printf("\nEnter the size of individual file..");
	for(i=0;i<process;i++)
	{
		flag=0;
		printf("\nfile %d:",i+1);
		scanf("%d",&a);
		for(j=0;j<blocks;j++)
		{
			if((a<=memory[j])&&(alloc[j]==0))
			{
				memory[j]-=a;
				alloc[j]=1;
				flag=1;
			}
			if(flag==1)
				break;
		}
		if(flag!=1)
			printf("\nFile %d can't be allocated..",i+1);
		else
			printf("\nFile %d is allocated successfully..",i+1);		
	}	
}
void BESTSORT(int *memory,int blocks)
{
	int i,j;
	for(i=0;i<blocks-1;i++)
	{
		for(j=i+1;j<blocks;j++)
		{
			if(memory[i]>memory[j])
			{
				int temp=memory[i];
				memory[i]=memory[j];
				memory[j]=temp;
			}
		}
	}
}
void WORSTSORT(int *memory,int blocks)
{
	int i,j;
	for(i=0;i<blocks-1;i++)
	{
		for(j=i+1;j<blocks;j++)
		{
			if(memory[i]<memory[j])
			{
				int temp=memory[i];
				memory[i]=memory[j];
				memory[j]=temp;
			}
		}
	}
}
void print(int *memory,int blocks)
{
	int i=0;
	printf("\nMemory Blocks..");
	for(i=0;i<blocks;i++)
		printf("\n%d=%d",i+1,memory[i]);
}
