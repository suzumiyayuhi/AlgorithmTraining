#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1000;
int dp[MAXN+10];//dp[i]表示以第i个数据结尾的符合要求的子列长度
int pre[MAXN+10];//记录i对应的上一个数据
int res[MAXN+10];//存放最终结果下标 

struct mouse
{
	int weight,speed,num;
};

bool cmp(const mouse &a,const mouse &b)
{
	if(a.weight<b.weight)  return 1;
    else if(a.weight==b.weight&&a.speed>b.speed)return 1;
    else return 0;
}

int main()
{
	vector<mouse> mice;
	mouse temmouse;
	int n=0;
	while(cin>>temmouse.weight>>temmouse.speed)
	{
		temmouse.num=++n;
		mice.push_back(temmouse);
	}
	sort(mice.begin(),mice.end(),cmp);
	
	int maxlen=0;
    int maxi,i,j;
    dp[1]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
            if(mice[i].weight>mice[j].weight&&mice[i].speed<mice[j].speed&&dp[j]+1>dp[i])
            {
                 dp[i]=dp[j]+1;
                 pre[i]=j;
                 if(dp[i]>maxlen)
                 {
                       maxi=i;
                       maxlen=dp[i];                      
                 }    
            }                 
    }
    int t=maxi;
    i=0;
    while(t!=0)
    {
        res[i++]=t;
        t=pre[t];
    } 
    cout<<i<<endl;
    while(i>0)
    {
        i--;
        cout<<mice[res[i]].num<<endl;
    }  
    return 0;             
}
