#include<iostream>
using namespace std;
int main()
{
	int counter=0,number;
	while(cin>>number)
	{
		if(number==0)
			break;		
		int tar[number],res=0,sum=0;
		for(int i=0;i!=number;++i)
		{
			cin>>tar[i];
			sum+=tar[i];
		}
		int avg=sum/number;
		for(int i=0;i!=number;++i)
		{
			while(tar[i]>avg)
			{
				--tar[i];
				++res;
			}
		}
		cout<<"Set #"<<++counter<<endl;
		cout<<"The minimum number of moves is "<<res<<"."<<endl<<endl;
	}
	return 0;
} 

