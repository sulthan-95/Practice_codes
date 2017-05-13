#include<iostream>
using namespace std;
int main()
{
	int i,j,t,st,k,en,flag;
	cin>>t;
    for(k=0;k<t;k++)
    {
        cin>>st>>en;
        for(i=st;i<=en;i++)
		{
			flag=0;
			for(j=2;j*j<=i;j++)
			{
				if(i%j==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0&&i>1)
				cout<<i<<"\n";
		}
		cout<<"\n";
	}
}
