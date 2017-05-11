#include<iostream>
using namespace std;
const int maxn = 1005;
int tar[maxn];
int res[maxn];
int main()
{
    int n;
    while(cin>>n,n)
	{
        for(int i = 1; i<=n; i++) 
			cin>>tar[i];
        memset(res,0,sizeof(res));
        int ans = 0;
        for(int i = 1; i<=n; i++)
		{
                res[i] = tar[i];
            for(int j = 1; j<=i; j++)
			{
                if(tar[i]>res[j])
				{
                    res[i] = max(res[i],res[j]+tar[i]);
                }
            }
            ans = max(ans,res[i]);
        }
        cout<<ans<<endl
    }
}

