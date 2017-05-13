#include<iostream>
#include<graphics.h>
using namespace std;
#define round(a)	((int)a+0.5)
int k=0;
float xmin,ymin,xmax,ymax,arr[20],m;
void clipl(float x1,float y1,float x2,float y2)
{
	if(x2-x1)
		m=(y2-y1)/(x2-x1);
	else
		m=10000;
	if(x1>=xmin && x2>=xmin)
	{
		arr[k++]=x2;
		arr[k++]=y2;
	}
	if(x1<xmin && x2>=xmin)
	{
		arr[k++]=xmin;
		arr[k++]=y1+m*(xmin-x1);
		arr[k++]=x2;
		arr[k++]=y2;
	}
	if(x1>xmin && x2<=xmin)
	{
		arr[k++]=xmin;
		arr[k++]=y1+m*(xmin-x1);
	}
}

void clipr(float x1,float y1,float x2,float y2)
{
	if(x2-x1)
		m=(y2-y1)/(x2-x1);
	else
		m=10000;
	if(x1<=xmax && x2<=xmax)
	{
		arr[k++]=x2;
		arr[k++]=y2;
	}
	if(x1>xmax && x2<=xmax)
	{
		arr[k++]=xmax;
		arr[k++]=y1+m*(xmax-x1);
		arr[k++]=x2;
		arr[k++]=y2;
	}
	if(x1<=xmax && x2>xmax)
	{
		arr[k++]=xmax;
		arr[k++]=y1+m*(xmax-x1);
	}
}

void clipt(float x1,float y1,float x2,float y2)
{
	if(y2-y1)
		m=(x2-x1)/(y2-y1);
	else
		m=10000;
	if(y1<=ymax && y2<=ymax)
	{
		arr[k++]=x2;
		arr[k++]=y2;
	}
	if(y1>ymax && y2<=ymax)
	{
		arr[k++]=x1+m*(ymax-y1);
		arr[k++]=ymax;
		arr[k++]=x2;
		arr[k++]=y2;
	}
	if(y1<=ymax && y2>=ymax)
	{
		arr[k++]=x1+m*(ymax-y1);
		arr[k++]=ymax;
	}
}

void clipb(float x1,float y1,float x2,float y2)
{
	if(y2-y1)
		m=(x2-x1)/(y2-y1);
	else
		m=10000;
	if(y1>=ymin && y2>=ymin)
	{
		arr[k++]=x2;
		arr[k++]=y2;
	}
	if(y1<ymin && y2>=ymin)
	{
		arr[k++]=x1+m*(ymin-y1);
		arr[k++]=ymin;
		arr[k++]=x2;
		arr[k++]=y2;
	}
	if(y1>=ymin && y2<=ymin)
	{
		arr[k++]=x1+m*(ymin-y1);
		arr[k++]=ymin;
	}
}

int main()
{
	int gd,gm,n,poly[20];
	float polyy[20];
	cout<<"\Enter the Clipping Windows:";
	cin>>xmin>>ymin>>xmax>>ymax;
	cout<<"\nEnter the no.of sides..";
	cin>>n;
	cout<<"\nEnter the sides of polygon";
	for(int i=0;i<2*n;i++)
		cin>>polyy[i];
	polyy[i]=polyy[0];
	polyy[i+1]=polyy[1];
	for(int i=0;i<2*n+2;i++)
		poly[i]=round(polyy[i])
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	setcolor(RED);
	rectangle(xmin,ymin,xmax,ymax);
	cout<<"\nUNCLIPPED POLYGON";
	setcolor(BLUE);
	fillpoly(n,poly);
	getch();
	cleardevice();
	k=0;
	for(int i=0;i<2*n;i+=2)
		clipl(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	n=k/2;
	for(int i=0;i<k;i++)
		polyy[i]=arr[i];
	polyy[i]=polyy[0];
	polyy[i+1]=polyy[1];
	k=0;
	for(int i=0;i<2*n;i+=2)
		clipt(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	n=k/2;
	for(int i=0;i<k;i++)
		polyy[i]=arr[i];
	polyy[i]=polyy[0];
	polyy[i+1]=polyy[1];
	k=0;
	for(int i=0;i<2*n;i+=2)
		clipr(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	n=k/2;
	for(int i=0;i<k;i++)
		polyy[i]=arr[i];
	polyy[i]=polyy[0];
	polyy[i+1]=polyy[1];
	k=0;
	for(int i=0;i<2*n;i+=2)
		clipb(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	for(int i=0;i<k;i++)
		poly[i]=round(arr[i])
	if(k)
		fillpoly(k/2,poly);
	getch();
	return 0;
}
