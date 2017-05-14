#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAX 1000
using namespace std;
struct block
{
	int x,y,z,maxheight;	
};

bool cmp(const block &a,const block &b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

int main()
{
	int cn=0,n;
	while(cin>>n,n)
	{
		int temn=n;
		block blocks[MAX];
		int x,y,z,i=0;
		while(n--)
		{
			cin>>x>>y>>z;
			blocks[i].x=x;blocks[i].y=y;blocks[i].z=z;blocks[i].maxheight=blocks[i].z;i++;
			blocks[i].x=y;blocks[i].y=x;blocks[i].z=z;blocks[i].maxheight=blocks[i].z;i++;
			blocks[i].x=x;blocks[i].y=z;blocks[i].z=y;blocks[i].maxheight=blocks[i].z;i++;
			blocks[i].x=z;blocks[i].y=x;blocks[i].z=y;blocks[i].maxheight=blocks[i].z;i++;
 			blocks[i].x=y;blocks[i].y=z;blocks[i].z=x;blocks[i].maxheight=blocks[i].z;i++;
			blocks[i].x=z;blocks[i].y=y;blocks[i].z=x;blocks[i].maxheight=blocks[i].z;i++;
        }
		sort(blocks,blocks+i,cmp);
		int temmax=0;
		for(int j=1;j!=i;j++)
		{
			for(int k=0;k!=j;k++)
				if(blocks[j].x>blocks[k].x&&blocks[j].y>blocks[k].y)
					blocks[j].maxheight=max(blocks[j].maxheight,blocks[k].maxheight+blocks[j].z);
			if(blocks[j].maxheight>temmax)
				temmax=blocks[j].maxheight;
		}
		cout<<"Case "<<++cn<<": maximum height = "<<temmax<<endl; 
	}
}
