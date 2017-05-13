#include<iostream>
using namespace std;
int main()
{
	int a=1;
	while(a)
	{
		cin>>a;
		if(a==42)
			break;
		cout<<a<<"\n";
	}
}
