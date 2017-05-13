#include<iostream>
using namespace std;
int main(int args,char *argv[])
{
	int t;
	long long s,w,q,p,T,sum=0;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>s>>w>>q>>p>>T;
		sum=s+w+q+p;
		if(sum<=T)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
