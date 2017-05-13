#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t=0,c=0,l=0,flag=1;
	cin>>t;
	while(t--)
	{
		cin>>l>>c;
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(flag)
				{	cout<<'*';
					flag=0;
				}
				else
				{
					cout<<'.';
					flag=1;
				}
			}
			cout<<"\n";
			if(i%2==0)
				flag=0;
			else
				flag=1;		
		}
		cout<<"\n";
		flag=1;
	}
	return 0;
}
