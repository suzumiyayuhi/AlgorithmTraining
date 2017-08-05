#include<iostream>
#include<string>
using namespace std;
int ct;
string str;

struct point
{
	int val,cnt;
	point():val(0),cnt(0){}
};

int sol(int index,point &p)
{
	int sum=0,i;
	for(i=index;i<str.size();)
	{
		if(str[i]=='(')
		{
			point p1,p2;
			i=sol(i+1,p1);
			i=sol(i+1,p2);
			if(p1.val>p2.val)
			{
				p.cnt+=2*p1.cnt+p2.cnt;
				p.val+=p1.val;
			}
			else
			{
				p.cnt+=2*p2.cnt+p1.cnt;
				p.val+=p2.val;
			}
			return sol(i+1,p);
		}
		else if(str[i]==')'||str[i]==',')
		{
			p.val+=sum;
			sum=0;
			return i;
		}
		else if(str[i]>='0'&&str[i]<='9')
		{
			sum=sum*10+str[i]-'0';
			i++;
		}
		else if(str[i]=='+')
		{
			p.val+=sum;
			sum=0;
			p.cnt++;
			return sol(i+1,p);
		}
		else
			i++;
	}
	if(sum)
		p.val+=sum;
	return i;
}

int main()
{
	cin>>ct;
	while(ct--)
	{
		cin>>str;
		point res;
		sol(0,res);
		cout<<res.val<<" "<<res.cnt<<endl;
	}
} 
