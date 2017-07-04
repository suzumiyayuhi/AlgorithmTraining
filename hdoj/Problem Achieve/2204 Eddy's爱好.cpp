#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int prime[18]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};//不加上61会导致精度误差使得WA
typedef long long ll;

int main()
{
	ll n,res,tem;
	while(cin>>n)
	{
		res=1;
		for(int i=0;;i++)
		{
			tem=(ll)(pow(n,1.0/prime[i]));
			if(tem<2)
				break;
			res+=tem-1;
			for(int j=i+1;;j++)
			{
				tem=(ll)pow(n,1.0/(prime[i]*prime[j]));
				if(tem<2)
					break;
				res-=tem-1;
				for(int k=j+1;;k++)
				{
					tem=(ll)pow(n,1.0/(prime[i]*prime[j]*prime[k]));
					if(tem<2)
						break;
					res+=tem-1;
				}
			}
		}
		cout<<res<<endl;
	}
} 
