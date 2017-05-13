//Sortig Algorithms
#include<iostream>
using namespace std;
template<class T>
void insertion_sort(T *a,int n)		//Array to be sorted and the no. of elements in it
{
	unsigned int j,i;
	T key;
	for(j=1;j<n;j++)
	{
		key=a[j];
		i=j-1;
		while(i>=0&&i<n)
		{
			if(a[i]>key)
			{
				a[i+1]=a[i];
				i=i-1;
			}
			else 
				break;
		}
		a[i+1]=key;
	}
}
template<class T>
void merge(T *a,int p,int q,int r)
{
	int n1=q-p+1,i,j,k;
	int n2=r-q;
	T b[n1+1],c[n2+1];
	for(i=0,k=p;i<n1;i++)
		b[i]=a[k++];
	for(i=0,k=q+1;i<n2;i++)
		c[i]=a[k++];
	b[n1+1]=-99999;
	c[n2+1]=-99999;
	i=0;
	j=0;
	for(k=p;k<=r;)
	{
		
		if(b[i]!=-99999&&c[j]!=-99999)
		{
			if(b[i]<=c[j])
			{
				a[k++]=b[i];
				i++;
			}
			else
			{
				a[k++]=b[j];
				j++;
			}
			k++;
		}
		else if(b[i]!=-99999)
		{
			a[k++]=b[i++];
		}
		else 
		{
			a[k++]=c[j++];
		}
	}
}
/*void tmerge(T *a,int p,int q,int r)
{
	T temp,temp1;
	while(p!=q+1&&q!=r)
	{
		if(a[p]>a[q])
		{
			
		}
		else
			p++;
	}
}*/
int partition(int *a,int s,int e)
{
	int p=a[e];
	int h=s-1;
	int i;
	for(i=s;i<e;i++)
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
template<class T>
void merge_sort(T *a,int p,int r)
{
	int q;
	if(p==r)
	{return;}
	q=(p+r)/2;
	merge_sort(a,p,q);
	merge_sort(a,q+1,r);
	merge(a,p,q+1,r);
}
main()
{
	int a[5];
	for(int i=0;i<5;i++)
		cin>>a[i];
	merge_sort(a,0,5);
	for(int i=0;i<5;i++)
		cout<<a[i];
	return 0;
}
