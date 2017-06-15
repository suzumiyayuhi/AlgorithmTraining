#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
const int MAXN=33;
int z1[MAXN];
long long f1(int a,int b,int c)
{
	for(int i=MAXN-1;c>b||c<a;i--)
	{
		if(z1[i]==0)
			z1[i]=1,c++;
	}
	long long res=0;
	for(int i=MAXN-1;i!=-1;i--)
	{
		if(z1[i]==1)
			res+=pow(2,MAXN-i+1);
	}
	return res;
}

int main()
{
	int x,y=0;
	cin>>x;
	while(x--)
	{
		y++;
		cout<<"Case #"<<y<<": ";
		long long A,B,s1,s2,res=0;
		int c1=0,c2=0;
		memset(z1,0,sizeof(z1));
		cin>>A>>s1>>s2;
		A++;
		res=B=A;
		
		while(A)
		{
			if(A%2==1)
				c1++;
			A=A>>1;
		}

		for(int i=MAXN-1;i!=-1;i--)
		{
			if(B&1)
				z1[i]=1,c2++;
			else
				z1[i]=0;
			B/=2;
		}

		if(c1>s2)
		{
			int i=0;
			for(;z1[i]==0;i++);
			if(MAXN-i-1<s2)
			{
				z1[i+1]=1;
				for(int j=MAXN-1;j!=i+1;j--)
					z1[j]==0;
				c1=1;
				res=f1(s1,s2,c1);
			}
			else 
				res=f1(s1,s2,c1);
		}
		else if(c1<s1)
		{
			res=f1(s1,s2,c1);
		}
		cout<<res<<endl;
	}
}
