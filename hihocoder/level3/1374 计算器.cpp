#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
using namespace std;
int len;
char str[100];

int sol(int start)
{
	stack<int> s1;
	stack<char> s2;
	int i=start,tem;
	for(;i<len;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			tem=0;
			while(str[i]>='0'&&str[i]<='9')
			{
				tem=tem*10+str[i]-'0';
				i++;
			}
			s1.push(tem);
		}
		if(str[i]=='+'||str[i]=='-')
		{
			if(!s2.empty())
			{
				int right=s1.top();
				s1.pop();
				int left=s1.top();
				s1.pop();
				char c=s2.top();
				s2.pop();
				if(c=='+')
				{
					tem=left+right;
					s1.push(tem);
				}
				else
				{
					tem=left-right;
					s1.push(tem);
				}
				s2.push(str[i]);
			}
			else
				s2.push(str[i]);	
		}
	}
	if(!s2.empty())
	{
		int right=s1.top();
		s1.pop();
		int left=s1.top();
		s1.pop();
		int c=s2.top();
		s2.pop();
		if(c=='+')
		{
			tem=left+right;
			s1.push(tem);
		}
		else
		{
			tem=left-right;
			s1.push(tem);
		}
	}
	return s1.top();
}

int main()
{
	while(gets(str))
	{
		if(str[0]=='E'&&str[1]=='N'&&str[2]=='D')
			break;
		len=strlen(str);
		cout<<sol(0)<<endl;
	}
}
