#include<iostream>
using namespace std;
int c[1024][1024];
int main()
{	
	string a,b;
	while(cin>>a>>b)
	{
		int len1=a.size(),len2=b.size();
		for(int i=0;i<=len1;i++)
			c[i][0]=0;
		for(int i=0;i<=len2;i++)
			c[0][i]=0;
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=len2;j++)
			{
				if(a[i-1]==b[j-1])
					c[i][j]=c[i-1][j-1]+1;
				else
					c[i][j]=max(c[i][j-1],c[i-1][j]);
			}
		}
		cout<<c[len1][len2]<<endl;
	}
	return 0;
} 
