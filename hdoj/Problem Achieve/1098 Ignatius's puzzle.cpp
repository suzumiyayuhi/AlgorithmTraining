#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int k;
	while(cin>>k)
	{
		int res=0;
		for(int a=1;a!=66;a++)
		{
			if(k*a%13==8&&k*a%5==2)
			{
				res=a;
				break;
			}
		}
		if(res)
			cout<<res<<endl;
		else
			cout<<"no"<<endl;
	}
}
