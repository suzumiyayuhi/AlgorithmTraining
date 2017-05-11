#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n,n)
	{
		long long ans;
		long long tar[n],res[n];
		for(int i=0;i!=n;i++)
		{
			cin>>tar[i];
			res[i]=tar[i];
		}
		ans=res[0];
		for(int i=1;i!=n;i++)
		{
			if(tar[i]>tar[i-1])
				res[i]=max(res[i],res[i-1]+tar[i]);
			ans=max(ans,res[i]);
		}
		ans=max(ans,res[n-1]);
		cout<<ans<<endl;
	}
}
