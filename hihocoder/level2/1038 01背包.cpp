#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=501;
const int MAXM=100001;
int f[MAXN][MAXM],weight[MAXN],value[MAXN];
int N,M;

int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		cin>>weight[i]>>value[i];
	memset(f,0,sizeof(f));
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(weight[i]<=j)
				f[i][j]=max(f[i-1][j],f[i-1][j-weight[i]]+value[i]);
			else
				f[i][j]=f[i-1][j];
		}
	}
	cout<<f[N][M]<<endl;
}
