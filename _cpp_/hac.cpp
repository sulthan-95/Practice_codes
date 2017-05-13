#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
#include<ctype.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,l=0,c=0,i=0,j=0;
    char a[1000],b[1000];
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        l=strlen(b);
        //cout<<l<<"\n";
        for(i=0;i<l;)
        {
            //c=islower(b[i]);
			if(b[i]>=48&&b[i]<=57)
            {
                for(j=i;j<l;j++)
                    b[j]=b[j+1];
            }
            else
            	i++;
        }
        cout<<b;
        if(strcmp(a,b)==0)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<"\n";
    }
    return 0;
}

