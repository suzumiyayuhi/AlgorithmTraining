#include<iostream>
using namespace std;
#define MAX 99999999999
long long res[5843];
int o[4]={2,3,5,7};
void table()
{
	int min;
	res[1]=1;
	for(int i=2;i!=5843;i++)
	{
		res[i]=MAX;
		for(int j=0;j!=4;j++)
		{
			for(int k=i-1;k!=0;k--)
			{
				if(res[k]*o[j]<=res[i-1])
					break;
				//else
				if(res[k]*o[j]<res[i])
					res[i]=res[k]*o[j];
			}
		}
		
		
	}
}

int main()
{
	table();
	int n;
	while(cin>>n,n)
	{
		int tem=n%10;
		int tem1=n%100;
		if(tem==1&&tem1!=11)
			cout<<"The "<<n<<"st humble number is "<<res[n]<<"."<<endl;
		else if(tem==2&&tem1!=12)
			cout<<"The "<<n<<"nd humble number is "<<res[n]<<"."<<endl;
		else if(tem==3&&tem1!=13)
			cout<<"The "<<n<<"rd humble number is "<<res[n]<<"."<<endl;
		else
			cout<<"The "<<n<<"th humble number is "<<res[n]<<"."<<endl;
	}
}
