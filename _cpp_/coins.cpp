#include<iostream>
using namespace std;
#define size 100
int main(int args,char *argv[])
{
	int n,C,v[size],M[size],min=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<"\nCost\n";
	cin>>C;
	for(int j=0;j<=C;j++)
	{
		if(j<v[0])
			M[j]=0;
		/*else if(j==1)
			M[j]=1;*/
		else
		{
			min=M[j-v[0]];
			for(int i=1;i<n;i++)
			{
				if(j-v[i]>=0)
				{
					if(min>(M[j-v[i]]))
						min=M[j-v[i]];
				}
			}
			M[j]=min+1;
		}
	}
	cout<<"\n"<<M[C]<<"\n";
	return 0;
}
		
				
