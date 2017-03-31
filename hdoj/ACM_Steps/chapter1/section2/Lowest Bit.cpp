#include<iostream>
using namespace std;
int main()
{
	int num,s=1;
	while(cin>>num)
	{
		if(num==0)
			break;
		while(1)
		{
				if(num%s!=0)
			{
				cout<<num%s<<endl;
				s=1;
				break; 
			}
				else
					s*=2;
		} 
	}
	return 0;
}
