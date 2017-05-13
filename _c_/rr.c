#include<stdio.h>
#include<stdlib.h>
int n;
struct process{
	int bt;
	int wt;
	int at;
	int rt;
	int pid;
	int tat;
	int flag;
	int st;
}p[10];
void accept()
{
	int i;
	printf("\nEnter the no. of processes..");
	scanf("%d",&n);
	printf("\nENter the arrival time,burst time");
	for(i=0;i<n;i++)
	{
		printf("\nProcess [%d]",i+1);
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].rt=p[i].bt;
		p[i].pid=i;
		p[i].flag=0;
	}
}
void sort()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				process temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
void roundrobin()
{
	int allterm=0,temp=0,cnt=0,pcnt=0,tq;
	float gt[10],ps[10],avgwt=0,avgtat=0;
	printf("\nEnter the time quantum...");
	scanf("%d",&tq);
	gt[0]=p[0].at;
	while(allterm<n)
	{
		for(i=0;i<n;i++)
		{
			if(p[i].flag==0)
			{
				p[i].st=temp;
				cnt++;
				if(p[i].rt>tq)
				{
					p[i].rt-=tq;
					temp+=tq;
					gt[cnt]=temp;
					ps[pcnt]=p[i].pid;
					pcnt++;
				}
				else
				{
					temp+=p[i].rt;
					p[i].rt=0;
					gt[cnt]=temp;
					ps[pcnt]=p[i].pid;
					pcnt++;
				}
				if(p[i].rt==0)
				{
					allterm++;
					p[i].ft=temp;
					p[i].flag=1;
					if(gt[cnt-1]<=p[i].at)
						p[i].wt=0;
					else if(
