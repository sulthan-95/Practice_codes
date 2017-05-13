#include<iostream>
#include<string.h>
using namespace std;
/*extern "C"
{
	int printf(const char *format,...);
}*/
class Pet{
	public:
		virtual string getdescription()const{
		return "This is pet class";
		}
};
class Dog:public Pet{
	public:
	virtual string getdescription(){
		return "This is dog class";
	}
};
void describe(Pet &p)
{
	cout<<p.getdescription()<<endl;
}
int main()
{
	/*void *vptr;   1.void conversion
	int *iptr;
	iptr=vptr;*/
	//const int a;  2.Const intialization
	//printf("Geeks for geeks");  3.Extern "C"
	//printf("%d",sizeof('s'));  4.int and char variation
	//cout<<sizeof(1==1);  5.Boolean expression
	/*int *ptr;
	int &ref=*ptr;*/
	//  6.Reference intialized to unintialized pointer
	Dog d;
	describe(d);   //Doesnt slice the derived class object
	return 0;
}
