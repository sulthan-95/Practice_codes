#include<iostream>
using namespace std;
int main()
{
	short int t;
	long int t1,t2,t3,total=0;
	cin>>t;
	while(t--)
	{
		total=0;
		cin>>t1>>t2>>t3;
		total=t1/3+t2/3+t3/3;
		t1%=3;
		t2%=3;
		t3%=3;
		if(t1==0||t2==0||t3==0)
		{
			cout<<total<<"\n";
			continue;
		}
		else if(t1==2&&t2==2&&t3==2)
			total+=2;
		else
			total+=1;
		cout<<total<<"\n";
		//cout<<"\n";
	}
}
