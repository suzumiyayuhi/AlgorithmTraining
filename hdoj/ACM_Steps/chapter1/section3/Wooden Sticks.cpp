#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct tree
{
	int length;
	int weight;
	bool fl;	
};

bool comparetree(const tree &a,const tree &b)
{
	if(a.length!=b.length)
		return a.length<b.length;
	return a.weight<b.weight;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num;
		cin>>num;
		vector<tree> trees;
		int res=0;
		while(num--)
		{
			tree tem;
			cin>>tem.length>>tem.weight;
			tem.fl=true;
			trees.push_back(tem);
		}
		sort(trees.begin(),trees.end(),comparetree);
		
		int t;
		for(int i=0;i<trees.size();++i)
		{
			if(trees[i].fl==false)
				continue;
			t=trees[i].weight;
			trees[i].fl=true;
			for(int j=i+1;j<trees.size();++j)
			{
				if(t<=trees[j].weight&&trees[j].fl)
				{
					trees[j].fl=false;
					t=trees[j].weight;
				}
			}
			++res;
		}
		cout<<res<<endl;
	}
	return 0;
}
