#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int count(int a)
{
    int q=0;
    while(a>0)
    {
       a=a/10;
       q++;
    }
    return q;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t,c,c1,a,i,b,d=0,l=1000000000,p=1;
    cin>>t;
    while(t--)
    {
        cin>>a;
        if(l<a)
        	p=l;
        else
        {
			p=1;
			d=0;
		}
        for(i=p;i<=a;i++)
        {   
            c1=0;
            c=count(i);
            if(i%10==0)
            {	 b=i;
                while(b>0)
                {
                     if(b%10==0||b%10==1)
                        c1++;
                     b=b/10;
                }
            }
            else if(i%10==1)
            {	 b=i;
                while(b>0)
                {
                    if(b%10==0||b%10==1)
                        c1++;
                    b=b/10;
                }
            }
            else{}
            if(c==c1)
            {
                d++;
            }
        }
        cout<<d<<"\n";
		l=a;
	}
    return 0;
}

