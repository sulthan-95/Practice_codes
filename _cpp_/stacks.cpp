#include<iostream>
using namespace std;
class stack
{
    int *s;
    int cap;
    int top;
    public:
            stack(int=5);
            void push(int);
            int pop();
            bool isempty();
            bool isfull();
            int peep(int);
            void display();
            void doublesize(stack &);
};
stack::stack(int a)
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
    if(top==cap-1)
        return 1;
    else
        return 0;

}

void stack::push(int x)
{
    if(!isfull())
    {
    s[++top]=x;
    }
}
int stack::pop()
{
    if(!isempty())
    {

        return s[top--];
    }
}

int stack::peep(int i)
{
    if(!isempty())
        return s[i];
    else
        cout<<"\n the stack is empty";
}
void stack::doublesize(stack &ns)
{

    ns.cap=cap*2;
    ns.s=new int[ns.cap];
    std::copy(s,s+cap,ns.s);
    ns.top=top;
    delete[] s;
}
void stack::display()
{
    cout<<"stack";
    for(int i=0;i<=top;i++)
        cout<<peep(i);

}
int main()
{

    stack b;
    stack a(5);
    a.push(7);
    a.push(8);
    a.push(9);
    a.display();
    a.pop();
    a.display();
    a.doublesize(b);
    b.display();
    return 0;

}
