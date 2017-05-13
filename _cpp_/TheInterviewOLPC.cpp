#include<iostream>
using namespace std;
int main(int args,char *argv[])
{
	int t,n,m,a[1000][1000],w,x,y,z,total=0;
	char C;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>a[i][j];
			cout<<"\n";
		}
		while(m--)
		{
			total=0;
			cin>>C;
			if(C=='U')
			{
				cin>>w>>x>>y;
				if(w<n&&x<n)
					a[w-1][x-1]=y;
			}
			else
			{
				cin>>w>>x>>y>>z;
				if(w<n&&x<n&&y<n&&z<n)
				{
					for(int i=w-1;i<y;i++)
					{
						for(int j=x-1;j<z;j++)
							total+=a[i][j];
					}
					cout<<total<<"\n";
				}
			}
		}
	}
}
