#include<bits/stdc++.h>
using namespace std;
#define alphabets 26
#define char_to_int(c) ((int)c-(int)'a')
struct Trie
{
	int words;
	int prefixes;
	struct Trie *children[alphabets];
};
void initialize(Trie *vertex)
{
	vertex->words=0;
	vertex->prefixes=0;
	for(int i=0;i<26;i++)
		vertex->children[i]=NULL;
}
void addword(string text,Trie **root)
{
	Trie *temp=*root;
	if(text[0]=='\0')
		temp->words+=1;
	else{
		int i=0;
		while(i<text.length())
		{
			int index=char_to_int(text[i]);
			temp->prefixes+=1;
			if(temp->children[index]==NULL)
			{
				temp->children[index]=new Trie;
				initialize(temp->children[index]);
			}
			temp=temp->children[index];
			i++;
		}
	temp->words+=1;
	}
}
int countwords(Trie **root,string word)
{
	Trie *temp=*root;
	for(int i=0;;i++)
	{
		int index=char_to_int(word[i]);
		if(word[i]=='\0')
			return temp->words;
		else if(temp->children[index]==NULL)
			return 0;
		else
			temp=temp->children[index];
	}
}
int countprefixes(Trie **root,string word)
{
	Trie *temp=*root;
	for(int i=0;;i++)
	{
		int index=char_to_int(word[i]);
		if(word[i]=='\0')
			return temp->prefixes;
		else if(temp->children[index]==NULL)
			return 0;
		else
			temp=temp->children[index];
	}
}
int main()
{
	Trie *root=new Trie;
	initialize(root);
	string word="hi",word1="hello",word2="hell";
	addword(word,&root);
	addword(word1,&root);
	addword(word2,&root);
	cout<<"H prefixes-"<<countprefixes(&root,"h");
	cout<<"\nlo-"<<countwords(&root,"lo");
	cout<<"\nhi-"<<countwords(&root,word);
	return 0;
}
