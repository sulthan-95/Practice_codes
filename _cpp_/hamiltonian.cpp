#include<iostream>
using namespace std;
int x[10],n;
bool G[10][10];
void Nextvalue(int k)
{
	do{
		x[k]=(x[k]+1)%n;
		if(x[k]==0)
			return;
		if(G[x[k-1]][x[k]]){
			int j;
			for(j=0;j<k;j++){
				if(x[j]==x[k])
					break;
			}
			if(j==k)
			{
				if(k<n-1||((k==n-1)&&G[x[n-1]][x[0]]))
					return;
			}
		}
	}while(1);
}
void Hamiltonian(int k)
{
	do{
		Nextvalue(k);
		if(x[k]==0) 
			return;
		if(k==n)
		{
			for(int i=0;i<n;i++)
				cout<<x[i]<<" ";
			cout<<"\n";
		}
		else
			Hamiltonian(k+1);
	}while(1);
}
int main(int args,char *argv[])
{
	int a,b,k;
	cout<<"Enter the no.of nodes..";
	cin>>n;
	for(int i=0;i<n;i++)
		x[i]=0;
	cout<<"\nEnter the edges..";
	do
	{
		cin>>a>>b;
		G[a][b]=true;
		cout<<"\nPress 1 to exit...";
		cin>>k;
	}while(k!=1);
	Hamiltonian(0);
	return 0;
}
