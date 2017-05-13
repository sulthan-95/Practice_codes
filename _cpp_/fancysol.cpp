#include<iostream>
using namespace std;
unsigned long a;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
  cin>>a;
  int ans = 1;
  int running = 1;
  while (a)
  {
    running *= 2;
    if (a%10 >= 2) {
      ans = running;
    } else if (a%10 == 1) {
      ans = running/2 + ans;
    }
    a /= 10;
  }
  cout<<ans-1<<endl;
    }
    return 0;
}
