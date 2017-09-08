#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[101];

bool check(char str[])
{
	int tem=0,sz=0,sz1=0;
	bool flag=true;
	for(int i=0;i!=strlen(str);i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			sz1++;
			flag=false;
			tem*=10;
			tem+=str[i]-'0';
		}
		else if(str[i]=='.')
		{
			sz++;
			if(tem>255||flag||sz1>3)
				return false;
			flag=true;
			sz1=0;
			tem=0;
		}
		else
			return false;	
	}
	if(sz==3&&tem<=255)
		return true;
	return false;
}

int main()
{
	while(gets(str))
	{
		
		if(check(str))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}	
}
