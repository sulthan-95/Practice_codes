#include<iostream>
using namespace std;
#define N 100
struct books{
	double t;
	double h;
};
int main(int args,char *argv[])
{
	int n,L,sum=0,count=0,max=0,maxi[10];
	books b[N];
	cout<<"\n Enter the length of shelf..";
	cin>>L;
	cout<<"\n ENter the no. of books..";
	cin>>n;
	cout<<"\n Enter the height and thickness of each book..";
	for(int i=0;i<n;i++)
	{
		cout<<"\nBook "<<i+1<<" ";
		cin>>b[i].t>>b[i].h;
		if(b[i].t>L)
		{
			cout<<"\nThis book can't be accomodated in a shelf..";
			i=i-1;
			continue;
		}
		if(max<b[i].h)
			max=b[i].h;
		sum+=b[i].t;
		if(sum>=L)
		{
			if(sum==L)
			{
				maxi[count]=max;
				count++;
				sum=0;
				max=0;
			}
			else
			{
				maxi[count]=max;
				sum=b[i].t;
				max=b[i].h;
				count++;
			}
		}
	}
	maxi[count]=max;
	cout<<"\nThe no. of book shelves required is.."<<count+1;
	for(int i=0;i<count+1;i++)
		cout<<"\nMaximum height of shelf "<<i+1<<" is "<<maxi[i]; 
	return 0;
}
