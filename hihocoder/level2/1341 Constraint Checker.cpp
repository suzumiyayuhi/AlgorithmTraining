#include<iostream>
#include<stdio.h>
#include<map> 
using namespace std;
const int MAXN=300;
int n,t;
char cont[MAXN][MAXN];
map<char,int> repl;
int main()
{
	while(cin>>n)
	{
		repl.clear();
		int k=0;
		for(int i=0;i<n;i++)
		{
			cin>>cont[i];
			for(int j=0;cont[i][j];j++)
			{
				if(cont[i][j]>='A'&&cont[i][j]<='Z')
					repl[cont[i][j]]=0;
			}
		}
	
		cin>>t;
		while(t--)
		{
			for(int i=0;i<repl.size();i++)
			{
				char c;
				cin>>c;
				scanf("%d",&repl[c]);
			}
			
			
			int start=0,count=0;
			int x;
			char op;
			bool flag=false;
			for(int i=0;i<n;i++)
			{		
				for(x=0;cont[i][x];)
				{
					int aa=0,bb=0;
					while(cont[i][x]<='9'&&cont[i][x]>='0')
						aa=aa*10+cont[i][x++]-'0';
					if(cont[i][x]>='A'&&cont[i][x]<='Z')
						aa=repl[cont[i][x++]];
					if(cont[i][x]=='<')
					{
						int rec;
						if(cont[i][x+1]=='=')
						{
							op='=';
							x+=2;
							rec=x;
						}
						else
						{
							op='<';
							++x;
							rec=x;
						}
						if(cont[i][x]>='A'&&cont[i][x]<='Z')
							bb=repl[cont[i][x++]];
						while(cont[i][x]<='9'&&cont[i][x]>='0')
							bb=bb*10+cont[i][x++]-'0';
						if(op=='<')
						{
							if(aa>=bb)
							{
								cout<<"No"<<endl;
								flag=true;
								break;
							}
							count++;
						}
						else
						{
							if(aa>bb)
							{
								cout<<"No"<<endl;
								flag=true;
								break;
							}
							count++;
						}
						start++;
						x=rec;
					}
					if(flag)
						break;
				}
				if(flag)
					break;
			}

			if(!flag)
				cout<<"Yes"<<endl;	
		}
	}
} 
