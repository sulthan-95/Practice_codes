//Program for maximum subsequence
#include<iostream>
using namespace std;
#define size 100
struct MAXSEQ{
	int start;
	int end;
	int value;
}m[10];
bool max(int a,int b)
{
	if(a>b)
		return true;
	else
		return false;
}
void maxsubseq(int *a,int n)
{
	int high=0,st=0,en=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			m[i].value=a[i];
			m[i].start=i;
			m[i].end=i;
		}
		else
		{
			if(max(m[i-1].value+a[i],a[i]))
			{
				m[i].value=m[i-1].value+a[i];
				m[i].start=m[i-1].start;
				m[i].end=i;
			}
			else
			{
				m[i].value=a[i];
				m[i].start=i;
				m[i].end=i;
			}
		}	
		
	}
	for(int i=0;i<n;i++)
	{
		if(high<m[i].value)
		{
			high=m[i].value;
			st=m[i].start;
			en=m[i].end;
		}
	}
	cout<<"\nThe maximum value is.."<<high<<" and its array is\n";
	for(int i=st;i<=en;i++)
		cout<<a[i]<<" ";			
	cout<<"\n";
}
int main(int args,char *argv[])
{
	int n,a[size];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	maxsubseq(a,n);
	return 0;
}
