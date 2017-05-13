#include<iostream>
#include<math.h>
using namespace std;
int main(int args,char *argv[])
{
	int n,c=0;
	cin>>n;
	while(n)
	{
		if(n%2!=0)
			c+=1;
		n/=2;
	}
	cout<<c;
	return 0;
}
