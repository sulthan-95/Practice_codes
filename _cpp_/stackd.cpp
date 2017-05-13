#include<iostream>
using namespace std;
class stack
{
    int *s;
    int cap;
    int top;
    public:
            stack(int a=6);
            void push(int);
            t pop();
            bool isempty();
            bool isfull();
            int peep(int);
            void display();
            friend void doublesize(stack,stack);
};
stack::stack(int a=6)
{
    cap=a;
    top=-1;
    s=new int[cap];

}
bool stack::isempty()
{

    if(top==-1)
         return 1;
    else
         return 0;
}
bool stack::isfull()
{
    if(top=cap-1)
        return 1;
    else
        return 0;

}

void stack::push(int x)
{
    if(!isempty())
    {
    top++;
    s[top]=x;
    }
}
int stack::pop()
{
    if(!isfull())
    {

        return st[top--];
    }
}

int stack::peep(int i)
{
    if(!isempty())
        return st[i];
    else
        cout<<"\n the stack is empty";
}
void stack::doublesize(stack os,stack ns)
{

    ns.capacity=os.capacity*2;
    ns.s=new int[ns .capacity];
    std::copy(os.s,os.s+os.cap-1,ns.s);
    ns.top=os.top;
}
void stack::display()
{
    cout<<"stack";
    for(int i=0;i<=top;i++)
        cout<<st[i];

}
main()
{

    stack a [5],b[5];
    a.push(7);
    a.push(8);
    a.push(9);
    a.pop();
    double size(a,b);

}
