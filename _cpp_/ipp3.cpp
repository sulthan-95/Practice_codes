#include<iostream>
#include<algorithm>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(long long*)a - *(long long*)b );
}
int main()
{
	int i,t,n;
	long long a[100000],sum=0,sum1=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		qsort(a,n,sizeof(long long),compare);
		sum1=sum;
		for(i=0;i<n;i++)
		{
			sum=sum-a[i];
			sum1+=sum;
		}
		sum1=sum1%1000000007;
		cout<<sum1<<"\n";
	}
	return 0;
}








