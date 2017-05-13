#include<iostream>
#include<stdio.h>
#include<stack>
#include<string>
using namespace std;
void reversepolishnotation(string t)
{
	stack<char>S;
	for(int i=0;i<t.length();i++)
	{
		if(t[i]=='(')
			continue;
		else if(t[i]>95&&t[i]<=122)
			cout<<t[i];
		else if(t[i]==')')
		{
			cout<<S.top();
			S.pop();
		}
		else
		{
			S.push(t[i]);
		}
	}
}
int main()
{
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		reversepolishnotation(s);
		cout<<"\n";
	}
	return 0;
}
