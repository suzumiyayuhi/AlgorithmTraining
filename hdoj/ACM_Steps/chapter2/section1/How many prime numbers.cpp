#include<iostream>
#include<math.h>
using namespace std;

int CalRes(int counter)
{
	int tar[counter],res=counter;
	for(int i=0;i!=counter;++i)
	{
		cin>>tar[i];
	}
	for(int i=0;i!=counter;++i)
	{
		if(tar[i]==2||tar[i]==3)
		{
			--res;
			continue;
		}
		else if(tar[i]<2)
		{
			--res;
			continue;
		}
		int tem=sqrt(tar[i]);
		for(int j=2;j<=tem;++j)
		{
			if(tar[i]%j==0)
			{
				--res;
				break;
			}
		}
	}
	return res;
}

int main()
{
	int counter;
	while(cin>>counter)
	{
		cout<<CalRes(counter)<<endl; 
	}
	return 0;
}
