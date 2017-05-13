#include<bits/stdc++.h>
using namespace std;
bool is_prime(long long n)
{
	if(n>=2)
	{
		for(long long i=2;i*i<=n;i++)
		{
			if(n%i==0)
				return false;
		}
	}
	else 
		return false;
	return true;
}
long long fibo(long long n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return fibo(n-1)+fibo(n-2);
}
int main()
{
	long long i=0,a,sum=0;
	while(sum<100000000)
	{
		a=fibo(i++);
		if(is_prime(a))
			sum+=a;
	}
	cout<<sum<<"\n";
	return 0;
} 
