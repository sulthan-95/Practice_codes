#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool find(int a,int b,int x,int y)
{
    int i=1;
    while(true)
    {
        if(a==x&&b==y)
            return true;
        else if(a>x||b>y)
            break;
        else
        {
            if(i%2!=0)
                a=a+b;
            else
                b=a+b;
        }
        i++;
    }
    return false;    
}
bool findback(int a,int b,int x,int y)
{
   int i=1;
    while(true)
    {
        if(a==x&&b==y)
            return true;
        else if(a<x||b<y)
            break;
        else
        {
            if(i%2!=0)
                a=a-b;
            else
                b=a-b;
        }
        i++;
    }
    return false;    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long int t,a,b,x,y;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>x>>y;
        if(x>=a&&y>=b)
        {
            if(find(a,b,x,y))
                   cout<<"YES";
            else
                cout<<"NO";
        }
        else
        {
            if(findback(a,b,x,y))
                cout<<"YES";
            else
                cout<<"NO";
        }
    }
    return 0;
}

