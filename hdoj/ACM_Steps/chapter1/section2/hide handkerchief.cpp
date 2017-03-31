#include<iostream>
using namespace std;

bool IsRelativePrime(int a,int b)
{
	int tem=a%b;
	if(tem==1)
		return true;
	if(a%b!=0)
		IsRelativePrime(b,tem);	
	else if(a%b==0)
	{
		return false;
	}
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==-1&&b==-1)
			break;
		if(a%b==0)
			cout<<"POOR Haha"<<endl;
		else
		{
			if(IsRelativePrime(a,b))
				cout<<"YES"<<endl;
			else
				cout<<"POOR Haha"<<endl;
		}
	}
	return 0;
}
