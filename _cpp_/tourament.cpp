#include<iostream>
#define Max 100
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int tournament(int n,int *ar)
{
	if(n<=1)
		return ar[0];
	for(int i=0,j=0;i<n;i+=2,j++)
	{
		if(i==(n-1))
			swap(ar[j],ar[i]);
		else if(ar[i]>ar[i+1])
			swap(ar[j],ar[i]);
		else
			swap(ar[j],ar[i+1]);
	}
	n=(n+1)/2;
	tournament(n,ar);
}
int maxmin(int n,int *ar);
int main(int args,char *argv[])
{
	int a[Max],n;
	cout<<"Enter the no. of elements..";
	cin>>n;
	cout<<"\nenter the elements..";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nThe maximum element is "<<tournament(n,a);
	for(int i=0;i<n;i++)
		cout<<"\n"<<a[i]<<" ";
	return 0;
}
