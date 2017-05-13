#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
struct bintree{
	int data;
	bintree *left;
	bintree *right;
}typedef node;
node *insert(node *root,int val)
{
	node *r=NULL,*s=NULL;
	queue<node *>q;
	s=new node;
	if(!s){
		cout<<"\nMem err";
		return root;
	}
	s->data=val;
	s-left=NULL;
	s->right=NULL;
	if(!root)
	{
		root=s;
		return root;
	}
	q.push(root);
	while(!q.empty())
	{
		r=q.front();
		if(r->left)
			q.push(r->left);
		else
		{
			r->left=s;
			return root;
		}
		q.pop();
		if(r->right)
			q.push(r->right);
		else 
		{
			r->right=s;
			return root;
		}	
	}
}
