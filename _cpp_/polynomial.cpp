#include<iostream>
using  namespace std;
struct poly{
	float coef;
	int exp;
	poly *next;
};
void pinsert(poly **q,float c,int e)
{
	poly *p=new poly;
	p->coef=c;
	p->exp=e;
	p->next=NULL;
	if(*q==NULL)
	{
		*q=p;
	}
	else if((*q)->exp<p->exp)
	{
		p->next=*q;
		*q=p;
	}
	else
	{
		poly *l=*q;
		while(l!=NULL&&l->next->exp>p->exp)
			l=l->next;
		p->next=l->next;
		l->next=p;
	}
}
poly *add(poly **q,poly **r)
{
	poly *t=*q,*t1=*r,*a=NULL;
	while(t!=NULL&&t1!=NULL)
	{
		if(t->exp==t1->exp)
		{
			float x=t->coef+t1->coef;
			pinsert(&a,x,t->exp);
		}
		else if(t->exp<t1->exp)
			pinsert(&a,t1->coef,t1->exp);
		else 
			pinsert(&a,t->coef,t->exp);
		t=t->next;
		t1=t1->next;
	}
	while(t!=NULL)
	{	
		pinsert(&a,t->coef,t->exp);
		t=t->next;
	}
	while(t1!=NULL)
	{
		pinsert(&a,t1->coef,t1->exp);
		t1=t1->next;
	}
	return a;
}
poly *multiply(poly **a,poly **b)
{
	poly *t=*a,*t1=*b,*c=NULL,*mul=NULL;
	for(;t!=NULL;t=t->next)
	{
		for(;t1!=NULL;t1=t1->next)
		{
			pinsert(&c,(t->coef)*(t1->coef),t->exp+t1->exp);
		}
		mul=add(&mul,&c);
	}
	return mul;
}
void print(poly **q)
{
	poly *a=*q;
	cout<<"\nPolynomial is \n";
	while(a!=NULL)
	{
		cout<<a->coef<<"X"<<a->exp<<"+";
		a=a->next;
	}
}
int main()
{
	poly *r=NULL,*s=NULL,*su=NULL,*mu=NULL;
	int b=1;
	float a=1;
	r->next=NULL;
	s->next=NULL;
	while(a!=0)
	{
		cout<<"\nEnter the coeff and expo of A/B";
		cin>>a>>b;
		pinsert(&r,a,b);
	}
	a=1;
	b=1;
	while(a!=0)
	{
		cout<<"\nEnter the coeff and expo of A/B";
		cin>>a>>b;
		pinsert(&s,a,b);
	}
	su=add(&r,&s);
	mu=multiply(&r,&s);
	print(&r);
}
