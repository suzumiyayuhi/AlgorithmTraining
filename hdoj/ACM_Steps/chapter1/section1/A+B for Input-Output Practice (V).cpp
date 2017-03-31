#include<iostream>
using namespace std;
int main()
{
	int counter1,counter2,a,sum=0;
	cin>>counter1;
	for(int i=0;i!=counter1;++i)
	{
		cin>>counter2;
		for(int j=0;j!=counter2;++j)
		{
			cin>>a;
			sum+=a;
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
