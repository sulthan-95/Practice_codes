#include<iostream>
#include<stdlib.h>
using namespace std;
int &fun()
{
	static int x=10;
	return x;
}
int fuo(const int &x)
{
	return x;
}
void swap(char *&str1,char *&str2)
{
	char *temp=str1;
	str1=str2;
	str2=temp;
}
int main()
{
	fun()=30;
	char *str1=new ["GEEKS"];
	char *str2=new ["FOR GEEKS"];
	swap(str1,str2);
	cout<<fun()<<endl;
	cout<<fuo(10)<<endl;
	cout<<"str1 is"<<str1<<"\nstr2 is:"<<str2;
	return 0;
}
