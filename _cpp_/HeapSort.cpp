#include<iostream>
#include<stdlib.h>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void max_heapify(int *arr,int i,int N)
{
	int left=2*i,right=2*i+1,largest=i;
	if(left<=N && arr[left]>arr[i])
		largest=left;
	else if(right<=N && arr[right]>arr[largest])
		largest=right;
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		max_heapify(arr,largest,N);
	}
}
void buildheap(int *arr,int N)
{
	for(int i=N/2;i>=1;i--)
		max_heapify(arr,i,N);
}
void heap_sort(int *arr,int N)
{
	int heap_sz=N;
	buildheap(arr,N);
	for(int i=N;i>=2;i--)
	{
		swap(arr[1],arr[i]);
		heap_sz-=1;
		max_heapify(arr,1,heap_sz);
	}
}
int main(int args,char *argv[])
{
	int a[10],N;
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>a[i];
	heap_sort(a,N);
	for(int i=1;i<=N;i++)
		cout<<a[i]<<"\n";
	cout<<"\n";
	return 0;
}
 
