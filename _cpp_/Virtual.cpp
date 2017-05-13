#include<iostream>
#include<conio.h>
using namespace std;
class base
{
	protected:
		int a,b;
	public:
		base(){a=0,b=0;
		}
		void print(){cout<<a<<b;}
		virtual void calculate(){a=1,b=2;}
};
class derived:virtual public base
{
	int c;
	public:
		derived(){c=0,a=4,b=5;}
		void print(){cout<<c;}
		void calculate(){c=a+b;}
};
main()
{
	derived d1;
	base *p=&d1;
	d1.calculate();
	d1.print();
	return 0;
}

