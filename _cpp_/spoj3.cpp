#include<iostream>
using namespace std;
int palindrome(long j){
    long r=0,num=0,k=j;
    while(k!=0)
    {
        r=k%10;
        num=num*10+r;
        k/=10;
    }
    if(num==j)
        return 1;
    else
        return 0;
}
int main()
{
    int t,n,c=0;
    cin>>t;
    while(t--)
    {
        c=0;
        cin>>n;
        while(c==0)
            c=palindrome(++n);
        cout<<n<<"\n";
    }
    return 0;
}
