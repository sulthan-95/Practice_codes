#include<iostream>
using namespace std;
static int tq;
int n,remain[10];
class process
{
	public:
		int pid;
		int bt;
		int dbt;
		int ar;
		int wt;
		int tat;
		int st;
		int ft;
		int flag;
}p[20];
void calculate_remain()
{
	int i,j;
	remain[0]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;;j++)
			if(tq*j>=p[i].dbt)
			{
				remain[i]=tq*j-p[i].dbt;
				break;
			}
	}
}
int get_remain(int x)
{
	int i,sum=0;
	for(i=0;i<x;i++)
		sum+=remain[i];
	return sum;
}


void sort()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(p[j].ar>p[j+1].ar)
			{
				process temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}

}
void accept()
{
	cout<<"\n enter number of process : ";
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"\n Process["<<i<<"]";
		cout<<"\nEnter Arrival time : ";
		cin>>p[i].ar;
		cout<<" Enter Burst time : ";
		cin>>p[i].bt;
		p[i].dbt=p[i].bt;
		p[i].pid=i;
		cout<<'\n';
	}
	cout<<"\n enter time quantum :";
	cin>>tq;
}
void static_round_robin()
{
	int allterminate=0,cnt=0,i;
	int gt[30],ps[30],temp=0,pcnt=0;
	gt[0]=p[0].ar;
	float avgtat=0;
	float avgwt=0;
	float remain=0;
	while(allterminate<n)
	{
		for(i=0;i<n;i++)
		{
			if(p[i].flag==0)
			{
				p[i].st=temp;
				cnt++;
				if(p[i].bt>=tq)
				{
					p[i].bt=p[i].bt-tq;
					temp=temp+tq;
					gt[cnt]=temp;
					ps[pcnt]=p[i].pid;
					pcnt++;
				}
				else
				{
					temp=temp+p[i].bt;
					remain=temp-tq*(cnt-1);
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
					if(gt[cnt-1]-p[i].ar<=0)
						p[i].wt=0;
					else //if(p[i].dbt-tq<=0)
						p[i].wt=tq*(cnt-1)-p[i].ar;
					//else
					//p[i].wt=tq*(cnt-1)-p[i].ar-(p[i].dbt-tq);
				}
				if(p[i].flag==1)
				{
					remain=get_remain(i);
					p[i].tat=p[i].ft+remain;
					avgtat=avgtat+p[i].tat;
					avgwt=avgwt+p[i].wt;
				}
			}
		}
	}
	cout<<"\n              T.A.T \tW.T   ";
	for(i=0;i<n;i++)
	{
		cout<<"\nProcess["<<i<<"]     "<<p[i].tat<<"\t "<<p[i].wt;
	}
	int slice=0;;
	cout<<"\n\n\t****************GANTT CHART**************\n\n";
	for(i=0;i<pcnt;i++)
	{
		cout<<"\t   P"<<ps[i];
	}
	cout<<"\n\t0 ";
	for(i=1;i<=cnt;i++)
	{
		slice+=tq;
		cout<<"\t"<<slice;
	}
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	cout<<"\n\n\t*****************************************\n\n";
	cout<<"\n\n\t**Number of Context Switch  : "<<pcnt<<" times   **";
	cout<<"\n\t** Average Turn Around Time : "<<avgtat<<" seconds  **";
	cout<<"\n\t** Average Waiting Time     : "<<avgwt<<" seconds    **";
}
int main()
{
	accept();
	sort();
	calculate_remain();
	static_round_robin();
	return 0;
}
