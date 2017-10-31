#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
const int MAXN=101;
const int MAXM=601;
int n,m;
double f[MAXN][MAXM];//注意double类型，long long大小也不够 

void table()
{
	f[1][1]=1;f[1][2]=1;f[1][3]=1;
	f[1][4]=1;f[1][5]=1;f[1][6]=1;
	for(int i=2;i<MAXN;i++)
	{
		int tar=i*6;
		for(int j=i;j<=tar;j++)
		{
			int flag1=j,flag2=0;
			double tem=0.0;//注意tem的数据类型，理由同上 
			while(--flag1&&flag2<6)
			{
				tem+=f[i-1][flag1];
				flag2++;
			}
			f[i][j]=tem;
		}
	}
}

int main()
{
	table();
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		double nume=pow(6,m);
		double res=f[m][n]/nume;
		printf("%.2f\n",res*100);
	}
}
