#include<bits/stdc++.h>
#define merge(a,b) b##a
using namespace std;
main()
{
	int j,k=0,d=0;
	string n[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	stack<int>s;
	cin>>j;
	do
	{
		s.push(j%10);
		j=j/10;
	}while(j>0);
	do
	{
		cout<<n[s.top()]<<" ";
		s.pop();	
	}while(!s.empty());
	cout<<"\n"<<merge(12,36);
	return 0;
}
