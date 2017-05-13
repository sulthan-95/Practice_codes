#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
int middle(int start,int end){
	return start+(end-start)/2;
}
int minim(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
void buildstUtil(int arr[],int start,int end,int *st,int index)
{
	if(start==end)
	{
		st[index]=arr[start];
		return;
	}
	int mid=middle(start,end);
	buildstUtil(arr,start,mid,st,2*index+1);
	buildstUtil(arr,mid+1,end,st,2*index+2);
	st[index]=minim(st[2*index+1],minim(st[2*index+2],st[2*index+1]+st[2*index+2]));
}
int * buildst(int arr[],int n)
{
	int stsize=(int)ceil(log2(n));
	stsize=2*(int)pow(2,stsize)-1;
	int *st=new int[stsize];
	buildstUtil(arr,0,n-1,st,0);
	return st;
}
int query(int *st,int index,int b,int e,int arr[],int i,int j)
{
	if(i>e || j<b)
		return 99999;
	if(i<=b && j>=e)
		return st[index];
	int first=query(st,2*index+1,b,middle(b,e),arr,i,j);
	int second=query(st,2*index+2,middle(b,e)+1,e,arr,i,j);
	if(first<second)
		return first;
	else
		return second;
}
void update(int *st,int b,int e,int arr[],int x,int y,int index)
{
	if(x<b || x>e)
		return;
	if(b==e)
	{
		arr[b]=y;
		st[index]=arr[b];
		return;
	}
	update(st,b,middle(b,e),arr,x,y,2*index+1);
	update(st,middle(b,e)+1,e,arr,x,y,2*index+2);
	st[index]=minim(st[2*index+1],minim(st[2*index+2],st[2*index+1]+st[2*index+2]));
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
	int var1,var2,var3;
	cin>>var1;
	while(var1--)
	{
		cin>>var2;
		int *var4=new int[var2];
		for(int i=0;i<var2;i++)
			cin>>var4[i];
		int *var5=buildst(var4,var2);
		int var6=(int)ceil(log2(var2));
		var6=2*(int)pow(2,var6)-1;
		cin>>var3;
		while(var3--)
		{
			int var7,var8,var9;
			cin>>var9>>var7>>var8;
			if(var9==0)
			{
				update(var5,0,var2-1,var4,var7-1,var8,0);
			}
			else if(var9==1)
			{
				cout<<query(var5,0,0,var2-1,var4,var7-1,var8-1)<<endl;
			}
		}
	}
}
