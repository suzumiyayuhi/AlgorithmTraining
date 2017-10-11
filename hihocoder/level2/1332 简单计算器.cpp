#include<cstring>
#include<cstdio>
#include<stack>
using namespace std; 
char str[101];
int len,newstart;

int sol(int start)
{
	stack<int> s1;
	stack<char> s2;
	int left,right,tem=0,i=start;
	char c;
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
				right=s1.top();
				s1.pop();
				left=s1.top();
				s1.pop();
				c=s2.top();
				s2.pop();
				if(c=='+')
					tem=left+right;
				else if(c=='-')
					tem=left-right;
				s1.push(tem);
				s2.push(str[i]);
			}
			else
				s2.push(str[i]);
		}
		else if(str[i]=='('||str[i]==')')
		{
			if(str[i]=='(')
			{
				tem=sol(++i);
				s1.push(tem);
			}
			else
			{
				if(!s2.empty())
				{
					right=s1.top();
					s1.pop();
					left=s1.top();
					s1.pop();
					c=s2.top();
					s2.pop();
					if(c=='+')
						tem=left+right;
					else if(c=='-')
						tem=left-right;				
					s1.push(tem);
				}
				newstart=i;
				return s1.top();
			}
			i=newstart;
		}
		
	}
	if(!s2.empty())
	{
		right=s1.top();
		s1.pop();
		left=s1.top();
		s1.pop();
		c=s2.top();
		s2.pop();
		if(c=='+')
			tem=left+right;
		else if(c=='-')
			tem=left-right;
		
		s1.push(tem);
	}
	else
		s1.push(str[i]);
	return s1.top();
}

int main()
{
	gets(str);
	len=strlen(str);
	printf("%d\n",sol(0));
}
