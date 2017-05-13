#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;
struct node{
	int key;
	node *left;
	node *right;
	int height;
};
node *newnode(int key)
{
	node *n=new node;
	if(!n)
		return NULL;
	n->key=key;
	n->left=NULL;
	n->right=NULL;
	n->height=1;
}
int max(int a,int b)
{
	int max;
	max=(a>b)?a:b;
	return max;
}

int height(node *n)
{
	if(!n)
		return 0;
	return n->height;
}
int getbalance(node *n)
{
	if(!n)
		return 0;
	return height(n->left)-height(n->right);
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
node * rightrotate(node *y)
{
	node *x=y->left;
	node *T1=x->right;
	x->right=y;
	y->left=T1;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return x;
}
node * leftrotate(node *y)
{
	node *x=y->right;
	node *T1=x->left;
	x->left=y;
	y->right=T1;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return x;
}
struct node* insert(struct node* node, int key)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newnode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getbalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightrotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftrotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftrotate(node->left);
        return rightrotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
node * insertnonrec(node *root,int key)
{
	node *n=new node,*t=NULL,*node=NULL;
	n->key=key;
	n->left=NULL;
	n->right=NULL;
	n->height=1;
	if(!root)
	{	
		root=n;
		return root;
	}
	stack<struct node *>s;
	stack<struct node *>s1;
	s.push(root);
	s1.push(root);
	while(!s.empty())
	{
		t=s.top();
		s.pop();
		if(key<t->key)
		{
			if(t->left==NULL)
				t->left=n;
			else
			{	s.push(t->left);
				s1.push(t->left);
			}
		}
		else
		{
			if(t->right)
			{
				s.push(t->right);
				s1.push(t->right);
			}
			else
				t->right=n;	
		}
	}
	while(!s1.empty())
	{
		node=s1.top();
		s1.pop();
		    /* 2. Update height of this ancestor node */
    	node->height = max(height(node->left), height(node->right)) + 1;
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    	int balance = getbalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    	if (balance > 1 && key < node->left->key)
        	node=rightrotate(node);
 
    // Right Right Case
    	if (balance < -1 && key > node->right->key)
        	node=leftrotate(node);
 
    // Left Right Case
    	if (balance > 1 && key > node->left->key)
    	{
        	node->left =  leftrotate(node->left);
        	node=rightrotate(node);
    	}
 
    // Right Left Case
    	if (balance < -1 && key < node->right->key)
    	{
        	node->right = rightrotate(node->right);
        	node=leftrotate(node);
    	}
	}
	return root;
}
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
/*struct node* deleteNode(struct node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE
 
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left : root->right;
 
            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child
 
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            struct node* temp = minValueNode(root->right);
 
            // Copy the inorder successor's data to this node
            root->key = temp->key;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }
 
    // If the tree had only one node then return
    if (root == NULL)
      return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = max(height(root->left), height(root->right)) + 1;
 
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}*/
int main()
{
  struct node *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 8);
 root = insert(root, 9);
  root = insert(root, 16);
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);
 
  return 0;
}
