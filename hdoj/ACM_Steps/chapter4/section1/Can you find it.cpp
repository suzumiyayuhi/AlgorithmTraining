#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int sum[505*505];
int main()
{
	int L,N,M,nnn=0;
	while(cin>>L>>N>>M)
	{
		int an[L],bn[N],cn[M],tem;
		for(int i=0;i!=L;i++)
			cin>>an[i];
		for(int i=0;i!=N;i++)
			cin>>bn[i];
		for(int i=0;i!=M;i++)
			cin>>cn[i];
		
		int k=0;
		for(int i=0;i!=L;i++)
			for(int j=0;j!=N;j++)
				sum[k++]=an[i]+bn[j];
		sort(sum,sum+k);
		
		int z;
		cin>>z;
		cout<<"Case "<<++nnn<<":"<<endl;
		while(z--)
		{
			bool flag;
			int X;
			cin>>X;
			for(int i=0;i!=M;i++)
			{
				int left=0,right=k-1,Y=X-cn[i],mid;
				flag=false;
				while(left<=right)
				{
					mid=(left+right)>>1;
					if(sum[mid]>Y)
						right=mid-1;
					else if(sum[mid]<Y)
						left=mid+1;
					else
						{
							flag=true;
							break;
						}
				}
				if(flag)
					break;
			}
			if(!flag)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
	}
} 
