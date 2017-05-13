#include<iostream>
#include<stdlib.h>
#include<cassert>
using namespace std;
template<class T>
class stack{
	T *st;
	int top;
	int capacity;
	public:
		stack(int sap=3);
		void push(T x);
		T pop();
		T peep(int s);
		bool isEmpty(){return top==-1;}
		bool isFull(){return top==capacity-1;}
		void Doublesize(stack old)
		{
			this->st=new T[old.capacity*2];
			copy(old.st,old.st+capacity-1,this->st);
			delete[] old.st;
			this->top=old.capacity;
		}
		T getmin();
};
template<class T>
stack<T>::stack(int sap)
{
	capacity=sap;
	top=-1;
	st=new T[sap];
}
template<class T>
void stack<T>::push(T x)
{
	if(!isFull())
		st[++top]=x;
}
template<class T>
T stack<T>::pop()
{
	if(!isEmpty())
		return st[top--];
}
template<class T>
T stack<T>::peep(int y)
{
	assert(!isEmpty()&&y<capacity);
	return st[y-1];
}
template<class T>
T stack<T>::getmin()
{
	T a;
	int i;
	a=st[top];
	for(i=top;i>=0;i--)
	{
		if(st[i]<a)
			a=st[i];
	}
	return a;
}
main()
{
	stack<double>s;
	s.push(15.5);
	s.push(10.3);
	s.push(12.9);
	cout<<"s.pop()="<<s.pop()<<"\nMinimum value.."<<s.getmin()<<endl;
	double t,v;
	stack<double>q;
	q.Doublesize(s);
	t=q.peep(2);
	v=q.peep(1);
	cout<<v<<"\n"<<t;
	return 0;			
}
