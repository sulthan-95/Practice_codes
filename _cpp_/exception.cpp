//Program to perform exception handling
#include<iostream>
#include<iomanip>
using namespace std;
//Class divide By Zero exception
class dividebyzeroexception
{
	public:
	dividebyzeroexception():message("attempted to divide by zero"){}
	const char *what()const{return message;}
	private:
	const char *message;
};
//Definition of function quotient
double quotient(int numerator,int denominator)
{
	if(denominator==0)
		throw dividebyzeroexception();
	return static_cast<double>(numerator)/denominator;
}
//Driver Program
int main()
{
	int no1,no2;
	double result;
	cout<<"Enter two no.(end of file to end)"<<endl;
	while(cin>>no1>>no2)
	{
		//try block wraps the code that may throw an exception//
		//and the code that should not execute if an exception//
		//occurs//
		try{
			result=quotient(no1,no2);
			cout<<"\nThe quotient is :"<<result<<endl;
		}
		catch(dividebyzeroexception ex)
		{
		//exception handler
			cout<<"Exception occured:"<<ex.what()<<endl;
		}
		cout<<"Enter two no.(end of file to end)"<<endl;
	}
	return 0;	//terminate normally//
}
