#include<iostream>
using namespace std;
int partition(int *a,int s,int e)
{
	int p=a[e];
	int h=s-1;
	int i;
	for(i=s;i<e-1;i++)
	{
		if(a[i]<=p)
		{	
			h++;
			swap(a[i],a[h]);
		}
	}
	h++;
	swap(a[h],a[i]);
	return h;
}

void quick_sort(int *a,int s,int e)
{
	if(s<e)
	{
		int pi=partition(a,s,e);
		quick_sort(a,s,pi-1);	
		quick_sort(a,pi+1,e);
	}
}
int main()
{
	int *a,n,i;
	cout<<"\nno of terms? ";
	cin>>n;
	a=new int[n];
	cout<<"\nenter terms\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<"\n"<<a[i];
	return 0;
}
