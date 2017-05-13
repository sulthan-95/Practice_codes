//Program To do selection sorting
#include<stdio.h>
//using namespace std;
int main(const char *argv[])
{
	int a[5]={21,11,1,34,5};
	int i=0,j=0,k=0,n=sizeof(a)/sizeof(int),temp=-9999;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[k])
				k=j;
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	return 0;
}

