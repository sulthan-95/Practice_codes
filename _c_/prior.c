#include<stdio.h>
#include<stdlib.h>
#define sz 20
int main(int args,char *argv[])
{
	int i,bt[sz],at[sz],rt[sz],et,time=0,remain=0,n,pr[sz],small;
	float avgtat,avgwt,totwt=0.0,totat=0.0;
	printf("\nEnter the no. of processes..");
	scanf("%d",&n);
	printf("\nEnter the arrival,burst time and priority of all the prrocesses..");
	for(i=0;i<n;i++)
	{
		printf("p[%d] ",i+1);
		scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
		rt[i]=bt[i];
	} 
	printf("Process\t\tTurnAroundTime\t\tWaiting time\n");
	for(time=0;remain!=n;time++)
	{
		small=n+1;
		pr[small]=9999;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && pr[i]<pr[small] && rt[i]>0)
				small=i;
		}
		rt[small]--;
		if(rt[small]==0)
		{
			remain++;
			et=time+1;
			printf("\np-[%d]\t\t%d\t\t%d",small+1,et-at[small],et-bt[small]-at[small]);
			totwt+=et-bt[small]-at[small];
			totat+=et-at[small];
		}
	}
	avgwt=totwt/n;
	avgtat=totat/n;
	printf("\nAverage Waiting Time is %0.2f\nAverage Turn arounf Time is %0.2f\n",avgwt,avgtat);
	return 0;
}
		
