#include<iostream>
using namespace std;
int main()
{
	int num,a,sum=0;
	while(cin>>num)
	{
		if(num==0)
			break;
		for(int i=0;i!=num;++i)
		{
			cin>>a;
			sum+=a;
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
