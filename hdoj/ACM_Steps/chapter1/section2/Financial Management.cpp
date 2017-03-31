#include<iostream>
using namespace std;
int main()
{
	double sum=0,a;
	for(int i=0;i!=12;++i)
	{
		cin>>a;
		sum+=a;
	}
	sum=sum/12;
	cout<<"$"<<sum<<endl;
	return 0;
}
