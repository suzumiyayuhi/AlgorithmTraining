#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	int N;
	map<string,size_t> colors;
	while(cin>>N,N)
	{
		int res=0;
		string temcolor;
		for(int i=0;i!=N;i++)
		{
			cin>>temcolor;
			++colors[temcolor];
		}
		for(map<string,size_t>::iterator X=colors.begin();X!=colors.end();X++)
		{
			if(X->second>=res)
			{
				res=X->second;
				temcolor=X->first;
			}
		}
		cout<<temcolor<<endl;
		colors.clear();
	}
}
