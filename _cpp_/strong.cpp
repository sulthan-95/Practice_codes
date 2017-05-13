#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string *s=new string[n];
        string s1;
        long long int max=-99999,weight=0;
        for(int i=0;i<n;i++)
            cin>>s[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<s[i].length();j++)
            {
                if(s[i][j]>='a' && s[i][j]<='z')
                {
                    weight+=s[i][j]-96;
                }
                else(s[i][j]>='A' && s[i][j]<='Z')
                    weight+=64-s[i][j];
            }
            if(weight>max)
            {
                weight=max;
                s1=s[i];
            }
        }
        cout<<s1<<endl;
    }
    return 0;
}

