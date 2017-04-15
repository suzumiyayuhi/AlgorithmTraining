#include<iostream>
#include<cmath>
using  namespace std;
int main()
{
	int num;
	cin>>num;
	while(num--)
	{
		int res,tar;
		double tem,tem1;
		cin>>tar;
		if(tar==2)
		{
			cout<<4;
			continue;
		}
		tem=tar*log10(tar);
		tem1=tem-floor(tem);
		res=pow(10.0,tem1);
		cout<<res<<endl;
	}
	return 0;
}
