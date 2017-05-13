#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
	struct node *nextleft;
};
void connectleft(struct node *n);
struct node *newnode(int data)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	n->nextleft=NULL;
	return n;
}
void connect(struct node *n)
{
	if(n!=NULL)
	{	
		n->nextleft=NULL;
		connectleft(n);
	}
	return;
}
struct node *getnextleft(struct node *n)
{
	struct node *temp=n->nextleft;
	while(!temp)
	{
		if(temp->right)
			return temp->right;
		if(temp->left)
			return temp->left;
		temp=temp->nextleft;
	}
	return NULL;
}
void connectleft(struct node *n)
{
	if(!n)
		return;
	if(n->nextleft)
		connectleft(n->nextleft);
	if(n->right)
	{
		if(n->left)
		{
			n->right->nextleft=n->left;
			n->left->nextleft=getnextleft(n);
		}
		else
			n->right->nextleft=getnextleft(n);
		connectleft(n->right);
	}
	else if(n->left)
	{
		n->left->nextleft=getnextleft(n);
		connectleft(n->left);
	}
	else
		connectleft(getnextleft(n));
}
int main()
{
 
    /* Constructed binary tree is
              10
            /   \
          8      2
        /         \
      3            90
    */
    struct node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->right->right       = newnode(90);
 
    // Populates nextRight pointer in all nodes
    connect(root);
 
    // Let us check the values of nextRight pointers
    printf("Following are populated nextleft pointers in the tree "
           "(-1 is printed if there is no nextleft) \n");
    printf("nextLeft of %d is %d \n", root->data,
           root->nextleft? root->nextleft->data: -1);
    printf("nextLeft of %d is %d \n", root->left->data,
           root->left->nextleft? root->left->nextleft->data: -1);
    printf("nextLeft of %d is %d \n", root->right->data,
           root->right->nextleft? root->right->nextleft->data: -1);
    printf("nextLeft of %d is %d \n", root->left->left->data,
           root->left->left->nextleft? root->left->left->nextleft->data: -1);
    printf("nextLeft of %d is %d \n", root->right->right->data,
           root->right->right->nextleft? root->right->right->nextleft->data: -1);
 
    getchar();
    return 0;
}
