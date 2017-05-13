#include<bits/stdc++.h>
using namespace std;
long long int middle(long long int start,long long int end)
{
	return start+(end-start)/2;
}
void buildstUtil(long long int arr[],long long int start,long long int end,long long int *st,long long int index)
{
	if(start==end)
	{
		st[index]=start;
		return;
	}
	long long int mid=middle(start,end);
	buildstUtil(arr,start,mid,st,2*index+1);
	buildstUtil(arr,mid+1,end,st,2*index+2);
	if(arr[st[2*index+1]]>arr[st[2*index+2]])
		st[index]=st[2*index+1];
	else
		st[index]=st[2*index+2];
	return;
}
long long int *buildst(long long int arr[],long long int n)
{
	long long int stsize=(long long int)ceil(log2(n));
	stsize=2*(long long int)pow(2,stsize)-1;
	long long int *st=new long long int[stsize];
	buildstUtil(arr,0,n-1,st,0);
	return st;
}
long long int query(long long int *st,long long int index,long long int b,long long int e,long long int arr[],long long int i,long long int j)
{
	if(i>e || j<b)
		return -1;
	if(i<=b && j>=e)
		return st[index];
	long long int a1=query(st,2*index+1,b,(b+e)/2,arr,i,j);
	long long int a2=query(st,2*index+2,(b+e)/2+1,e,arr,i,j);
	if(a1==-1)
		return st[index]=a2;
	if(a2==-1)
		return st[index]=a1;
	if(arr[a1]>arr[a2])
		return st[index]=a1;
	return st[index]=a2;
	
}
void print(long long int arr[],long long int n)
{
	for(long long int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
	long long int *arr,n,q;
	cin>>n;
	arr=new long long int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	long long int *st=buildst(arr,n);
	//long long int stsize=(long long int)ceil(log2(n));
	//stsize=2*(long long int)pow(2,stsize)-1;
	cin>>q;
	while(q--)
	{
		long long int b,c;
		cin>>b>>c;
		cout<<arr[query(st,0,0,n-1,arr,b-1,c-1)]<<endl;
		//print(arr,n);
		//print(st,stsize);
	}
	return 0;
}
