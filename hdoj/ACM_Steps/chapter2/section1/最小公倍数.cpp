#include<iostream>
using namespace std;

int CalRes(int a,int b)
{
	int tem1=a,tem2=b;
	while(a%b!=0)
	{
		b=a%b;
		a=tem2;
	}
	return tem1*tem2/b;
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a>b)
			cout<<CalRes(a,b)<<endl;
		else
			cout<<CalRes(b,a)<<endl;
	}
	return 0;
} 
