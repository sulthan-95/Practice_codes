#include <iostream>
using namespace std;
long double factorial(int a)
{
	long double q=1;
	if(!a)
			return 1;
	for(;a>=1;a--)
		q=q*a;
	return q;
}
int main() {
	// your code goes here
	int t=0,c=0,count=0;
	long double a=1,k=10;
	cin>>t;
	while(t--)
	{
		cin>>c;
		a=factorial(c);
		cout<<a<<"\n";
		while(a>0)
		{
			if(a%k==0)
				count++;
			a=a/10;
		}
		a=1;
		cout<<count<<"\n";
		count=0;
	}
	return 0;
}
