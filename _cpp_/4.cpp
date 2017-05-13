#include<iostream>
#include<stdlib.h>
using namespace std;
int n;
class peace{
	public:
	union no{
		double x;
		int n=7;
		char ch;
	};
	int k;
	peace(){
		k=1;
		n=2;
	}
	int f() const {return n;}
}a;
int main()
{
	n=28;
	printf("%d\n",a.f());
	return 0;	
}	
