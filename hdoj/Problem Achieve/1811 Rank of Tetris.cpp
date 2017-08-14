#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
const int MAXN=20002;
char oper[MAXN];
int sa[MAXN],sb[MAXN],parent[MAXN],lit[MAXN];//lit用来记录比其小的元素个数 
int n,m,sum;//sum为元素个数 
vector<int> big[MAXN];//big用来记录比其大的元素个数 
bool flag;

int get_parent(int a)
{
	while(parent[a]!=a)
		a=parent[a];
	return a; 
}

bool merge(int a,int b)
{
	int x=get_parent(a);
	int y=get_parent(b);
	if(x==y)
		return false;
	parent[y]=x;
	return true;
}

void top_order()
{
	flag=false;
	queue<int> q;
	for(int i=0;i<n;i++)
		if(lit[i]==0&&i==get_parent(i))
			q.push(i);
	while(!q.empty())
	{
		if(q.size()>1)
			flag=true;
		int cur=q.front();
		q.pop();
		sum--;
		for(int i=0;i<big[cur].size();i++)
		{
			if(--lit[big[cur][i]]==0)
				q.push(big[cur][i]);
		}
	}
	if(sum>0)
		cout<<"CONFLICT"<<endl;
	else if(flag)
		cout<<"UNCERTAIN"<<endl;
	else
		cout<<"OK"<<endl;
}

int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			big[i].clear();
			parent[i]=i;
			lit[i]=0;
		}
		sum=n;
		//并查集部分 
		for(int i=0;i<m;i++)
		{
			cin>>sa[i]>>oper[i]>>sb[i];
			if(oper[i]=='=')
				if(merge(sa[i],sb[i]))
					sum--;
		}
		//拓补排序部分 
		for(int i=0;i<m;i++)
		{
			if(oper[i]=='=')
				continue;
			int x=get_parent(sa[i]);
			int y=get_parent(sb[i]);
			if(oper[i]=='>')
			{
				big[x].push_back(y);
				lit[y]++;
			}
			else
			{
				big[y].push_back(x);
				lit[x]++;
			}
		}
		top_order();
	}
}
