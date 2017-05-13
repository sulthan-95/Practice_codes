#include<iostream>
using namespace std;
#define sz 20
int main(int args,char *argv[])
{
	int n,m,c[sz][sz];
	char a[sz],b[sz];
	cout<<"\n enter the length of 2 strings";
	cin>>n>>m;
	cout<<"\n enter Them..";
	cin>>a>>b;
	for(int i=0;i<n;i++)
		c[i][0]=0;
	for(int i=0;i<m;i++)
		c[0][i]=0;
	
	
