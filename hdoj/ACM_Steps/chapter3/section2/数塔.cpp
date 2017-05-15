#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int n;
		cin>>n;
		int res[n][n],tar[n][n];
		for(int i=0;i!=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				cin>>tar[i][j];
			}
		}
		for(int i=0;i!=n;i++)
		{
			res[n-1][i]=tar[n-1][i];
		}
		
		for(int i=n-2;i!=-1;i--)
		{
			for(int j=0;j<=i;j++)
			{
				res[i][j]=max(tar[i][j]+res[i+1][j],tar[i][j]+res[i+1][j+1]);
			}
		}
		cout<<res[0][0]<<endl;
	}
} 
