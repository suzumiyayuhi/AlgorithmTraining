#include<iostream>
#include<string>
using namespace std;
int main()
{
	int L,N;
	while(cin>>L>>N)
	{
		string dic[L*2],words[N];
		for(int i=0;i!=2*L;i++)
			cin>>dic[i];
		for(int i=0;i!=N;i++)
		{
			bool flag=false;
			cin>>words[i];
			string tem=words[i];
			for(int j=0;j!=2*L;j+=2)
			{
				if(tem==dic[j])
					words[i]=dic[j+1],flag=true;
			}
			if(!flag)
			{
				if(tem[tem.size()-1]=='y'&&tem[tem.size()-2]!='a'&&tem[tem.size()-2]!='e'&&tem[tem.size()-2]!='i'
						&&tem[tem.size()-2]!='o'&&tem[tem.size()-2]!='u')
					tem.replace(tem.end()-1,tem.end(),"ies");
				else if(tem[tem.size()-1]=='o'||tem[tem.size()-1]=='s'||
						(tem[tem.size()-2]=='s'||tem[tem.size()-2]=='c')&&tem[tem.size()-1]=='h'
						||tem[tem.size()-1]=='x')
					tem+="es";
				else
					tem+="s";
				words[i]=tem;
			}
		}
		for(int i=0;i!=N;i++)
			cout<<words[i]<<endl;
	}
} 
