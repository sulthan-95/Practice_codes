#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n,x,y,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y;
		for(i=x;i<n;i++)
		{
			if((i%x==0)&&(i%y!=0))
				cout<<i<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
