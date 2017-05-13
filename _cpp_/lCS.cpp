//Program to find the lOngest common subsequence
#include<iostream>
#include<stdlib.h>
#define size 20
using namespace std;
void print_lcs(int b[][size],int x[size],int i,int j);
void LCS_length(int x[],int m,int y[],int n)
{
	int b[size][size];
	int c[size][size];
	cout<<"\n";
	for(int i=0;i<m+1;i++)
		c[i][0]=0;
	for(int i=0;i<n+1;i++)
		c[0][i]=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(x[i]==y[j])
			{
				c[i+1][j+1]=c[i][j]+1;
				b[i][j]=0;
			}
			else if(c[i][j+1]>=c[i+1][j])
			{
				c[i+1][j+1]=c[i][j+1];
				b[i][j]=1;
			}
			else
			{
				c[i+1][j+1]=c[i+1][j];
				b[i][j]=2;
			}
		}
	}
	print_lcs(b,x,m-1,n-1);
}
void print_lcs(int b[][size],int x[],int i,int j)
{
	if(i==-1||j==-1)
		return;
	if(b[i][j]==0)
	{
		print_lcs(b,x,i-1,j-1);
		cout<<x[i]<<" ";
	}
	else if(b[i][j]==1)
		print_lcs(b,x,i-1,j);
	else
		print_lcs(b,x,i,j-1);
}
int main(int args,char *argv[])
{
	int m,n;
	int *x=new int[size],*y=new int[size];
	cin>>m>>n;
	for(int i=0;i<m;i++)
		cin>>x[i];
	for(int i=0;i<n;i++)
		cin>>y[i];
	LCS_length(x,m,y,n);
	return 0;
}
			

