#include<iostream>
#include<stdlib.h>
using namespace std;
int pk[10]={0};
class Check{
	int &n;
	int &cnt;
	public:
	Check(int k,int c):n(k),cnt(c)
	{}
	void change()
	{
		for(int i=0;i<cnt;i++){
			&n=i;
			*(&cnt+i)=i;
		}
	}
};
int main()
{
	Check a(pk[0],pk[1]);
	a.change();
	for(int i=0;i<10;i++)
		cout<<pk[i];
	cout<<endl;
	return 0;
}
