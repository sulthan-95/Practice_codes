#include<iostream>
#define size 100
using namespace std;
int x[size];
bool G[size][size];
void Nextvalue(int k,int n,int m)
{
	int j;
	do{
		x[k]=(x[k]+1)%(m+1);
		if(!x[k])
			return;
		for(j=0;j<n;j++)
		{
			if(G[k][j]&&(x[k]==x[j]))
				break;
		}
		if(j==n)
			break;
	}while(1);
}
void Mcoloring(int k,int n,int m)
{
	do{
		Nextvalue(k,n,m);
		if(!x[k])
			break;
		if(k==n)
		{
			cout<<"\n";
			for(int i=0;i<n;i++)
			{
				cout<<x[i]<<" ";
			}
			break;
		}
		else
			Mcoloring(k+1,n,m);
	}while(1);
}
int main(int args,char *argv[])
{
	int k,j,n,ch;
	cout<<"\n enter the no.of nodes...";
	cin>>n;
	cout<<"\nEnter the nodes between which edges exist...\n";
	do{
		cin>>k>>j;
		G[k][j]=true;
		G[j][k]=true;
		cout<<"\nAny other edge...\t1.Yes\t2.No\n";
		cin>>ch;
	}while(ch==1);
	cout<<"\n";
	Mcoloring(0,n,n-1);
	return 0;
}
