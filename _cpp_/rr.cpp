#include<iostream>
using namespace std;
static float tq;
int n;
class process
{
	public:
		int pid;
		float bt;
		float dbt;
		float ar;
		float wt;
		float tat;
		float st;
		float ft;
		int flag;
		//int lock;
}p[20];
float get_dynamic_tq(int x)
{
	float sum=0;
	int i,cnt=0;
	for(i=0;i<n;i++)
		if(p[i].ar<=x && p[i].flag!=1)
		{
			cout<<"\n p["<<i<<"]bt = "<<p[i].bt;
			sum=sum+p[i].bt;
			//p[i].lock=0;
			cnt++;
		}
	sum=sum/cnt;
	cout<<"\n final tq :"<<sum;
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
		//p[i].lock=1;
		p[i].dbt=p[i].bt;
		p[i].pid=i;
		cout<<'\n';
	}
}
void dynamic_round_robin()
{
	int allterminate=0,cnt=0,i;
	float gt[30];
	int ps[30];
	float temp=0;
	int pcnt=0;
	gt[0]=p[0].ar;
	float avgtat=0;
	float avgwt=0;
	cout<<"\nEnter the time quantum..";
	cin>>tq;
	while(allterminate<n)
	{
		//tq=get_dynamic_tq(gt[cnt]);
		for(i=0;i<n;i++)
		{
			if(p[i].flag==0)//&&p[i].lock==0)
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
					else if(p[i].dbt-tq<=0)
						p[i].wt=gt[cnt-1]-p[i].ar;
					else
						p[i].wt=gt[cnt-1]-p[i].ar-(p[i].dbt-tq);
				}
				if(p[i].flag==1)
				{
					p[i].tat=p[i].ft;
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
	cout<<"\n\n\t****************GANTT CHART**************\n\n";
	for(i=0;i<pcnt;i++)
	{
		cout<<"\t   P"<<ps[i];
	}
	cout<<"\n\t0 ";
	for(i=1;i<=cnt;i++)
	{
		cout<<"\t"<<gt[i];
	}
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	cout<<"\n\n\t*****************************************\n\n";
	cout<<"\n\n\t**Number of Context Switch  : "<<pcnt<<" times      **";
	cout<<"\n\t** Average Turn Around Time :"<<avgtat<<" seconds  **";
	cout<<"\n\t** Average Waiting Time     :"<<avgwt<<" seconds   **";
}
int main()
{
	accept();
	sort();
	dynamic_round_robin();
	return 0;
}
