#include<stdio.h>
//using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int Partition(int *a,int p,int r)
{
	int x=a[r];
	int i=p-1,j;
	for(j=p;j<r;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return i+1;
}
int Selection(int *a,int p,int r,int i)
{
	if(p==r)
		return a[p];
	int q=Partition(a,p,r);
	int k=q-p+1;
	if(i==k)
		return a[q];
	else if(i<k)
		return Selection(a,p,q-1,i);
	else
		return Selection(a,q+1,r,i-k);
}	
int main(int args,char *argv[])
{
	int a[]={13,2,25,6,9,75},n=6,i=2;
	//cout<<"\nThe "<<i<<"th smallest element is.."<<Selection(a,0,n,i);
	printf("\n The %d smallest element is..%d\n",i,Selection(a,0,n-1,i)); 
	return 0;
}
