#include<iostream>
using namespace std;
void merge(int *l,int *r,int *b,int nl,int nr,int n)
{
	//int nl=sizeof(l)/2;
	//int nr=sizeof(r)/2;
	int i=0,k=0,j=0;
	while(i<nl&&j<nr)
	{
		if(l[i]<=r[j])
		{
			b[k]=l[i];
			i++;
		}
		else
		{
			b[k]=r[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		b[k]=l[i];
		k++;
		i++;
	}
	while(j<nr)
	{
		b[k]=r[j];
		k++;
		j++;
	}
	cout<<"\nafter merging";
	for(int i=0;i<n;i++)
		cout<<b[i];
	cout<<'\n';
}
void merge_sort(int *a,int n)
{
	if(n<2)
		return;
	int mid=n/2;
	int *la,*ra;
	la=new int[mid];
	ra=new int[n-mid];
	int i;
	for(i=0;i<mid;i++)
	{
		la[i]=a[i];
		//cout<<a[i];
	}
	//cout<<'\n';
	int k=0;
	for(i=mid;i<n;i++)
	{
		ra[k]=a[i];
		k++;
		//cout<<a[i];
	}
	//cout<<'\n';
	merge_sort(la,mid);
	merge_sort(ra,n-mid);
	merge(la,ra,a,mid,n-mid,n);
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
	merge_sort(a,n);
	cout<<"\nsorted array is";
	for(int i=0;i<n;i++)
		cout<<a[i];
	return 0;
}
