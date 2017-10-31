#include<iostream>
#include<algorithm> 
using namespace std;
const int MAXN=1001;
int N,res;
int A[MAXN],sum[MAXN][MAXN],f[MAXN][MAXN];

int sol()
{
	for(int i=1;i<=N;i++)
		f[i][i]=A[i];
	for(int i=1;i!=N;i++)
	{
		int left=N-i,right=N;
		while(left!=0)
		{
			f[left][right]=max(sum[left][right]-f[left+1][right],sum[left][right]-f[left][right-1]);
			left--;right--;
		}
	}
	return f[1][N];
}

int main()
{
	while(cin>>N)
	{
		res=0;
		cin>>A[1];
		for(int i=2;i<=N;i++)
			cin>>A[i];
		for(int i=1;i<=N;i++)
		{
			sum[i][i]=A[i];
			for(int j=i+1;j<=N;j++)
				sum[i][j]=sum[i][j-1]+A[j];
		}
		cout<<sol()<<endl;
	}
}
