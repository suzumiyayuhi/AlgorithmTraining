#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,n1=0;
	cin>>n;
	while(n--)
	{
		int N;
		cin>>N;
		int tar[N],res[N],tem[N];
		for(int i=0;i!=N;i++)
		{
			cin>>tar[i];
		}
		cout<<"Case "<<++n1<<":"<<endl;
		res[0]=tar[0];
		tem[0]=0;
		for(int i=1;i!=N;i++)
		{
			if(tar[i]>res[i-1]+tar[i])
			{
				tem[i]=i;
				res[i]=tar[i];
			}
			else
			{
				tem[i]=tem[i-1];
				res[i]=res[i-1]+tar[i];
			}
		}
		int xmax=-9999,high,low;
		for(int i=0;i!=N;i++)
		{
			if(xmax<res[i])
			{
				xmax=res[i];
				high=i;
				low=tem[i];
			}
		}
		cout<<xmax<<" "<<++low<<" "<<++high<<endl;
		if(n!=0)
			cout<<endl;
	}
} 
