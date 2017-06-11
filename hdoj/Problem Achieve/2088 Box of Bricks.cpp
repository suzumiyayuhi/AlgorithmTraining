#include<iostream>
using namespace std;
int main()
{
	int n,sum,k=0;
	while(cin>>n,n)
	{
		if(k)
			cout<<endl;
		sum=0;
		int s[n],res=0;
		for(int i=0;i!=n;i++)
		{
			cin>>s[i];
			sum+=s[i];
		}
		sum/=n;
		for(int i=0;i!=n;i++)
		{
			int tem=sum-s[i];
			if(tem>0)
				res+=tem;
		}
		cout<<res<<endl;
		k++;
	}
} 
