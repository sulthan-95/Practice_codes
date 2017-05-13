#include<iostream>
#include<cstdlib>
using namespace std;
int compare (const void *elem1, const void *elem2){
	return *(int*)elem1 - *(int*)elem2;
}
int main(int args,char *argv[])
{
	int t,k,n,sum=0,flag=0;
	int x,y,square;
	//cin>>t;
	//while(t--)
	//{
	sum=0;
	cin>>k>>n;
	int rad[k];
	for(int i=0;i<k;i++)
		cin>>rad[i];
	qsort(rad,k, sizeof(int),compare);
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		//flag=0;
		square=(x*x)+(y*y);
		for(int i=0;i<k;i++)
		{
			if(square<=(rad[i]*rad[i]))
			{
				sum+=(k-i);
				//flag=1;
				break;
			}
		}
	}
	cout<<sum;
	//}
	return 0;
}
