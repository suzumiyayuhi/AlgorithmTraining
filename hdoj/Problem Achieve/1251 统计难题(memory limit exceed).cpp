#include<string.h>
#include<cstdio>
using namespace std;
struct node
{
	node *next[26];
	int cnt;
	node()
	{
		cnt=0;
		memset(next,0,sizeof(next));
	}
};

void join(node *root,char word[])
{
	node *p=root;
	int index,len=0;
	while(word[len])
	{
		index=word[len++]-'a';
		if(p->next[index]==NULL)
			p->next[index]=new node();
		p=p->next[index];
		p->cnt++;
	}
}

int search(node *root,char word[])
{
	int len=0,index;
	node *p=root;
	while(word[len])
	{
		index=word[len++]-'a';
		p=p->next[index];
		if(p==NULL)
			return 0;
	}
	return p->cnt;
}

int main()
{
	char word[11];
	node *root=new node();
	while(gets(word)&&word[0]!='\0')
		join(root,word);
	while(gets(word))
		printf("%d\n",search(root,word));
}
