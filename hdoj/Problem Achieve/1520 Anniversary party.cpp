#include<iostream>
using namespace std;
int N,L,K;
struct node
{
	int employee,boss,value,ivalue,co;
	int max()
	{
		if(value>ivalue)
			return value;
		return ivalue;
	}
}tree[6001];

void dfs(int root)
{
	int emp=tree[root].employee;
	while(emp)
	{
		dfs(emp);
		tree[root].value+=tree[emp].ivalue;
		tree[root].ivalue+=tree[emp].max();
		emp=tree[emp].co;
	}
}

int main()
{
	while(cin>>N)
	{
		for(int i=1;i<=N;i++)
		{
			cin>>tree[i].value;
			tree[i].boss=tree[i].employee=tree[i].ivalue=tree[i].co=0;
		}
		while(cin>>L>>K,L+K)
		{
			tree[L].boss=K;
			tree[L].co=tree[K].employee;
			tree[K].employee=L;
		}
		for(int i=1;i<=N;i++)
		{
			if(!tree[i].boss)
			{
				dfs(i);
				cout<<tree[i].max()<<endl;
				break;
			}
		}
	}
}
