#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int t,x,y,n,d;
map<int,vector<int> > m;

int sol()
{
	int res=0,d2=d*d;
	for(map<int,vector<int> >::iterator it=m.begin();it!=m.end();it++)
	{
		sort(it->second.begin(),it->second.end());
		for(int i=0,j=0,n=it->second.size();i<n;i++)
		{
			for(;j<n&&it->second[i]+d>it->second[j];j++);
			res+=j-i-1;
		}
	}
	for(map<int,vector<int> >::iterator it=m.begin();it!=m.end();it++)
	{
		for(vector<int>::iterator it_vec=it->second.begin();it_vec!=it->second.end();it_vec++)
		{
			for(int i=1,t=d;i<d;++i)
			{
				while(i*i+t*t>=d2)
					t--;
				map<int,vector<int> >::iterator tar=m.find(it->first+i);
				if(tar!=m.end())
				{
					res+=(upper_bound(tar->second.begin(),tar->second.end(),*it_vec+t)-tar->second.begin())-
						(lower_bound(tar->second.begin(),tar->second.end(),*it_vec-t)-tar->second.begin());
				}
			}
		}
	}
	return res;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=0;i!=n;i++)
		{
			cin>>x>>y;
			m[x].push_back(y);
		}
		cout<<sol()<<endl;
	}
	return 0;
}
