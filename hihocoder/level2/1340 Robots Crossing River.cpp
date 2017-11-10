#include<iostream>
#include<algorithm>
using namespace std;
int num[3];
int xcount;

int cmp(const int &a,const int &b)
{
	return a>b;	
}

int main()
{
	while(cin>>num[0]>>num[1]>>num[2])
	{
		xcount=0;
		while(num[0]+num[1]+num[2])
		{
			sort(num,num+3,cmp);
			if(num[0]<=num[1]+num[2])
			{
				xcount+=(num[0]+num[1]+num[2])/20;
				if((num[0]+num[1]+num[2])%20)
					xcount++;
				break;
			}
			else
			{
				while(num[0]>=10&&num[1]>=10)
				{
					num[0]-=10;
					num[1]-=10;
					sort(num,num+3,cmp);
					xcount++;
				}
				if(num[0]>=10)
				{
					if(num[1]+num[2]>=10)
					{
						if(num[1]+num[2]>=10)
						{
							num[0]-=10;
							num[2]=0;
							num[1]-=10-num[2];
							xcount++;
						}
						else if(num[1]+num[2]>=8)
						{
							num[0]-=num[1]+num[2];
							num[1]=0;
							num[2]=0;
							xcount++;
						}
					}
				}
				xcount+=(num[0]+num[1]+num[2])/15;
				if(num[0]+num[1]+num[2]%15)
					xcount++;
				break;
			}
		}
		cout<<xcount*6<<endl;
	}
}
