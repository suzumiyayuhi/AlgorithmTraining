#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct people
{
    int cur;
};
int sol[14]={0};
void table()
{
	for(int x=1;x!=14;x++)
	{
		int num=x;
		int outman=0,n=num;
     	num*=2;
       	people peoples[num];
       	for(int i=0;i!=num;++i)
       	{
           	peoples[i].cur=i+1;
   		}
       	int m,f=0,t[num/2],j=0;
       	memset(t,100,sizeof(int)*n);
       	for(m=1;;)
       	{
           	int tem=(f+m-1)%(num-outman);
           	int c=0;
           	for(int i=0;i!=num/2;++i)
           	{
           		if(tem>=t[i])
           		{
           			c++;
				}
			}
           	if(peoples[tem+c].cur<=num/2)
           	{
           		memset(t,100,sizeof(int)*n);
               	outman=0;
               	c=0;
               	f=0;
               	j=0;
               	++m;
               	continue;
           	}
           	t[j]=tem;
           	++j;
           	f=tem;
           	++outman;
           	if(outman==num/2)
               	break;
       	}
       	sol[x]=m;
	}
}
int main()
{
	table();
    int num;
    while(cin>>num,num)
        cout<<sol[num]<<endl;
}

