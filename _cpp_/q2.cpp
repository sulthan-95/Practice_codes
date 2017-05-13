//Find the Logic of the code and explain how it works..
#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
int func4(int var1,int var2){
	return var1+(var2-var1)/2;
}
int func5(int var1,int var2)
{
	if(var1<var2)
		return var1;
	else
		return var2;
}
void func6(int var1[],int var2,int var3,int *var4,int var5)
{
	if(var2==var3)
	{
		var4[var5]=var1[var2];
		return;
	}
	int var6=func4(var2,var3);
	func6(var1,var2,var6,var4,2*var5+1);
	func6(var1,var6+1,var3,var4,2*var5+2);
	var4[var5]=func5(var4[2*var5+1],func5(var4[2*var5+2],var4[2*var5+1]+var4[2*var5+2]));
}
int * func1(int var1[],int var2)
{
	int var3=(int)ceil(log2(var2));
	var3=2*(int)pow(2,var3)-1;
	int *var4=new int[var3];
	func6(var1,0,var2-1,var4,0);
	return var4;
}
int func3(int *var1,int var2,int var3,int var4,int var5[],int var6,int var7)
{
	if(var6>var4 || var7<var3)
		return 99999;
	if(var6<=var3 && var7>=var4)
		return var1[var2];
	int var8=func3(var1,2*var2+1,var3,func4(var3,var4),var5,var6,var7);
	int var9=func3(var1,2*var2+2,func4(var3,var4)+1,var4,var5,var6,var7);
	if(var8<var9)
		return var8;
	else
		return var9;
}
void func2(int *var1,int var2,int var3,int var4[],int var5,int var6,int var7)
{
	if(var5<var2 || var5>var3)
		return;
	if(var2==var3)
	{
		var4[var2]=var6;
		var1[var7]=var4[var2];
		return;
	}
	func2(var1,var2,func4(var2,var3),var4,var5,var6,2*var7+1);
	func2(var1,func4(var2,var3)+1,var3,var4,var5,var6,2*var7+2);
	var1[var7]=func5(var1[2*var7+1],func5(var1[2*var7+2],var1[2*var7+1]+var1[2*var7+2]));
}
int main()
{
	int var1,var2,var3;
	cin>>var1;
	while(var1--)
	{
		cin>>var2;
		int *var4=new int[var2];
		for(int i=0;i<var2;i++)
			cin>>var4[i];
		int *var5=func1(var4,var2);
		int var6=(int)ceil(log2(var2));
		var6=2*(int)pow(2,var6)-1;
		cin>>var3;
		while(var3--)
		{
			int var7,var8,var9;
			cin>>var9>>var7>>var8;
			if(var9==0)
			{
				func2(var5,0,var2-1,var4,var7-1,var8,0);
			}
			else if(var9==1)
			{
				cout<<func3(var5,0,0,var2-1,var4,var7-1,var8-1)<<endl;
			}
		}
	}
}
