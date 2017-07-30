#include<iostream>
#include<queue>
#include<string>
#include<string.h>
#include<cmath>
using namespace std;
int n,k,m,km;
bool vis[1000001];
string res;

struct point
{
	int val,time;
	string str;
};

int mod(int a,int b)
{
	return (a%b+b)%b;
//	return fmod(a,b);
}

int bfs()
{
	memset(vis,false,sizeof(vis));
	queue<point> q;
	point p1,p2;
	p1.val=n;
	p1.time=0;
	p1.str="";
	q.push(p1);
	while(!q.empty())
	{
		p1=q.front();
		q.pop();
		if(mod(n+1,k)==mod(p1.val,k))
		{
			res=p1.str;
			return p1.time;
		}
		p2.time=p1.time+1;
		for(int i=0;i!=4;i++)
		{
			
			if(i==0)
			{
				p2.val=(p1.val+m)%km;
				p2.str=p1.str+'+';

			}
			else if(i==1)
			{
				p2.val=(p1.val-m)%km;
				p2.str=p1.str+'-';
			}
			else if(i==2)
			{
				p2.val=(p1.val*m)%km;
				p2.str=p1.str+'*';
			}
			else if(i==3)
			{
				p2.val=mod(p1.val,m)%km;
				p2.str=p1.str+'%';
			}
			if(!vis[mod(p2.val,k)])
			{
				q.push(p2);
				vis[mod(p2.val,k)]=true;
			}
		}
	}
	return 0;
}

int main()
{
	while(cin>>n>>k>>m,n||k||m)
	{
		km=k*m;
		int tem=bfs();
		cout<<tem<<endl;
		if(tem)
			cout<<res<<endl;
	}
		
}
