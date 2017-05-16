#include<iostream>
#include<algorithm>
using namespace std;
int palace[21][1001];
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int row,line;
		cin>>row>>line;
		for(int i=0;i<=row;i++) 
			palace[i][0]=-1000;
      	for(int i=0;i<=line;i++)
	 		palace[0][i]=-1000;
    	palace[1][0]=palace[0][1]=0;
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=line;j++)
			{
				cin>>palace[i][j];
			}
		}
		
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=line;j++)
			{
				int xmax=-1000;
				for(int k=1;k!=j;k++)
					if(j%k==0)
						xmax=max(xmax,palace[i][k]);
				xmax=max(xmax,palace[i-1][j]);
				palace[i][j]+=max(xmax,palace[i][j-1]);
			}
		}
		
		cout<<palace[row][line]<<endl; 
	}
} 
