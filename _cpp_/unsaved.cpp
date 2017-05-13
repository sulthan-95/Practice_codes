#include<iostream>
using namespace std;
int main()
{
	int t,n,a,b,d,x1,y1,x2,y2,e;
	char c;
	cin>>t;
	while(t--)
	{
		cin>>n;
		while(n--)
		{
			cin>>c;
			if(c=='p')
				cin>>a>>b;
			else if(c=='c')
				cin>>a>>b>>d;
			else if(c=='l')
				cin>>a>>b>>d>>e;
		}
	}
}
