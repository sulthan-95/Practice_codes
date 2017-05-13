#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
using namespace std;
template<class t>
class stack
{
	t* stck;
	int top;
	int capacity;
	public:
		stack();
		~stack();
		void display() const;
		void push(t);
		t& rettop() const;
		t pop();
		bool isfull();
		bool isempty();
};
template<class t>
stack<t>::stack()
{
	capacity=MAX;
	stck=new t[capacity];
	top=-1;
}
template<class t>
stack<t>::~stack()
{
	delete[] stck;
	top=-1;
}
template<class t>
bool stack<t>::isfull()
{
	if(top==capacity-1)
		return 1;
	return 0;
}
template<class t>
bool stack<t>::isempty()
{
	if(top==-1)
		return 1;
	return 0;
}
template<class t>
void stack<t>::push(t x)
{
	if(isfull())
		cout<<"\nOVERFLOW!!!";
	else
	{
		top++;
		stck[top]=x;
	}
}
template<class t>
t stack<t>::pop()
{
	t x;
	if(isempty())
		cout<<"\nUnderflow!!!\nNo elements left ";
	else
	{
		x=stck[top];
		top--;
		return x;
	}
}
template<class t>	
t& stack<t>::rettop() const
{
		return stck[top];
}
template<class t>
void stack<t>::display() const
{
	for(int i=0;i<=top;i++)
		cout<<stck[i]<<" ";
}
int priority(char x)
{
   if(x == '(')
 return(0);
   if(x == '+' || x == '-')
 return(1);
   if(x == '*' || x == '/' || x == '%')
 return(2);
   return(3);
}
int eval(char z[],int l)
{
	int x,y;
	stack<int> s1;
	int i=0,j,k;
	while(i<=l)
	{
		if(z[i]>='0'&&z[i]<='9')
		{
			s1.push((int)(z[i]-48));
			i++;
			continue;
		}
		else if(z[i]=='+'||z[i]=='-'||z[i]=='/'||z[i]=='*'||z[i]=='%')
		{
			y=s1.pop();
			x=s1.pop();
			if(z[i]=='+')
			{
				k=x+y;
				s1.push(k);
				i++;
				continue;
			}
			else if(z[i]=='-')
			{
				k=x-y;
				s1.push(k);
				i++;
				continue;
			}
			else if(z[i]=='*')
			{
				k=x*y;
				s1.push(k);
				i++;
				continue;
			}
			else if(z[i]=='%')
			{
				k=x%y;
				s1.push(k);
				i++;
				continue;
			}
			else if(z[i]=='/')
			{
				k=x/y;
				s1.push(k);
				i++;
				continue;
			}
		}
	}
	x=s1.pop();
	return x;
}
int main()
{
	stack<char> s;
	int i,j=-1;
	char x;
	char y[100],z[100];
	cout<<"Enter Infix Expression [End with dot] (With Brackets) ";
	gets(y);
	for(i=0;y[i]!='.';i++)
	{
		if(isalnum(y[i]))
		{
			j++;
			z[j]=y[i];
		}
		else if(y[i]=='(')
			s.push('(');
		else
		{
			if(y[i]==')')
				while((x=s.pop())!='(')
             	{
             		j++;
             		z[j]=x;
				}
        	else
        	{
         		while(priority(y[i])<=priority(s.rettop())&&!(s.isempty()))
             	{
             		x=s.pop();
             		j++;
             		z[j]=x;
             	}
         	s.push(y[i]);
         	}				
		}
	}
	while(!s.isempty())
	{
		x=s.pop();
		j++;
		z[j]=x;
	}
	i=eval(z,j);
	cout<<"The answer to the expression is "<<i;
}
