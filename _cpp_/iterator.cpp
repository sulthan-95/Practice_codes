#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<iterator>
int main()
{
	cout<<"\nEnter two decimals";
	std::istream_iterator<double>inputdec(cin);
	double number1,number2;
	number1=*inputdec;    //read first int from standard input
	++inputdec;           //move iterartor to next input value
	number2=*inputdec;    //read next int from standard input 
	
	cout<<"\nThe sum is :";
	std::ostream_iterator<double>outputdec(cout);
	*outputdec=number1+number2;  //output result to cout
	cout<<endl;
	return 0;
}
