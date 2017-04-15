#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int gcd(int a,int b)
{
	if(a<b)
		swap(a,b);
	if(b==0)
		return a;
	else
		gcd(b,a%b);
}

int main()
{
	int num;
	cin>>num;
	while(num--)
	{
		bool flag=true;
		string str;
		int base1=0,base2=0;
		int weight1=1,weight2=1;
		cin>>str;
		for(int i=2;i!=str.size();++i)
		{
			if(str[i]=='(')
			{
				flag=false;
				continue;
			}
			if(str[i]!=')')
			{
				if(flag)
				{
					weight1*=10;
					base1=base1*10+str[i]-48;
				}
				weight2*=10;
				base2=base2*10+str[i]-48;
			}
		}
		if(flag)
			cout<<base1/gcd(base1,weight1)<<"/"<<weight1/gcd(base1,weight1)<<endl;
		else
		{
			int tem=gcd(base2-base1,weight2-weight1);
			cout<<(base2-base1)/tem<<"/"<<(weight2-weight1)/tem<<endl;
		} 
	}
}
