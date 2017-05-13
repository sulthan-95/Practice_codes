#include<stdio.h>
#include<stdlib.h>
typedef struct process
{
	int pid,st,ft,prior;
	int wt,tat,at,bt,rt;
	int flag;
}pr;

int n;
pr p[10];
void accept(int);
void fcfs();
void disp_gantt();
void sjf_sort();
void priority_sort();
void round_robin(int);
int checkshort(int pt);
void shortestfirst();
main(int args,char *argv[])
{
	int ch,tq;
	do
	{
		printf("\n\t—- Scheduling Algorithms —-");
		printf("\n\t1. FCFS\n\t2. SJF\n\t3. Priority Based\n\t4. Round Robin\n\t5. Exit");
		printf("\n\t Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: accept(ch);
				fcfs();
				break;
			case 2:
				accept(ch);
				printf("Accepted");
				shortestfirst();
				break;
			case 3:
				accept(ch);
				priority_sort();
				fcfs();
				break;
			case 4: printf("\n\tEnter the Time Quantum: ");
				scanf("%d",&tq);
				accept(ch);
				round_robin(tq);
				break;
			case 5:
				break;
		}
		printf("\n\n\tPress any key to continue………");
	}while(ch!=5);
}

void accept(int ch)
{
	int i;
	printf("\n\tHow many processes: ");
	scanf("%d",&n);
	printf("\tEnter the values\n");
	if(ch==1 || ch==2 || ch==4)
	{
		printf("\n\tArrival Time and Burst Time\n");
		for(i=0;i<n;i++)
		{
			printf("\tEnter for Process %d :",i+1);
			scanf("%d%d",&p[i].at,&p[i].bt);
			p[i].pid=i+1;
			p[i].rt=p[i].bt;
		}
		return;
	}
	if(ch==3)
	{
		printf("\n\tArrival Time , Burst Time and Priority\n");
		for(i=0;i<n;i++)
		{
			printf("\tEnter for Process %d :",i+1);
			scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].prior);
			p[i].pid=i+1;
		}
	}
}
int checkshort(int pt)
{
	int i=0,min=9999,k=0;
	for(i=0;i<n;i++)
	{
		if((min>p[i].rt)&&(p[i].at<=pt)&&(p[i].rt!=0))
		{
			min=p[i].rt;
			k=i;
		}
	}
	return k;
}	
void shortestfirst()
{
	int total=0,pt=0,i=0,k=0,count=0,totwt=0,tottat=0;
	for(i=0;i<n;i++)
	{	total+=p[i].bt;
		printf("%d",p[i].bt);
	}
	for(pt=0;pt<=total;)
	{
		i=checkshort(pt);
		k=i;
		count=0;
		while(p[k].rt!=0)
		{
			p[k].rt-=1;
			pt+=1;
			count+=1;
			i=checkshort(pt);
			if(i!=k)
				break;
		}
		if(p[k].rt==0)
			p[k].tat=pt-p[k].at;
		else
			p[k].rt-=count;
	}
	for(i=0;i<n;i++)
		p[i].wt=p[i].tat-p[i].bt;
	for(i=0;i<n;i++)
		totwt+=p[i].wt;
	for(i=0;i<n;i++)
		tottat+=p[i].tat;
	printf("\nThe average waiting time is %d",totwt/n);
	printf("\nThe average tat is %d",tottat/n);  
}
void fcfs()
{
	int i;
	float avgtat=0,avgwt=0;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			p[i].st=p[i].at;
			p[i].wt=0;
			p[i].tat=p[i].wt+p[i].bt;
			p[i].ft=p[i].st+p[i].bt;
		}
		else
		{
			p[i].st=p[i-1].ft;
			p[i].wt=p[i].st-p[i].at;
			p[i].tat=p[i].wt+p[i].bt;
			p[i].ft=p[i].st+p[i].bt;
		}
		avgtat=avgtat+p[i].tat;
		avgwt=avgwt+p[i].wt;
	}
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	disp_gantt(n);
	printf("\n\t** Average Turn Around Time:%f **",avgtat);
	printf("\n\t** Average waiting time:%f **",avgwt);
}

void disp_gantt()
{
	int i;
	printf("\n\tGANTT CHART\n ");
	for(i=0;i<n;i++)
	{
		printf("\t P%d",p[i].pid);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("\t %d",p[i].st);
	}
	printf("\t %d",p[i-1].ft);
	printf("\n");
}

void sjf_sort()
{
	int i,j;
	pr temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].at==p[j].at)
			{
				if(p[i].bt>p[j].bt)
				{
					temp=p[i];
					p[i]=p[j];
					p[j]=temp;

				}
			}
			else if(p[i].at>p[j].at)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
			else{}
		}
	}
}
void priority_sort()
{
	int i,j;
	pr temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at==p[j+1].at)
			{
				if(p[j].prior>p[j+1].prior)
				{
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}

			}
			else if(p[j].at>p[j+1].at)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
			else{}
		}
	}
}

void round_robin(int tq)
{
	int allterminate=0,cnt=0,i;
	int gt[30],ps[30],temp=0,pcnt=0;
	float avgtat=0;
	printf("\n\tGANTT CHART\n\n");
	while(allterminate<n)
	{
		for(i=0;i<n;i++)
		{
			if(p[i].flag==0) //process incomplete
			{
				p[i].st=temp;
				cnt++;
				if(p[i].bt>=tq)//burst time > time slice
				{

					p[i].bt=p[i].bt-tq;
					temp=temp+tq;
					gt[cnt]=temp;
					ps[pcnt]=p[i].pid;
					pcnt++;
				}
				else
				{ //burst time < time slice
					temp=temp+p[i].bt;
					gt[cnt]=temp;
					p[i].bt=0;
					ps[pcnt]=p[i].pid;
					pcnt++;
				}

				if(p[i].bt==0)
				{
					allterminate++;
					p[i].flag=1;
					p[i].ft=temp;
				}

				if(p[i].flag==1)
				{
					p[i].tat=p[i].ft;
					avgtat=avgtat+p[i].tat;
				}
			}//if

		}//for

	}//while
	for(i=0;i<pcnt;i++)
	{
		printf("\t P%d",ps[i]);
	}
	printf("\n\t0 ");
	for(i=1;i<=cnt;i++)
	{
		printf("\t %d ",gt[i]);
	}
	avgtat=avgtat/n;
	printf("\n\t** Average Turn Around Time:%f **",avgtat);
}
