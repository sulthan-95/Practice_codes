#include<iostream>
#include<stdlib.h>
using namespace std;
int pk[10]={0};
class Hello{
	int a;
	Hello(int a)
	{
		this.a=a;
	}
	void print()
	{
		cout<<a<<endl;
	}
};
int main()
{
	Hello h(5);
	h.print();
	cout<<endl;
	return 0;
}
