#include<iostream>
using namespace std;
int main()
{
	int a=5,b=3,c=0;
	if((b==3) || (c=10))
		c+=100;
	cout<<c<<endl;
	if((b==2)||(c+=1000))
		c+=2000;
	cout<<c<<endl;
	if(((a==4) && (c=50))||(c+=1500))
		c+=1500;	
	cout<<c<<endl;
	return 0;
}
