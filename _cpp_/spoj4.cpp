#include<iostream>
#include<string.h>
#define sz 200
using namespace std;

int main() {
	// your code goes here
	int n,k=0,j;
	char s[sz];
	cin>>n;
	while(n--)
	{
		cin>>s;
		k=strlen(s)/2;
		for(j=0;j<k;j=j+2)
			cout<<s[j]<<"\n";
	}
	
	return 0;
}
