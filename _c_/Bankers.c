//Program for Banker's Algo
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define sz 30
/*void print(int **a,int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}*/
int main(int args,char *argv[])
{	
	int count=0,i,j,k,fin=0,tot=0,flag=0,allocation[sz][sz],maximum[sz][sz],need[sz][sz],available[sz],total[sz],n,m,cnt=0,pc[sz];
	bool finished[sz];
	printf("\nENter the no of processes and resources..");
	scanf("%d%d",&n,&m);
	printf("\nEnter the maximum of each resource by each process..");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			scanf("%d",&maximum[i][j]);
	}
	printf("\n Enter the allocated resource matrix..");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&allocation[i][j]);
			need[i][j]=maximum[i][j]-allocation[i][j];
		}
	}
	//print(allocation,n,m);
	printf("\nEnter the total instances of each resource..");
	for(i=0;i<m;i++)
		scanf("%d",&total[i]);
	for(i=0;i<m;i++)
	{
		tot=0;
		for(j=0;j<n;j++)
			tot+=allocation[j][i];
		available[i]=total[i]-tot;
	}
	for(i=0;i<m;i++)
		printf("%d\t",available[i]);
	while(1)
	{
		fin=0;
		flag=0;
		for(i=0;i<n;i++)
		{
			flag=0;
			for(j=0;j<m;j++)
			{
				if(need[i][j]>available[j]||finished[i]==true)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				for(k=0;k<m;k++)
					available[k]+=allocation[i][k];
				finished[i]=true;
				pc[cnt++]=i+1;
				fin=1;
				count++;
			}
		}
		printf("\n%d",count);
		if(fin==0)
		{
			printf("\nDeadLock detected..\n");
			break;
		}
		else
		{
			if(count==n)
			{
				printf("\nComplete..!!\n");
				break;
			}
		}
	}
	for(i=0;i<cnt;i++)
		printf("%d->",pc[i]);
	return 0;
}
						
