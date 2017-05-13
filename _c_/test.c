#include<stdio.h>
extern "C"
{
	int printf(const char* format,...);
}
main()
{
	const int j=5;
	int *pt=&j;
	printf("%d",*pt);
	return 0;
}
