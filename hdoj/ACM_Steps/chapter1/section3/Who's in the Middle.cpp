#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	while(cin>>num)
	{
		vector<int> cows;
		int tem;
		for(int i=0;i!=num;++i)
		{
			cin>>tem;
			cows.push_back(tem);
		}
		sort(cows.begin(),cows.end());
		cout<<cows[cows.size()/2]<<endl;
	}
	return 0;
}
