#include<iostream>
using namespace std;

int main()
{
	int a;
	while(cin>>a)
	{
		if(a==0)
			cout<<1<<endl;
		else if(a<41)
		{
			int res=a;
			for(int i=1;i<a;++i) 
			{
				res*=i;
				res%=2009;
			}
			cout<<res<<endl;
		}
		else if(a>=41)
			cout<<0<<endl;
	}
}
