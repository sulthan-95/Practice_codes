#include<iostream>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
struct Node{
	char data;
	unsigned freq;
	Node *left;
	Node *right;
	 
	Node(char d,unsigned f)
	{
		data=d;
		freq=f;
		left=right=NULL;
	}
};
struct compare{
	bool operator()(Node *l,Node *r){
		return l->freq >= r->freq;			//compare(l,r);
	}
};


void codes(Node *root,string str)
{
	if(!root)
		return;
	if(root->data != '$')
		cout<<root->data<<":"<<str<<endl;
	codes(root->left,str+"0");
	codes(root->right,str+"1");
}

void buildtree(int freq[26])
{
	Node *head,*left,*right;
	priority_queue<Node *,vector<Node *>,compare> minheap;
	for(int i=0;i<26;i++)
	{
		if(freq[i]!=0)
			minheap.push(new Node((char)(i+97),freq[i]));
	}
	while(minheap.size()!=1)
	{
		left=minheap.top();
		minheap.pop();
		right=minheap.top();
		minheap.pop();
		head=new Node('$',left->freq+right->freq);
		head->left=left;
		head->right=right;
		minheap.push(head);
	}
	codes(minheap.top(),"");
}
		
int main()
{
	string str;
	int freq[26];
	for(int i=0;i<26;i++)
		freq[i]=0;
	cout<<"Enter a string\n";
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		int index=str[i]-97;
		freq[index]+=1;
	}
	buildtree(freq);
	return 0;
}
