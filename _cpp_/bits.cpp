#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int *binary=new int[8];
int *dtb(int quotient)
{
	 int i=0;
	 while(i<8){
         binary[i++]= quotient % 2;
         quotient = quotient / 2;
    }
    /*for(int j=7;j>=0;j--)
    	cout<<binary[j];*/
    return binary;
}
int btd(int a[])
{
	int dec=0;
	for(int i=0;i<6;i++)
	{
		if(a[i]==1)
			dec+=pow(2,i);
	}
	return dec;
}
int main()
{
	int t,n,a1[6],b1[6],t1=0;
	int *bit[6];
	char str1[6],str2[64];
	cin>>t;
	while(t--)
	{
		cin>>n;
		int *a=new int[n],*b=new int[n],in=0;
		while(in<n)
		{
			cin>>str1;
			for(int j=0;j<6;j++)
				bit[j]=dtb((int)str1[j]);
			for(int k=0,j=0;k<6;k++,j++)
			{
				a1[j]=bit[k][k];
				t1=(k+3)%6;
				b1[j]=bit[k][t1];
			}
			a[in]=btd(a1);
			b[in]=btd(b1);
			in++;
		}
		cin>>str2;
		for(int i=0;i<n;i++)
			cout<<str2[a[i]]<<str2[b[i]];
		cout<<"\n";
	}
	return 0;
}
