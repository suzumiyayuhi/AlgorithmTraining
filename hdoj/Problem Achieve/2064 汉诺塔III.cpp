#include<iostream>
using namespace std;
int main()
{
	long long dp[36];
	int n;
	dp[1]=2;
	for(int i=2;i!=36;i++)
		dp[i]=3*dp[i-1]+2;
	while(cin>>n)
		cout<<dp[n]<<endl;
}
