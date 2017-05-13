#include<stdio.h>
#define MAX(c,d) c##d
#define gee(c) #c
#define III(a,b) while(b>0)\
			{\
				printf("\n%d",a--);\
				b--;\
			}
#define cube(x) x*x*x
int main(void)
{
	int i=5,a=2,b=3,x=16/cube(4);
	if(--i)
	{
		
		printf("%d\n",MAX(6-5,2*3));
		printf("%s\n%d",gee(12345),x);
		III(a,b);
		//main(10);
	}
	/*printf("\nCurrent File:%s\n",_FILE_);
	printf("Current Date:%s\n",_DATE_);
	printf("Current Time:%s\n",_TIME_);
	printf("Line Number:%s\n",_LINE_);*/
	return 0;
}
