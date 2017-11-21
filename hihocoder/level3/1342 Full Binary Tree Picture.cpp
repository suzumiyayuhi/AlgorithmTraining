#include<iostream> 
using namespace std;

int x1,y1,x2,y2;
int res,n,m;

struct node
{
	int x,y,step;
	node *left,*right;
	node(int a,int b):x(a),y(b)
	{
		left=NULL;
		right=NULL;
	}
	~node()
	{
		delete(left);
		delete(right);
	}
};

int CalStep(int hi)
{
	if(hi==1)
		return 0;
	if(hi==2)
		return 1;
	if(hi==3)
		return 2;
	return CalStep(hi-1)*2+1;
}

void CreateTree(node par,int lev)
{
	node left(par.x+par.step+1,par.y-par.step-1);
	node right(par.x+par.step+1,par.y+par.step+1);
	if(left.x>=x1 && left.y>=y1 && left.x<=x2 && left.y<=y2)
	{
		res++;
	}
		
	if(right.x>=x1 && right.y>=y1 && right.x<=x2 && right.y<=y2)
	{
		res++;
	}
		
	if(lev==n)
		return;
	left.step=par.step/2;
	right.step=left.step;
	CreateTree(left,lev+1);
	CreateTree(right,lev+1); 
}


int main()
{
	while(cin>>n>>m)
	{
		while(m--)
		{
			cin>>x1>>y1>>x2>>y2;
			res=0;
			node ro(0,0);
			if(ro.x>=x1 && ro.y>=y1 && ro.x<=x2 && ro.y<=y2)
				res++;
			ro.step=CalStep(n);
			CreateTree(ro,1);
			cout<<res<<endl;
		}
	}
}
