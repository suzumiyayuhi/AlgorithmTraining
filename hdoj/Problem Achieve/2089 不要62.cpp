#include<iostream>
using namespace std;
int dp[10][3],bit[10];
//dp[i][j]
//长度为i;j=0代表不存在不吉利数的数量,j=1代表不存在不吉利数且最高位为2的数量,j=2代表存在的不吉利数的数量 
void init()
{
	dp[0][0]=1;
	dp[0][1]=0;
	dp[0][2]=0;
	for(int i=1;i!=10;i++)
	{
		dp[i][0]=dp[i-1][0]*9-dp[i-1][1];
		dp[i][1]=dp[i-1][0];
		dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];
	}
}

int sol(int a)
{
	int len=1,tem=a,res=0;
	while(a)
	{
		bit[len++]=a%10;
		a/=10;
	}
	bit[len]=0; 
	bool flag=true;
	for(int i=len-1;i>=1;i--)
	{
		res+=dp[i-1][2]*bit[i];
		if(!flag)
			res+=dp[i-1][0]*bit[i];
		if(flag&&bit[i]>4)
			res+=dp[i-1][0];
		if(flag&&bit[i+1]==6&&bit[i]>2)
			res+=dp[i][1];
		if(flag&&bit[i]>6)
			res+=dp[i-1][1];
		if(bit[i]==4||(bit[i+1]==6&&bit[i]==2))
			flag=false;
	}
	if(!flag)
		res++;
	return tem-res;
}

int main()
{
	init();
	int m,n;
	while(cin>>m>>n,m+n)
		cout<<sol(n)-sol(m-1)<<endl;
} 
