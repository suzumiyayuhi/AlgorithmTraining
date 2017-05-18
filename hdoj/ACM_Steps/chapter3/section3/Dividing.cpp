#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
using namespace std;
int f[120005],v;

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
	int items[7],cn=0;
	while(1)
	{
		int sum=0;
		for(int i=1;i!=7;i++)
		{
			cin>>items[i];
			sum+=items[i]*i;
		}
		if(sum==0)
			break;
		cout<<"Collection #"<<++cn<<":"<<endl;
		if(sum%2==1)
		{
			cout<<"Can't be divided."<<endl<<endl;
			continue;
		}
		else
		{
			v=sum/2;
			memset(f,0,sizeof(f));
			for(int i=1;i!=7;i++)
				MultiplePack(i,i,items[i]);
			if(f[v]==v)
				cout<<"Can be divided."<<endl<<endl;
			else
				cout<<"Can't be divided."<<endl<<endl;
		}
	}
} 
