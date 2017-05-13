#include <bits/stdc++.h>
using namespace std;
int middle(int start,int end){
	return start+(end-start)/2;
}
int buildstUtil(int arr[],int start,int end,int *st,int index)
{
	if(start==end)
	{
		if(arr[start]%3==0)
			st[index]=1;
		else
			st[index]=0;
		return st[index];
	}
	
	int mid=middle(start,end);
	st[index]=buildstUtil(arr,start,mid,st,2*index+1)+buildstUtil(arr,mid+1,end,st,2*index+2);
	return st[index];
}
int * buildst(int arr[],int n)
{
	int stsize=(int)ceil(log2(n));
	stsize=2*(int)pow(2,stsize)-1;
	int *st=new int[stsize];
	int root=buildstUtil(arr,0,n-1,st,0);
	return st;
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
int query(int *st,int index,int b,int e,int arr[],int i,int j)
{
	if(i>e || j<b)
		return 0;
	if(i<=b && j>=e)
		return st[index];
	int total=query(st,2*index,b,(b+e)/2,arr,i,j)+query(st,2*index+1,((b+e)/2)+1,e,arr,i,j);
	return total;
}

void update(int *st,int b,int e,int arr[],int i,int j,int index)
{
	if(b>e || j<b || i>e)
		return;
	if(b==e)
	{
		arr[b]+=1;
		if(arr[b]%3==0)
			st[index]=1;
		else
			st[index]=0;
		return;
	}
	/*int el1=update(st,b,middle(b,e),arr,i,j,2*index+1);
	if(el1==1)
	{
		st[index]+=1;
	}
	int el2=update(st,middle(b,e)+1,e,arr,i,j,2*index+2);
	if(el2==1)
	{
		st[index]+=1;
	}*/
	update(st,b,middle(b,e),arr,i,j,2*index+1);
	update(st,middle(b,e)+1,e,arr,i,j,2*index+2);
	st[index]=st[2*index+1]+st[2*index+2];
}
int main() {
	// your code goes here
	int *arr,n,q;
	cin>>n>>q;
	arr=new int[n];
	for(int i=0;i<n;i++)
		arr[i]=0;
	int *st=buildst(arr,n);
	//int stsize=(int)ceil(log2(n));
	//stsize=2*(int)pow(2,stsize)-1;
	while(q--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==0)
			update(st,0,n-1,arr,b,c,0);
		else if(a==1)
			cout<<query(st,0,0,n-1,arr,b,c)<<endl;
		//print(arr,n);
		//print(st,stsize);
	}
	return 0;
}
