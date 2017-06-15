#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
const int MAXN=40;  
int main()  
{  
    int T;  
    int a[MAXN];  
    scanf("%d",&T);  
    for(int k=1;k<=T;k++)  
        { 
        memset(a,0,sizeof(a));  
        int L,S1,S2;  
        scanf("%d%d%d",&L,&S1,&S2);  
        long long int pos,dis=0;
        int sum,h;
        do
        {  
            dis++;  
            pos=L+dis;  
            sum=0;  
            h=0;  
            while(pos)  
            {  
                if(pos&1)  
                {  
                    a[h]=1;  
                    sum++;  
                }else a[h]=0;  
                h++;  
                pos>>=1;  
            }  
            if(sum<S1)  
            {  
                int add=S1-sum;  
                int j=0;  
                while(add)  
                {  
                    if(a[j]==0)  
                    {  
                        a[j]=1;  
                        add--;  
                    }  
                    j++;  
                }  
                break;  
            }  
        }while(sum<S1||sum>S2);  
        long long int ans=0,temp=1;   
        for(int i=0;i<MAXN;i++)  
        {  
            if(a[i])  
                ans+=temp;  
            temp<<=1;  
        }  
        printf("Case #%d: %lld\n",k,ans);  
    }  
    return 0;  
}
