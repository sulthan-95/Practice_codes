#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n;
	long int a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
		c=(b-a)%(long int)(pow(10,9)+7);
        
        if(n%3==0)
        {
        	if(n%2==0)
        		cout<<-c<<endl;
        	else
        		cout<<c<<endl;
		}
		else if(n%3==1)
		{
			if(n%2==0)
				cout<<-a<<endl;
			else
				cout<<a<<endl;
		}
		else{
			if(n%2==0)
				cout<<b<<endl;
			else
				cout<<-b<<endl;
		}
        /*for(int i=0;i<n;i++)
        	cout<<f[i]<<endl;*/
    }
    return 0;
}

