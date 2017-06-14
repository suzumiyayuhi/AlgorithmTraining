#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
using namespace std;
int f[120000],v;
struct ri
{
	int p,w,n;
};

void ZeroOnePack(int cost,int weight)
{
    for(int i=v;i>=cost;i--)
       if(f[i-cost]+weight>f[i]) f[i]=f[i-cost]+weight;
}   
 
void CompletePack(int cost,int weight)
{
    for(int i=cost;i<=v;i++)
        if(f[i-cost]+weight>f[i]) f[i]=f[i-cost]+weight;
}  
       
void MultiplePack(int cost ,int weight,int amount)
{
    if(cost*amount>=v) CompletePack(cost,weight);
    else
    {
        for(int k=1;k<amount;)
        {
            ZeroOnePack(k*cost,k*weight);
            amount-=k;
            k<<=1;
        }    
        ZeroOnePack(amount*cost,amount*weight);
    }    
}    

int main()
{
	int x,sum=0;
	ri rice[101];
	cin>>x;
	while(x--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i!=m;i++)
		{
			cin>>rice[i].p>>rice[i].w>>rice[i].n;
			sum+=rice[i].p*rice[i].n;
		}
		memset(f,0,sizeof(f));
		v=sum/2;
		for(int i=0;i!=m;i++)
			MultiplePack(rice[i].p,rice[i].w,rice[i].n);
		cout<<f[n]<<endl;
	}
}
