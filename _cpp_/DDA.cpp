#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#define round(a)	((int)a+0.5)
using namespace std;
float xmin,ymin,xmax,ymax,u1,u2,r1,r2,r3,r4;
int p1,p2,p3,p4,q1,q2,q3,q4;
void lineDDA(int x1,int y1,int x2,int y2)
{
	int dx=x2-x1,dy=y2-y1;
	float m,xi,yi;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xi=abs(dx)/steps;
	yi=abs(dy)/steps;
	if(dx!=0)
		m=dy/dx;
	if(x1>x2)
	{
		x=x2;
		y=y2;
	}
	else
	{
		x=x1;
		y=y1;
	}
	putpixel(round(x),round(y),0);
	if((int)m>=0)
	{
		for(int k=0;k<steps;k++)
		{
			x=x+xi;
			y=y+yi;
			putpixel(round(x),round(y),0);
		}
	}
	else
	{
		for(int k=0;k<steps;k++)
		{
			x=x+xi;
			y=y-yi;
			putpixel(round(x),round(y),0);
		}
	}	
}
void clip(int x1,int y1,int x2,int y2)
{
	int x11,y11,x22,y22;
	p1=p2=p3=p4=q1=q2=q3=q4=0;
	p1=-(x2-x1);
	p2=x2-x1;
	p3=-(y2-y1);
	p4=y2-y1;
	q1=x1-xmin;
	q2=xmax-x1;
	q3=y1-ymin;
	q4=ymax-y1;
	u1=0.0;
	u2=1.0;
	if((p1==0 && q1<0)||(p2==0 && q2<0) || (p3==0 && q3<0) || (p4==0 && q4<0))
	{}
	else
	{
		if(p1!=0)
		{
			r1=(float)q1/p1;
			if(p1<0)
				u1=max(r1,u1);
			else
				u2=min(r1,u2);
		}
		if(p2!=0)
		{
			r2=(float)q2/p2;
			if(p2<0)
				u1=max(r2,u1);
			else
				u2=min(r2,u2);
		}
		if(p3!=0)
		{
			r3=(float)q3/p3;
			if(p3<0)
				u1=max(r3,u1);
			else
				u2=min(r3,u2);
		}
		if(p4!=0)
		{
			r4=(float)q4/p4;
			if(p4<0)
				u1=max(r4,u1);
			else
				u2=min(r4,u2);
		}				
		if(u1>u2){}
		else
		{
			x11=x1+u1*(x2-x1);
			y11=y1+u1*(y2-y1);
			x22=x1+u2*(x2-x1);
			y22=y1+u2*(y2-y1);
		}
		lineDDA(x11,y11,x22,y22);
	}
}



