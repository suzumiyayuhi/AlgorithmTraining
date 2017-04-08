#include<iostream>
#include<algorithm> 
#include<cstdio>
using namespace std;
int main()
{
	int num;
	while(cin>>num,num)
	{
		int C[num],J[num],point1=0,point2=0;
		for(int i=0;i!=num;++i)
		{
			cin>>C[i];
		}
		for(int i=0;i!=num;++i)
		{
			cin>>J[i];
		}
		sort(C,C+num);
		sort(J,J+num);
		
		for(int i=0;i!=num;++i)
		{
			if(C[i]>J[i])
				point1+=2;
			else if(C[i]==J[i])
				{
				point1++;
				point2++;
				}
			else
				point2+=2;
		}
		printf("%d vs %d\n",point1,point2);//vs Сд... 
	}
}
