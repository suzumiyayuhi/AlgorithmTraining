#include<iostream>
using namespace std;
int main()
{
	int number;
	while(cin>>number)
	{
		if(number==0)
			break;
		int cur=0,prev,res=0;
		for(int i=0;i!=number;++i)
		{
			cin>>prev;
			int da=prev-cur;
			if(da>0)
			{
				res+=da*6;
			}
			else if(da<0)
			{
				res+=da*(-1)*4;
			}
			cur=prev;
			res+=5;
		}
		cout<<res<<endl;
	}
	return 0;
} 
