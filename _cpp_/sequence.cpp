#include<iostream>
#include<stdlib.h>
using namespace std;
int num=1;
void (**rptr)();
void foo()
{
	if(num>=100)
		exit(0);
	cout<<++num<<endl;
	*rptr++=foo;
}
main()
{
	rptr=(void(**)())alloca(sizeof(*rptr)*200);
	foo();
	return 0;
	//return system("seq 1 100");
}

