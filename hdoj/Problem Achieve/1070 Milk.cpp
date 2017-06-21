#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a,tem1,mini;
double minp;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		string names[n];
		double avg[n];
		int values[n];
		for(int i=0;i!=n;i++)
		{
			cin>>names[i]>>a>>values[i];
			tem1=values[i]/200;
			if(tem1>=5)
				tem1=5;
			else if(tem1==5)
			{
				avg[i]=99999999;
				continue;
			}
			avg[i]=1.0*tem1/values[i];
		}
		minp=avg[0];
		mini=0;
		for(int i=1;i<n;i++)
		{
			if(minp<avg[i])
				mini=i,minp=avg[i];
			else if(minp==avg[i]&&values[mini]<values[i])
				mini=i,minp=avg[i];
		}
		cout<<names[mini]<<endl;
	}
}
