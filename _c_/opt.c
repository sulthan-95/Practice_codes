#include<stdio.h>
#include<stdlib.h>
int fr[5],lg[5];
void display()
{
	int i;
	for(i=0;i<3;i++)
	{
		printf("%d ",fr[i]);
	}
	printf("\n");
}
int main()
{
	int page[100],n,flag1=0,flag2=0,i,j,k,found=0,top=0,index=0,pf=0;
	printf("\nEnter the no. of pages..");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&page[i]);
	for(j=0;j<3;j++)
	{
		fr[j]=-1;
		lg[j]=0;
	}
	for(i=0;i<n;i++)
	{
		flag1=flag2=0;
		for(j=0;j<3;j++)
		{
			if(fr[j]==page[i])
			{
				flag1=1;
				flag2=1;
				break;
			}
		}
		if(flag1==0)
		{
			for(j=0;j<3;j++)
			{
				if(fr[j]==-1)
				{
					fr[j]=page[i];
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		{
			found=0;
			for(j=0;j<3;j++)
				lg[j]=0;
			for(j=0;j<3;j++)
			{
				for(k=i+1;k<n;k++)
				{
					if(fr[j]==page[k])
					{
						lg[j]=k-i;
						break;
					}
				}
				if(lg[j]==0)
				{
					index=j;
					found=1;
					break;
				}
			}
			if(found==0)
			{
				int max=0;
				index=0;
				for(j=0;j<3;j++)
				{
					if(max<lg[j])
					{
						max=lg[j];
						index=j;
					}
				}
			}
			fr[index]=page[i];
			top=(top+1)%3;
			pf++;
		}
		display();	
	}		
	return 0;
}
			

