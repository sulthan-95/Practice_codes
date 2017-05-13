#include<stdio.h>
#include<conio.h>
#include<process.h>
typedef struct process
{
        int pid,st,ft,prior;
        int wt,tat,at,bt;
        int flag;
}pr;
pr p[10];
void FCFS(int n,char p[][],int et[],int at[])
{
	int tot=0,wt[10],tt[10],i,total=0,processortime[10];
	float avg=0,avg1=0;
	wt[0]=0;
	tt[0]=et[0];
	processortime[0]=tt[0]+at[0];
	for(i=1;i<n;i++)
	{
		wt[i]=processortime[i-1]-at[i];
		tt[i]=wt[i]+et[i];
		tot=tot+wt[i];
		total+=tt[i];
		processortime[i]=processortime[i-1]+tt[i];
	}
	avg=(float)tot/n;
	avg1=(float)total/n;
	printf("----------First Come First Serve---------");
	printf("\nP_name\t P_time\t W_time\tTAT_\n");
	for(i=0;i<n;i++)
		printf("%s\t%d\t%d\t%d\n",p[i],et[i],wt[i],tt[i]);
	printf("Total waiting time=%d\n avg waiting time=%f\nAverage TAT=%f",tot,avg,avg1);
}
void SJF(int n,char p[],int et[],int at[])
{
	int total=0,i,j,st;
	for(i=0;i<n;i++)
		total+=et[i];
	st=at[0];
	total+=st;
	for(i=0;i<=total;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==st)
			{
				sort(

