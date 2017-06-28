#include<cstdio>
#include<iostream>
using namespace std;
int tab[10][4]={0,0,0,0,
				1,1,1,1,
				2,4,8,6,
				3,9,7,1,
				4,6,4,6,
				5,5,5,5,
				6,6,6,6,
				7,9,3,1,
				8,4,2,6,
				9,1,9,1};
int main()
{
	int n,c,res;
	while(cin>>n>>c)
	{
		n%=10;
		c%=4;
		if(c!=0)
			res=tab[n][c-1];
		else
			res=tab[n][3];
		printf("%d\n",res);
	}
}
