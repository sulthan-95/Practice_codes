#include<iostream>
using namespace std;
template<class T>
class stack{
	T *ptr;
	int top,size;
	public:
		stack(int=0);
		~stack();
		void push(T);
		T pop();
		void peep();
};
template<class T>
stack<T>::stack(int s)
{
	size=s;
	ptr=new T[size];
}
template<class T>
stack<T>::~stack()
{
	cout<<"\nDestructor..";
	delete ptr;
}
template<class T>
void stack<T>::push(T x)
{
	if(top!=size)
		ptr[++top]=x;
}
template<class T>
T stack<T>::pop()
{
	if(top!=0)
		return ptr[top--];
}
template<class T>
void stack<T>::peep()
{
	int temp=top;
	while(temp!=0)
		cout<<ptr[temp--];
}
int main()
{
	stack<int>s;
	s.push(3);
	stack<char>s1(3);
	s1.push('a');
	s1.push('b');
	cout<<s1.pop();
	s1.peep();
	return 0;
}
