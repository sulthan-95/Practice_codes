#include<iostream>
#include<string.h>
using namespace std;
char examine(char *a,int i)
{
	return a[i];
}
void swap(char *a,int i,int j)
{
	char t=a[i];
	a[i]=a[j];
	a[j]=t;
}
int main()
{
	char a[]={'R','R','R','W','W','W','B','R'};
	int i=0,b=6,r=0;
	for(i=0;i<strlen(a);)
	{
		if(examine(a,i)=='R')
		{
			if(examine(a,r)!='R')
				r++;
			else
			{	swap(a,i,r);
				r++;
			}
		}
		else if(examine(a,i)=='B')
		{
			if(examine(a,b)!='B')
				b--;
			else
			{	swap(a,i,b);
				b--;
			}
		}
		else
			i++;
	}
	for(i=0;i<strlen(a);i++)
		cout<<a[i]<<"\n";
	return 0;
}
