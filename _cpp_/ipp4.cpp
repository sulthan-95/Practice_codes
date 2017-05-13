#include <iostream>
#include<stack>
#include<stdlib.h>
using namespace std;
int main() {
	// your code goes here
	
	stack<unsigned int>s;
	int t,num,n,i=0;
	cin>>t;
	stack<unsigned int>s1[t]; 
	while(i<t)
	{
		cin>>n;
		if(n==1)
		{
			cin>>num;
			s.push(num);		
		}
		else if(n==2)
		{
			if(s.empty())
				s.pop();
		}
		if(s.empty())
			s1[i].push(-1);
		else
			s1[i]=s;
		i++;
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		while(!s1[n-1].empty())
		{
			cout<<s1[n-1].top()<<" ";
			s1[n-1].pop();
		}
	}
	return 0;
}

