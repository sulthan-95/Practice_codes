#include<iostream>
using namespace std;
int main(int args,char *argv[])
{
	int n,q,a,flag=0,fail=-1;
	char c;
	cin>>n>>q;
	int *status=new int[n];
	for(int i=0;i<n;i++)
		status[i]=0;
	while(q--)
	{
		cin>>c>>a;
		if(c=='C'||c=='c')
		{
			if(status[a-1]==0)
				status[a-1]=1;
			else
				status[a-1]=0;
		}
		else if(c=='I'||c=='i')
		{
			for(int i=a-1;i<n;i++)
			{
				if(status[i]==1)
				{	
					cout<<i+1<<"\n";
					flag=1;
					break;
				}
			}
			if(flag==0)
				cout<<fail<<"\n";
		}
		flag=0;
	}
	return 0;
}
