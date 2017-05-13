//Program to work with exceptions
#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
main()
{
	int a,b;
	cout<<"enter two no.";
	cin>>a>>b;
	try{
		if(b==0)
			throw b;
		else
			cout<<setw(20)<<setiosflags(ios::right)<<"\nThe quotient is.."<<a/b<<endl;
	}
	catch(...)
	{
		cout<<"Denominator can't be this"<<endl;
	}
	return 0;
}

