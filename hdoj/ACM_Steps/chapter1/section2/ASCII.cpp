#include<iostream>
using namespace std;
int main()
{
	int num;
	while(cin>>num)
	{
		char tar[num];
		for(int i=0;i!=num;++i)
		{
			int s;
			cin>>s;
			char c=s;
			tar[i]=c;
		}
		for(int i=0;i!=num;++i)
		{
			cout<<tar[i];
		}
	}
	return 0;
}
