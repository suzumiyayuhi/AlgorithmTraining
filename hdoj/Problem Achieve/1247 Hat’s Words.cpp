#include<iostream>
#include<string.h>
using namespace std;
char words[50001][30];

struct node
{
	bool flag;
	node *next[26];
	node()
	{
		flag=false;
		memset(next,0,sizeof(next));
	}
};

void join(node *root,char word[])
{
	int len=0;
	node *p=root;
	while(word[len])
	{
		int tem=word[len++]-'a';
		if(p->next[tem]==NULL)
			p->next[tem]=new node();
		p=p->next[tem];
	}
	p->flag=true;
}

bool search(node *root,char word[])
{
	int index=0,len=0,stack[1005];
	node *p=root;
	while(word[index])//记录索引 
	{
		
		int tem=word[index++]-'a';
		p=p->next[tem];		
		if(p->flag&&word[index])
		if(p->flag)
			stack[len++]=index;
	}
	while(len)//遍历索引 
	{
		bool e=false;
		index=stack[--len];
		p=root;
		while(word[index])
		{
			int tem=word[index++]-'a';
			if(p->next[tem]==NULL)
			{
				e=true;
				break;
			}
			p=p->next[tem];
		}
		if(!e&&p->flag)
			return true;
	}
	return false;
}

int main()
{
	int i=0;
	node *root=new node();
	while(cin>>words[i])
	{
		join(root,words[i]);
		i++;
	}
	for(int j=0;j!=i;j++)
		if(search(root,words[j]))
			cout<<words[j]<<endl;
}
