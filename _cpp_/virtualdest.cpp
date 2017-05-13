#include<iostream>
using namespace std;
class base1{
	int a,b;
	public:
	base1(){a=7;b=5;}
	void getdata(){cin>>a>>b;}
	void print(){cout<<a<<"  "<<b;}
	~base1(){cout<<"destructor base1"<<endl;}
};
class base2{
	int c,d;
	public:
	base2(){c=0;d=0;}
	void getdata(){cin>>c>>d;}
	void print1(){cout<<c<<"  "<<d;}
	~base2(){cout<<"destructor base2"<<endl;}
};
class derived:public base1,base2
{
	int g;
	public:
	derived(){g=0;}
	~derived(){cout<<"\ndestructor derived\n ";};
};
int main()
{
	derived f;
	base1 *p=&f;
	p->print();
	//delete p;
	return 0;
}
