#include <iostream>
#include <cstdio>
using namespace std;
int n,M;
struct matrax
{
    int m[4][4];
};
matrax A={
  1,0,1,1,
  1,0,0,0,
  0,1,0,0,
  0,0,1,0
};
matrax E;
void init()
{
   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
     E.m[i][j]=(i==j);
}
matrax multi(matrax a,matrax b)
{
    matrax c;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            c.m[i][j]=0;
            for(int k=0;k<4;k++)
                c.m[i][j]+=a.m[i][k]*b.m[k][j]%M;
        c.m[i][j]%=M;
        }
    }
    return c;
}
matrax power(matrax A,int k)
{
    matrax ans=E,p=A;
    while(k){
        if(k&1){
            ans=multi(ans,p);
            k--;
        }
        k>>=1;
        p=multi(p,p);
    }
    return ans;
}
int main()
{
    init();
    int a[4]={1,2,4,6};
    while(cin>>n>>M){
        matrax ans=power(A,n-3);
        int x=0;
        for(int i=0;i<4;i++)
            x+=(ans.m[0][i]*a[4-i-1])%M;
        /*for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                cout<<ans.m[i][j]<<" ";
            cout<<endl;
        }*/
        cout<<x%M<<endl;
    }
    return 0;
}
