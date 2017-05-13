#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int i,a[5]={1,2,3,4,5},*p=&a[1],*p1;
	printf("%d\n",*(p++));
	printf("%d\n",*(p++));
	printf("%d\n",*(p--));
	printf("%d\n",*(--p));
	printf("%d\n",*(++p));
	printf("%d\n",*++p);
	printf("%d\n",*p--);
	printf("%d\n",(*p)++);	
	p1=(int *)calloc(5,sizeof(int));
	p1=realloc(p,20);
	//printf("%d\n",*p1);
}

