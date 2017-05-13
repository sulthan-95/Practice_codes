#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct bintree
{
    int data;
    bintree *left;
    bintree *right;
}typedef node;
void insertnode(node **root,int val)
{
    node *temp=NULL;
    if(*root==NULL)
    {
        temp=new node;
        temp->left=temp->right=NULL;
        temp->data=val;
        *root=temp;
        return;
    }
    if(val<(*root)->data){insertnode(&(*root)->left,val);}
    else{insertnode(&(*root)->right,val);}
}
void preorder(node *r)
{
    if(r==NULL){return;}
        cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
}
void postorder(node *r)
{
    if(r==NULL){return;}
    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}
void inorder(node *r)
{
    if(r==NULL){return;}
    inorder(r->left);
    cout<<r->data;
    inorder(r->right);
}
bool search(node *root,int val)
{
	if(!root)
		return false;
	if(root->data==val)
		return true;
	else if(val<root->data)
		return search(root->left,val);
	else
		return search(root->right,val);
}
node *find_min(node *root)
{
	node *r1=root;
	if(!root)
	{
		cout<<"\nNo root";
		return root;
	}
	while(root->left)
	{
		root=root->left;
	}
	return root;
}
node *find_max(node *root)
{
	if(!root)
	{	
		cout<<"No root";
		return root;
	}
	while(root->right)
	{
		root=root->right;
	}
	return root;
}
node *delet(node *root,int val)
{
	node *temp=NULL;
	if(!root)
		return root;
	else if(val<root->data)
		delet(root->left,val);
	else if(val>root->data)
		delet(root->right,val);
	else
	{
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		else if(root->left==NULL)
		{
			temp=root;
			root=root->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
				temp=root;
				root=root->left;
				delete temp;
		}
		else
		{
			temp=find_min(root->right);
			root->data=temp->data;
			root->right=delet(root->right,temp->data);
			delete temp;
		}
	}
	return root;
}
main()
{
    node *tree;
    insertnode(&tree,5);
    insertnode(&tree,3);
    insertnode(&tree,9);
    preorder(tree);
    return 0;
}
