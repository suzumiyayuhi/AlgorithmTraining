#include<iostream>
#include<string>
#include<algorithm>
#define MAX 1003
using namespace std;
int main()
{
	string a,b;
	int n;
	cin>>n;
	int x=0;
	while(n--)
	{
		cin>>a>>b;
		cout<<"Case "<<++x<<":"<<endl;
		cout<<a<<" + "<<b<<" = ";
		if(a.size()<b.size())
			swap(a,b);
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		char res[MAX];
		int tem=0,i;
		for(i=0;i!=b.size();++i)
		{
			tem+=a[i]-48+b[i]-48;
			res[i]=tem%10+48;
			tem/=10;
		}

		for(;i!=a.size();++i)
		{
			tem+=a[i]-48;
			res[i]=tem%10+48;
			tem/=10;
		}
		if(tem!=0)
		{
			res[i++]=tem+48;
		}
		while(1)
		{
			--i;
			if(res[i]=='0')
				continue;
			else
				break;
		}
		for(;i!=-1;--i)
			cout<<res[i];
		cout<<endl;
		if(n!=0)
			cout<<endl;
	}
}
