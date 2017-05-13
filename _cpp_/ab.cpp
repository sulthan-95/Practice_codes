#include<iostream>
using namespace std;
int main()
{
	                    
	int  x;
	scanf("%d",&x);
	int i=2,flag=0;
	if(x==1)	//1 is neither prime nor composite. So odd
		printf("odd");
	else if(x%2==0)	//Even can never be prime
		printf("even");
	else	//Prime checker
	{
		for(i=2;i*i<=x;i++)
		{
			if(x%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("prime");
		else		//If it's not prime confirm odd only..
			printf("odd");
	}
	return 0;
}
