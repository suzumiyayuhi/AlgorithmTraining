#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1000001;
int n,m;
int weight[MAXN],value[MAXN],f[MAXN];

int main()
{
	cin>>n>>m;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		cin>>weight[i]>>value[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
			if(weight[i]<=j)
				f[j]=max(f[j],f[j-weight[i]]+value[i]);
	}
	cout<<f[m]<<endl;
}
